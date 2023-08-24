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
    
    srand(time(NULL));
    m_pMapObj = new KPlaneObj;
    m_pMapObj->Set(m_pDevice, m_pImmediateContext);
    m_pMapObj->SetPosition({ 0.0f, 0.0f, 0.0f });
    m_pMapObj->SetScale(Vector3(g_fMapSizeX, g_fMapSizeY, 1.0f));
    m_pMapObj->Create(m_textureMgr, textname[0], m_shaderMgr, L"Plane.hlsl");

    m_pPlayer = new KPlayer;
    m_pPlayer->Set(m_pDevice, m_pImmediateContext);
    m_pPlayer->SetPosition({ 0.0f, 0.0f, 0.0f });
    m_pPlayer->SetScale(Vector3(30.0f, 30.0f, 1.0f));
    Vector2 rt_pos = { m_pPlayer->m_vPosition.x ,m_pPlayer->m_vPosition.y };
    m_pPlayer->SetRect(rt_pos, m_pPlayer->m_vScale.x * 2.0f, m_pPlayer->m_vScale.y * 2.0f);
    m_pPlayer->Create(m_textureMgr, textname[1], m_shaderMgr, L"Plane.hlsl");


    m_MainCamera.Create(m_pPlayer->m_vPosition,
        { (float)m_dwWindowWidth, (float)m_dwWindowHeight });

    for (int i = 0; i < 5; i++) {
        KObject* pNpcObj = new KNpcObj;
        pNpcObj->Set(m_pDevice, m_pImmediateContext);
        pNpcObj->SetPosition(Vector3(randstep(-g_fMapSizeX, +g_fMapSizeX),
            randstep(-g_fMapSizeY, +g_fMapSizeY), 0));
        pNpcObj->SetScale(Vector3(50.0f, 50.0f, 1.0f));
        pNpcObj->SetDirection({ randstep(-1, +1), randstep(-1, +1), 0 });
        Vector2 rt_pos = { pNpcObj->m_vPosition.x ,pNpcObj->m_vPosition.y };
        pNpcObj->SetRect(rt_pos, pNpcObj->m_vScale.x * 2.0f, pNpcObj->m_vScale.y * 2.0f);
        pNpcObj->Create(m_textureMgr ,textname[i%4], m_shaderMgr, L"Plane.hlsl");
        m_ObjList.push_back(pNpcObj);
    }


    return true;
}
bool  KSample::Frame()
{
    m_pPlayer->Frame();
    m_pMapObj->Frame();
    for (auto obj : m_ObjList) {
        if (obj->m_bDead == false) {
            if (g_fGameTimer > 10.0f) {
                obj->SetDirection({ m_pPlayer->m_vPosition.x - obj->m_vPosition.x,m_pPlayer->m_vPosition.y - obj->m_vPosition.y , 0 });
            }
            srand(time(NULL));
            if (fmodf(g_fGameTimer, 2.0f) < 0.001f) {
                obj->SetDirection({ randstep(-1, +1), randstep(-1, +1), 0 });
            }
            obj->Move(g_fSecondPerFrame);
            obj->Frame();
        }
   
     
    }
    for (auto obj : m_ObjList) {
        if (m_pPlayer->m_rt.ToRect(obj->m_rt))
        {
            obj->m_bDead = true;
        }
    }
    return true;
}
bool  KSample::Render()
{
    m_pImmediateContext->OMSetBlendState(m_AlphaBlend, 0, -1);

    m_MainCamera.m_vCameraPos = m_pPlayer->m_vPosition;
    m_pMapObj->SetMatrix(nullptr, &m_MainCamera.m_mtxView, &m_MainCamera.m_mtxOrthoProjection);
    m_pMapObj->Render();
    for (auto obj : m_ObjList) {
        if (obj->m_bDead == false)
        {
            obj->SetMatrix(nullptr, &m_MainCamera.m_mtxView, &m_MainCamera.m_mtxOrthoProjection);
            obj->Render();
        }
    }
    m_pPlayer->SetMatrix(nullptr, &m_MainCamera.m_mtxView,
        &m_MainCamera.m_mtxOrthoProjection);
    m_pPlayer->Render();
    return true;
}
bool  KSample::Release()
{
    m_pMapObj->Release();
    delete m_pMapObj;
    m_pMapObj = nullptr;
    m_pPlayer->Release();
    delete m_pPlayer;
    m_pPlayer = nullptr;
    for (auto obj : m_ObjList) {
        obj->Release();
        delete obj;
    }
    m_ObjList.clear();
    m_AlphaBlend->Release();
    return true;
}

KGAME(L"kgca", 800, 600)