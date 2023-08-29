#include "KSpriteObj.h"
bool KSpriteObj::Load(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext, SpriteInfo sInfo) {
	m_InitSpriteInfo = sInfo;
	Set(pDevice, pImmediateContext);
	SetScale(sInfo.scale);
	SetPosition(sInfo.pos);
	if (!sInfo.texAlphaFileName.empty()) {
		m_pAlphaTex = I_Texture.Load(sInfo.texAlphaFileName);
	}
	LoadTexArray(sInfo.texList);
	//SetUVFrame(sInfo.iNumRow, sInfo.iNumColumn);
	Create(sInfo.texFileName, sInfo.shaderFIleName);
	return true;
}
bool KSpriteObj::Render() {
	PreRender();
	if (m_pAlphaTex) {
		m_pAlphaTex->Apply(m_pImmediateContext, 1);
	}
	PostRender();
	return true;
}

int KSpriteTexture::GetMaxSize()  {
	return (int)m_pTexList.size();
};
 bool KSpriteTexture::LoadTexArray(T_STR_VECTOR& texList) {
	 for (auto& texName : texList) {
		 const KTexture* pTex = I_Texture.Load(texName);
		 m_pTexList.push_back(pTex);
	 }
	 m_fOffsetTime = m_InitSpriteInfo.iAniTickTime / m_pTexList.size();
	return true; 
};
 bool  KSpriteTexture::Init() {
	 KPlaneObj::Init();
	 return true;
}
 bool KSpriteTexture::Frame() {
	 KPlaneObj::Frame();
	 m_fElapsedTimer += g_fSecondPerFrame;
	 if (m_pTexList[m_iCurrentAniIndex] != nullptr) {
		 if (m_fElapsedTimer >= m_fOffsetTime) {
			 m_iCurrentAniIndex++;
			 if (m_iCurrentAniIndex == m_pTexList.size()) {
				 m_iCurrentAniIndex = 0;
			 }
			 m_fElapsedTimer = 0.0f;
		 }
	 }
	 return true;
}
 bool  KSpriteTexture::Render() {
	 PreRender();
	 if (m_pTexList[m_iCurrentAniIndex]) {
		 m_pTexList[m_iCurrentAniIndex]->Apply(m_pImmediateContext, 0);
	 }
	 PostRender();
	 return true;
}
 bool KSpriteTexture::Release() {
	 KPlaneObj::Release();
	 return true;
}

KSpriteTexture::KSpriteTexture() {
	Init();
}
KSpriteTexture::~KSpriteTexture() {
	Release();
}

void KSpriteUV::SetUVFrame(int iNumRow, int iNumColumn) {
	UVRect uvRt;
	Vector2 uv;
	float fOffsetX = 1.0f/ iNumColumn;
	float fOffsetY = 1.0f/ iNumRow;
	for (int row = 0; row < iNumRow; row++) {
		uv.y = fOffsetY * row;
		for (int column = 0; column < iNumColumn; column++) {
			uv.x = fOffsetX * column;
			uvRt.m_Min = uv;
			uvRt.m_Max.x = uv.x + fOffsetX;
			uvRt.m_Max.y = uv.y + fOffsetY;
			m_pUVTexList.push_back(uvRt);
		}
	}
	m_fOffsetTime = m_fAniFullTimer / m_pUVTexList.size();
}

void KSpriteUV::SetNumSprite(int x, int y) {
	m_iNumSpriteX = 1;
	m_iNumSpriteY = 1;
}

int KSpriteUV::GetMaxSize() {
	return m_pUVTexList.size();
}
bool KSpriteUV::Init() {
	KPlaneObj::Init();
	return true;
}
bool KSpriteUV::Frame() {
	KPlaneObj::Frame();
	m_fElapsedTimer += g_fSecondPerFrame;
		if (m_fElapsedTimer >= m_fOffsetTime) {
			m_iCurrentAniIndex++;
			if (m_iCurrentAniIndex == m_pUVTexList.size()) {
				m_iCurrentAniIndex = 0;
			}
			m_fElapsedTimer = 0.0f;
		}

	return true;
}
bool KSpriteUV::Render() {
	return true;
}
bool KSpriteUV::Release() {
	KPlaneObj::Release();
	return true;
}
	
KSpriteUV::KSpriteUV() {
}
KSpriteUV::~KSpriteUV(){

}

