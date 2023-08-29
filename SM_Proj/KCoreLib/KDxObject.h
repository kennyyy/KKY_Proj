#pragma once
#include"kstd.h"
#include"KTextureMgr.h"
#include"KShaderMgr.h"

struct P_Vertex {
	Vector3 p;
	Vector2 t;
};

struct CB_Data {
	Matrix  mtxWorld;
	Matrix  mtxView;
	Matrix  mtxProj;
};

class KDxObject
{
public:
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;

public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11Buffer* m_pIndexBuffer = nullptr;
	ID3D11Buffer* m_pConstantBuffer = nullptr;
	ID3D11InputLayout* m_pVertexLayout = nullptr;
	const KShader* m_pShader = nullptr;
	const KTexture* m_pTex = nullptr;

	CB_Data m_cbData;
	std::vector<P_Vertex> m_VertexList;

public:
	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
public:
	virtual bool CreateVertexBuffer();
	virtual bool CreateIndexBuffer();
	virtual bool CreateConstantBuffer();
	virtual bool CreateInputLayout();
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool PreRender();
	virtual bool Render();
	virtual bool PostRender();
	virtual bool Release();
public:
	virtual ~KDxObject() {};
};

