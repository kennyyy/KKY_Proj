#pragma once
#include "KWindow.h"

class KCore : public KWindow
{
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Realease();
private:
	virtual bool EngineInit();
	virtual bool EngineFrame();
	virtual bool EngineRender();
	virtual bool EngineRealease();
public:
	bool Run();
public:
	KCore() {};
	virtual ~KCore() {}
};

