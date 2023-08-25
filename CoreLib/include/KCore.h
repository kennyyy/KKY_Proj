#pragma once
#include "KDevice.h"
#include "KCamera.h"
#include "KInput.h"
#include "KTimer.h"
#include "KShaderMgr.h"
#include "KTextureMgr.h"
#include "KDXWrite.h"

class KCore : public KDevice
{
public:
    KTimer m_GameTimer;
    KCamera m_MainCamera;
public:
    virtual bool  Init();
    virtual bool  Frame();
    virtual bool  Render();
    virtual bool  Release();
private:
    virtual bool  EngineInit();
    virtual bool  EngineFrame();
    virtual bool  EngineRender();
    virtual bool  EngineRelease();
public:
    bool  Run();

};

