#pragma once
#include "KStd.h"
#include "KTextureMgr.h"
#include "KShaderMgr.h"

struct P_Vertex {
	Vector3 p;
	Vector2 t;
};

struct CB_Data {
	Matrix  mtxWorld;
	Matrix  mtxView;
	Matrix  mtxProj;
};

class KObject 
{
public:
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;

	Vector3 m_vPosition;
	Vector3 m_vScale;
	Vector3 m_vRotation;
	Matrix  m_mtxWorld;
	Matrix  m_mtxView;
	Matrix  m_mtxProj;
	CB_Data m_cbData;

public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11Buffer* m_pIndexBuffer = nullptr;
	ID3D11Buffer* m_pConstantBuffer = nullptr;
	ID3D11InputLayout* m_pVertexLayout = nullptr;

	const KShader* m_pShader = nullptr;
	const KTexture* m_pTex = nullptr;
	std::vector<P_Vertex> m_VertexList;

public:
	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
	void SetPosition(Vector3 p);
	void SetSRT( Vector3 vScale, Vector3 vRotation, Vector3 vTranslation);
	void SetMatrix(Matrix* mtxWorld, Matrix* mtxView, Matrix* mtxProj);
public:
	virtual bool CreateVertexBuffer();
	virtual bool CreateIndexBuffer();
	virtual bool CreateConstantBuffer();
	virtual bool CreateInputLayout();
	
public:
	virtual bool Init(KTextureMgr& texMgr, std::wstring texFilename, KShaderMgr& shaderMgr, std::wstring shaderFilename);
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
public:
	KObject() {};
	virtual ~KObject() {}
};

