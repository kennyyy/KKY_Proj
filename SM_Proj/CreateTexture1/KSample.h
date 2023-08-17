#pragma once
#include "KCore.h"
#include "KObject.h"


class KSample : public KCore{

	KShaderMgr m_shaderMgr;
	KTextureMgr m_textureMgr;

	std::vector<KObject*> m_ObjList;
	ID3D11BlendState* m_AlphaBlend = nullptr;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

