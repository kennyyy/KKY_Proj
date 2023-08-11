#pragma once
#include "KCore.h"

struct P_Vertex {
	float x, y, z;
	float u, v;
};

class KSample  : public KCore
{
public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11InputLayout* m_pVertexLayout = nullptr;
	ID3DBlob* m_VertexShaderCode = nullptr;
	ID3DBlob* m_PixelShaderCode = nullptr;
	ID3D11VertexShader* m_pVS = nullptr;
	ID3D11PixelShader* m_pPS = nullptr;

	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;
	std::vector<P_Vertex> m_VertexList;


public:
	void Set();
	bool CreateVertexBuffer();
	bool  LoadVertexShader();
	bool  LoadPixelShader();
	bool  CreateInputLayout();
	bool LoadTextureFile(std::wstring filename);

public:
	bool Init(std::wstring texFilename);
	bool Frame();
	bool Render();
	bool Release();
};

