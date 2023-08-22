#pragma once
#include"KDxObject.h"


class KObject :public KDxObject
{
public:
	bool      m_bDead = false;
public:
	Vector3 m_vPosition;
	Vector3 m_vScale;
	Vector3 m_vRotation;
	Matrix  m_mtxWorld;
	Matrix  m_mtxView;
	Matrix  m_mtxProj;
	Rect m_rt;

public:
	void SetPosition(Vector3 p);
	void SetScale(Vector3 s);
	void SetSRT( Vector3 vScale, Vector3 vRotation, Vector3 vTranslation);
	void SetMatrix(Matrix* mtxWorld, Matrix* mtxView, Matrix* mtxProj);
	virtual void    SetRect(Vector2& p, float w, float h);
	virtual void  SetDirection(Vector3 d) {};
	
public:
	virtual bool Create(KTextureMgr& texMgr, std::wstring texFilename, KShaderMgr& shaderMgr, std::wstring shaderFilename);
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	virtual void  Move(float fSecond) {};

public:
	KObject() {};
	virtual ~KObject() {};
};

