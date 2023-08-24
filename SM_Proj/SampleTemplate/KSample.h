#pragma once
#include "KCore.h"
#include "KPlaneObj.h"
#include "KDXWrite.h"
//#include "KNpcObj.h"
//#include "KPlayer.h"


float g_fMapSizeX = 800.0f;
float g_fMapSizeY = 600.0f;

class KSample : public KCore{
	KObject* m_pMapObj = nullptr;
	KDXWrite m_font;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

