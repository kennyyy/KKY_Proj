#include "KDxObject.h"


void KDxObject::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext) {
    m_pDevice = pDevice;
    m_pImmediateContext = pImmediateContext;
}

bool KDxObject::CreateConstantBuffer() {
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

bool  KDxObject::CreateVertexBuffer(){
    return true;
}
bool KDxObject::CreateIndexBuffer() {
    return true;
}

bool  KDxObject::CreateInputLayout()
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
bool  KDxObject::Init()
{
    return true;
}
bool  KDxObject::Frame()
{
    return true;
}
bool KDxObject::PreRender() {
    m_pImmediateContext->VSSetConstantBuffers(0, 1, &m_pConstantBuffer);
    m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_pImmediateContext->IASetInputLayout(m_pVertexLayout);
    UINT stride = sizeof(P_Vertex);
    UINT offset = 0;
    m_pImmediateContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
    m_pImmediateContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
    m_pTex->Apply(m_pImmediateContext, 0);
    m_pShader->Apply(m_pImmediateContext);
    return true;
}
bool  KDxObject::Render()
{
    PreRender();
    PostRender();
    return true;
}
bool KDxObject::PostRender() {
    m_pImmediateContext->DrawIndexed(6, 0, 0);
    // m_pImmediateContext->Draw(6, 0);
    return true;
}
bool  KDxObject::Release()
{
    if (m_pConstantBuffer) m_pConstantBuffer->Release();
    if (m_pVertexBuffer) m_pVertexBuffer->Release();
    if (m_pIndexBuffer)m_pIndexBuffer->Release();
    if (m_pVertexLayout) m_pVertexLayout->Release();
    return true;
}
