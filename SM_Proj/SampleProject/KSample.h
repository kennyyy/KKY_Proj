#pragma once
#include "KCore.h"
#include "KPlaneObj.h"
//#include "KNpcObj.h"
//#include "KPlayer.h"

float g_fMapSizeX = 800.0f;
float g_fMapSizeY = 600.0f;

class KSample : public KCore{
	KDXWrite* m_pWrite = nullptr;
	KDXWrite* m_pWrite2 = nullptr;
	KObject* m_pMapObj = nullptr;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

