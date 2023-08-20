#include "KObject.h"


void KObject::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext) {
    m_pDevice = pDevice;
    m_pImmediateContext = pImmediateContext;
}
void  KObject::SetPosition(Vector3 p) {
    m_vPosition = p;
}
void KObject::SetSRT(Vector3 vScale, Vector3 vRotation, Vector3 vTranslation) {
    m_vScale = vScale;
    m_vRotation = vRotation;
    m_vPosition = vTranslation;
}
void KObject::SetMatrix(Matrix* mtxWorld, Matrix* mtxView, Matrix* mtxProj) {
    if (mtxWorld != nullptr) {
        m_mtxWorld = *mtxWorld;
    }
    if (mtxView != nullptr) {
        m_mtxView = *mtxView;
    }
    if (mtxProj != nullptr) {
        m_mtxProj = *mtxProj;
    }
    m_cbData.mtxWorld = m_mtxWorld.Transpose();
    m_cbData.mtxView = m_mtxView.Transpose();
    m_cbData.mtxProj = m_mtxProj.Transpose();
    m_pImmediateContext->UpdateSubresource(
        m_pConstantBuffer,
        0,
        nullptr,
        &m_cbData,
        0,
        0
    );
}
bool KObject::CreateConstantBuffer(){
    D3D11_BUFFER_DESC cbDesc;
    ZeroMemory(&cbDesc, sizeof(cbDesc));
    cbDesc.ByteWidth = sizeof(CB_Data);
    cbDesc.Usage = D3D11_USAGE_DEFAULT;
    cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
;
    HRESULT hr = m_pDevice->CreateBuffer(&cbDesc, nullptr, &m_pConstantBuffer);
    if (FAILED(hr)) {
        return false;
    }

    return true;

}

bool  KObject::CreateVertexBuffer()
{
    /* m_VertexList.resize(6);
   m_VertexList[0].u = 0.0f;   m_VertexList[0].v = 0.0f;
   m_VertexList[1].u = 1.0f;   m_VertexList[1].v = 0.0f;
   m_VertexList[2].u = 0.0f;   m_VertexList[2].v = 1.0f;
   m_VertexList[3].u = 0.0f;   m_VertexList[3].v = 1.0f;
   m_VertexList[4].u = 1.0f;   m_VertexList[4].v = 0.0f;
   m_VertexList[5].u = 1.0f;   m_VertexList[5].v = 1.0f;
   float x = randstep(-1.0f, +1.0f);
   float y = randstep(-1.0f, +1.0f);

   m_VertexList[0].x = x; m_VertexList[0].y = y;  m_VertexList[0].z = 0.5f;
   m_VertexList[1].x = x + 0.5f; m_VertexList[1].y = y;  m_VertexList[1].z = 0.5f;
   m_VertexList[2].x = x; m_VertexList[2].y = y - 0.5f;  m_VertexList[2].z = 0.5f;
   m_VertexList[3] = m_VertexList[2];
   m_VertexList[4] = m_VertexList[1];
   m_VertexList[5].x = x + 0.5f; m_VertexList[5].y = y - 0.5f; m_VertexList[5].z = 0.5f;*/

   /* P_Vertex vList[3];
    vList[0].x = -1.0f; vList[0].y = 1.0f; vList[0].z = 0.5f;
    vList[1].x = 1.0f; vList[1].y = 1.0f; vList[1].z = 0.5f;
    vList[2].x = -1.0f; vList[2].y = -1.0f; vList[2].z = 0.5f;*/
    return true;
}
bool KObject::CreateIndexBuffer() {
    WORD indices[] =
    {
        0,1,2,
        2,1,3,
    };

    UINT iNumIndex = sizeof(indices) / sizeof(indices[0]);

    D3D11_BUFFER_DESC ibDesc;
    ibDesc.ByteWidth = iNumIndex * sizeof(WORD);
    ibDesc.Usage = D3D11_USAGE_DEFAULT;
    ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibDesc.CPUAccessFlags = 0;
    ibDesc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA ibInitData;
    ZeroMemory(&ibInitData, sizeof(D3D11_SUBRESOURCE_DATA));
    ibInitData.pSysMem = indices;
    HRESULT hr = m_pDevice->CreateBuffer(&ibDesc, &ibInitData, &m_pIndexBuffer);
    if (FAILED(hr)) {
        return false;
    }

    return true;

}

bool  KObject::CreateInputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        {"TEXTURE",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0,}
    };
    UINT iNumCount = sizeof(layout) / sizeof(layout[0]);
    HRESULT hr = m_pDevice->CreateInputLayout(
        layout,
        iNumCount,
        m_pShader->m_VertexShaderCode->GetBufferPointer(),
        m_pShader->m_VertexShaderCode->GetBufferSize(),
        &m_pVertexLayout);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}
bool  KObject::Init(KTextureMgr& texMgr, std::wstring texFilename, KShaderMgr& shaderMgr, std::wstring shaderFilename)
{
    CreateConstantBuffer();
    CreateVertexBuffer();
    CreateIndexBuffer();
    m_pShader = shaderMgr.Load(shaderFilename);
    CreateInputLayout();
    m_pTex = texMgr.Load(texFilename);
    return true;
}
bool  KObject::Frame()
{
    return true;
}
bool  KObject::Render()
{
    m_pImmediateContext->VSSetConstantBuffers(0, 1, &m_pConstantBuffer);
    m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_pImmediateContext->IASetInputLayout(m_pVertexLayout);
    UINT stride = sizeof(P_Vertex);
    UINT offset = 0;
    m_pImmediateContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
    m_pImmediateContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
    m_pTex->Apply(m_pImmediateContext, 0);
    m_pShader->Apply(m_pImmediateContext);
    m_pImmediateContext->DrawIndexed(6, 0, 0);
   // m_pImmediateContext->Draw(6, 0);
    return true;
}
bool  KObject::Release()
{
    if (m_pConstantBuffer) m_pConstantBuffer->Release();
    if (m_pVertexBuffer) m_pVertexBuffer->Release();
    if (m_pIndexBuffer)m_pIndexBuffer->Release();
    if (m_pVertexLayout) m_pVertexLayout->Release();
    return true;
}
