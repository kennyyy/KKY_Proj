#pragma once
#include "KStd.h"
#include "KTextureMgr.h"
#include "KShaderMgr.h"

struct P_Vertex {
	float x, y, z;
	float u, v;
};

class KObject 
{
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11Buffer* m_pIndexBuffer = nullptr;
	ID3D11InputLayout* m_pVertexLayout = nullptr;

	const KShader* m_pShader = nullptr;
	const KTexture* m_pTex = nullptr;

	std::vector<P_Vertex> m_VertexList;



public:
	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
	bool CreateVertexBuffer();
	bool CreateIndexBuffer();
	bool  LoadVertexShader();
	bool  LoadPixelShader();
	bool  CreateInputLayout();
	bool LoadTextureFile(std::wstring filename);

public:
	bool Init(KTextureMgr& texMgr, std::wstring texFilename, KShaderMgr& shaderMgr, std::wstring shaderFilename);
	bool Frame();
	bool Render();
	bool Release();
};

