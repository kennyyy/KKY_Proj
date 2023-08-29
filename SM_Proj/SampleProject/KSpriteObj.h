#pragma once
#include "KPlaneObj.h"

struct SpriteInfo {
	float iAniTickTime;
	int iNumRow;
	int iNumColumn;
	Vector3 pos;
	Vector3 scale;
	T_STR texFileName;
	T_STR texAlphaFileName;
	T_STR shaderFIleName;
	T_STR_VECTOR texList;

};
class KSpriteObj : public KPlaneObj
{
public:
	const KTexture* m_pAlphaTex = nullptr;
	float m_fAniFullTimer = 1.0f;
	float m_fOffsetTime = 0.0f;
	float m_fElapsedTimer = 0.0f;
	int m_iCurrentAniIndex = 0;
	int m_iNumSpriteX = 1;
	int m_iNumSpriteY = 1;
	SpriteInfo m_InitSpriteInfo;
public:
	virtual int GetMaxSize() { return 1; };
	virtual void SetUVFrame(int iNumRow, int iNumColumn) {  };
	virtual bool Render() override;
	virtual bool Load(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext, SpriteInfo);
	virtual bool LoadTexArray(T_STR_VECTOR& texList) { return true; };

};

class KSpriteTexture : public KSpriteObj {
public:
	std::vector<const KTexture*> m_pTexList;
public:
	virtual int GetMaxSize() override;
	virtual bool LoadTexArray(T_STR_VECTOR& texList) override;
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;
public:
	KSpriteTexture();
	virtual ~KSpriteTexture();

};

class KSpriteUV : public KSpriteObj {
	std::vector<UVRect> m_pUVTexList;
public:
	void SetUVFrame(int iNumRow, int iNumColumn) override;
	void SetNumSprite(int x, int y);
public:
	virtual int GetMaxSize() override;
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;
public:
	KSpriteUV();
	virtual ~KSpriteUV();
};

