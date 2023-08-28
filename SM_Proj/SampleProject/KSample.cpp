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

    m_pWrite = new KDXWrite;
    m_pWrite->Set(m_pSwapChain);
    m_pWrite->Create(L"°íµñ", 100, L"ko-kr");

    //left , top, right, bottom
    m_pWrite->AddText(L"dd",0.0f, 0.0f , 400.0f, 300.0f,{ 0.0f, 0.0f, 0.0f, 1.0f });
    
    m_pWrite2 = new KDXWrite;
    m_pWrite2->Set(m_pSwapChain);
    m_pWrite2->Create(L"°íµñ", 50, L"ko-kr");
    m_pWrite2->AddText(L"±è°æ¿¬", 400.0f, 0, 800.0f, 300.0f,{ 0.0f, 0.0f, 0.0f, 1.0f });
    m_pWrite2->AddText(L"±è°æ¿¬", 600.0f,0, 800.0f, 300.0f, { 0.0f, 0.0f, 0.0f, 1.0f });



    m_pBGS =I_Sound.LoadSound(L"../../data/sound/MyLove.mp3");
    m_pBGS->VolumeSet(0.5f);
    m_pBGS->Play();

    m_pEffectS= I_Sound.LoadSound(L"../../data/sound/Gun1.wav");
    m_pEffectS->PlayEffect();
    return true;
}
bool  KSample::Frame()
{
    I_Sound.Frame();
    if (I_Input.m_dwKeyState[VK_LBUTTON]
        == KEY_PUSH)
    {
        m_pEffectS->PlayEffect();
    }
    if (I_Input.m_dwKeyState[VK_RBUTTON]
        == KEY_PUSH)
    {
        m_pBGS->Stop();
    }
    if (I_Input.m_dwKeyState[VK_HOME]
        == KEY_PUSH)
    {
        m_pBGS->Paused();
    }
    if (I_Input.m_dwKeyState[VK_LEFT]
        == KEY_HOLD)
    {
        m_pBGS->VolumeDown();
    }
    if (I_Input.m_dwKeyState[VK_RIGHT]
        == KEY_HOLD)
    {
        m_pBGS->VolumeUp();
    }
    m_pMapObj->Frame();
    m_pWrite->Frame();
    m_pWrite2->Frame();
    return true;
}
bool  KSample::Render()
{
    
    m_pMapObj->SetMatrix(nullptr, &m_MainCamera.m_mtxView, &m_MainCamera.m_mtxOrthoProjection);
    m_pMapObj->Render();
    m_pWrite->Render();
    m_pWrite2->Render();

    return true;
}
bool  KSample::Release()
{
    m_pWrite->Release();
    m_pWrite2->Release();

    m_pMapObj->Release();
    delete m_pMapObj;
    m_pMapObj = nullptr;
    return true;
}

KGAME(L"kgca", 800, 600)