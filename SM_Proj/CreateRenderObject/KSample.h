#pragma once
#include "KCore.h"
#include "KPlaneObj.h"
#include "KNpcObj.h"
#include "KPlayer.h"


class KSample : public KCore{

	KShaderMgr m_shaderMgr;
	KTextureMgr m_textureMgr;
	KObject* m_pMapObj = nullptr;
	KObject* m_pPlayer = nullptr;

	std::vector<KObject*> m_ObjList;
	ID3D11BlendState* m_AlphaBlend = nullptr;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

