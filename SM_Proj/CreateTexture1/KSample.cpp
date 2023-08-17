#include "KSample.h"


bool  KSample::Init()
{
    D3D11_BLEND_DESC bdc;
    ZeroMemory(&bdc, sizeof(bdc));
    bdc.RenderTarget[0].BlendEnable = true;
    bdc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    bdc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bdc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

    bdc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    bdc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    bdc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

    bdc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    m_pDevice->CreateBlendState(&bdc, &m_AlphaBlend);


    m_shaderMgr.Set(m_pDevice, m_pImmediateContext);
    m_textureMgr.Set(m_pDevice, m_pImmediateContext);
    std::wstring textname[] = { L"../../res/kgcabk.bmp", L"../../res/ade4.dds" , L"../../res/mapcontrol.png",  L"../../res/103.tga" };
   /* for (int i = 0; i < 100; i++) {
        KObject* pObj = new KObject;
        pObj->Set(m_pDevice, m_pImmediateContext);
        pObj->Init(textname[0]);
        m_ObjList.push_back(pObj);
    }*/
 
        KObject* pObj = new KObject;
        pObj->Set(m_pDevice, m_pImmediateContext);
        pObj->Init(m_textureMgr ,textname[1], m_shaderMgr, L"Plane.hlsl");
        m_ObjList.push_back(pObj);
        KObject* pObj1 = new KObject;
        pObj1->Set(m_pDevice, m_pImmediateContext);
        pObj1->Init(m_textureMgr, textname[2], m_shaderMgr, L"Plane.hlsl");
        m_ObjList.push_back(pObj1);

    return true;
}
bool  KSample::Frame()
{
    for (auto obj : m_ObjList) {
        obj->Frame();
    }
    return true;
}
bool  KSample::Render()
{
    m_pImmediateContext->OMSetBlendState(m_AlphaBlend, 0, -1);
    for (auto obj : m_ObjList) {
        obj->Render();
    }
    return true;
}
bool  KSample::Release()
{
    for (auto obj : m_ObjList) {
        obj->Release();
        delete obj;
    }
    m_ObjList.clear();
    m_AlphaBlend->Release();
    return true;
}

KGAME(L"kgca", 800, 600)