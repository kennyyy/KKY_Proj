#pragma once
#include "KCore.h"
#include "KPlaneObj.h"
//#include "KNpcObj.h"
//#include "KPlayer.h"
float g_fMapSizeX = 1000.0f;
float g_fMapSizeY = 1000.0f;

class KSample : public KCore{
	KObject* m_pMapObj = nullptr;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

