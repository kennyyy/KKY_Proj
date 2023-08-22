#include "KObject.h"
void KObject::SetRect(Vector2& p, float w, float h) {
    m_rt.Set(p, w, h);
}

void  KObject::SetPosition(Vector3 p) {
    m_vPosition = p;
}
void KObject::SetScale(Vector3 s) {
    m_vScale = s;
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

bool KObject::Create(KTextureMgr& texMgr, std::wstring texFilename, KShaderMgr& shaderMgr, std::wstring shaderFilename) {
    CreateConstantBuffer();
    CreateVertexBuffer();
    CreateIndexBuffer();
    m_pShader = shaderMgr.Load(shaderFilename);
    CreateInputLayout();
    m_pTex = texMgr.Load(texFilename);
    return true;
}

bool  KObject::Init()
{ 
    KDxObject::Init();
    return true;
}
bool  KObject::Frame()
{
    KDxObject::Frame();
    return true;
}
bool  KObject::Render()
{
    KDxObject::Render();
    return true;
}
bool  KObject::Release()
{
    KDxObject::Release();
    return true;
}
