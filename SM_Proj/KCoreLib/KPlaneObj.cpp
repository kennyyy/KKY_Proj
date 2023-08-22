#include "KPlaneObj.h"
bool KPlaneObj::CreateVertexBuffer() {
    m_VertexList.resize(4);
    m_VertexList[0].t.x = 0.0f;   m_VertexList[0].t.y = 0.0f;
    m_VertexList[1].t.x = 1.0f;   m_VertexList[1].t.y = 0.0f;
    m_VertexList[2].t.x = 0.0f;   m_VertexList[2].t.y = 1.0f;
    m_VertexList[3].t.x = 1.0f;   m_VertexList[3].t.y = 1.0f;

    m_VertexList[0].p.x = -1.0f; m_VertexList[0].p.y = 1.0f;  m_VertexList[0].p.z = 0.0f;
    m_VertexList[1].p.x = 1.0f; m_VertexList[1].p.y = 1.0f;  m_VertexList[1].p.z = 0.0f;
    m_VertexList[2].p.x = -1.0f; m_VertexList[2].p.y = -1.0f;  m_VertexList[2].p.z = 0.0f;
    m_VertexList[3].p.x = 1.0f; m_VertexList[3].p.y = -1.0f; m_VertexList[3].p.z = 0.0f;


    D3D11_BUFFER_DESC Desc;
    ZeroMemory(&Desc, sizeof(Desc));
    Desc.ByteWidth = sizeof(P_Vertex) * m_VertexList.size();
    Desc.Usage = D3D11_USAGE_DEFAULT;
    Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    CD3D11_BUFFER_DESC cbc(sizeof(P_Vertex) * m_VertexList.size(), D3D11_BIND_VERTEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitialData;
    ZeroMemory(&InitialData, sizeof(InitialData));
    InitialData.pSysMem = &m_VertexList.at(0);

    HRESULT hr = m_pDevice->CreateBuffer(
        &cbc,
        &InitialData,
        &m_pVertexBuffer);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}

bool KPlaneObj::CreateIndexBuffer() {
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
bool KPlaneObj::Frame() {
 
    Matrix mtxScale, mtxRotation, mtxTranslate;
    mtxScale.Scale(m_vScale);
    mtxRotation.ZRotate(m_vRotation.z);
    mtxTranslate.Translation(m_vPosition);

    m_mtxWorld = mtxScale * mtxRotation * mtxTranslate;
    return true;
}