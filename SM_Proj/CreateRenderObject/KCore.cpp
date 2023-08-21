#include "KCore.h"


bool  KCore::Init() { return true; }
bool  KCore::Frame() { return true; }
bool  KCore::Render() { return true; }
bool  KCore::Release() { return true; }
bool  KCore::EngineInit()
{
    KDevice::Init();
    m_GameTimer.Init();
    KInput::GetInstance().Init();
    m_MainCamera.Init();
    Init();
    return true;
}
bool  KCore::EngineFrame()
{
    m_GameTimer.Frame();
    KInput::GetInstance().Frame();
    m_MainCamera.Frame();
    KDevice::Frame();
    Frame();
    return true;
}
bool  KCore::EngineRender()
{
   
    KDevice::PreRender();
    Render();
    m_MainCamera.Render();
    m_GameTimer.Render();
    KInput::GetInstance().Render();
    KDevice::PostRender();
    return true;
}
bool  KCore::EngineRelease()
{
    m_GameTimer.Release();
    m_MainCamera.Release();
    KInput::GetInstance().Release();
    Release();
    KDevice::Release();
    return true;
}

bool KCore::Run() {
    EngineInit();
    MSG msg = { 0 };
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 게임로직을 처리
            if (!EngineFrame() || !EngineRender())
            {
                break;
            }
        }
    }
    EngineRelease();
	return true;
}
