#pragma once
#include "KStd.h"

class KCamera
{
public:
	Matrix m_mtxView;
	Matrix m_mtxOrthoProjection;
	Vector3 m_vCameraPos;
	DWORD m_dwWindowWidth;
	DWORD m_dwWindowHeight;
public:
	bool Create(Vector3 vCamPos, Vector2 CamSize);
public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
};

