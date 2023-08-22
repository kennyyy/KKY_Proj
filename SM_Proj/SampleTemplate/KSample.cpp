#include "KSample.h"


bool  KSample::Init()
{


    std::wstring textname[] = { L"../../res/kgcabk.bmp", L"../../res/ade4.dds" , L"../../res/mapcontrol.png",  L"../../res/103.tga" };
    
    srand(time(NULL));
    m_pMapObj = new KPlaneObj;
    m_pMapObj->Set(m_pDevice, m_pImmediateContext);
    m_pMapObj->SetPosition({ 0.0f, 0.0f, 0.0f });
    m_pMapObj->SetScale(Vector3(m_dwWindowWidth/2.0f, m_dwWindowHeight/2.0f, 1.0f));
    m_pMapObj->Create( textname[0], L"../../res/shader/Plane.hlsl");


    m_MainCamera.Create({0,0,0},
        { (float)m_dwWindowWidth, (float)m_dwWindowHeight });
   

    return true;
}
bool  KSample::Frame()
{
    m_pMapObj->Frame();
    return true;
}
bool  KSample::Render()
{
    m_pMapObj->SetMatrix(nullptr, &m_MainCamera.m_mtxView, &m_MainCamera.m_mtxOrthoProjection);
    m_pMapObj->Render();
    return true;
}
bool  KSample::Release()
{
    m_pMapObj->Release();
    delete m_pMapObj;
    m_pMapObj = nullptr;
    return true;
}

KGAME(L"kgca", 800, 600)