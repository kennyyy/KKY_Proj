#include "KCore.h"


bool  KCore::Init() { return true; }
bool  KCore::Frame() { return true; }
bool  KCore::Render() { return true; }
bool  KCore::Release() { return true; }
bool  KCore::EngineInit()
{
    KDevice::Init();
    Init();
    return true;
}
bool  KCore::EngineFrame()
{
    KDevice::Frame();
    Frame();
    return true;
}
bool  KCore::EngineRender()
{
    KDevice::PreRender();
    Render();
    KDevice::PostRender();
    return true;
}
bool  KCore::EngineRelease()
{
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
