#pragma once
#include "KCore.h"

struct P_Vertex {
	float x;
	float y;
	float z;
};

class KSample  : public KCore
{
public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11InputLayout* m_pVertexLayout = nullptr;
	ID3DBlob* m_VertexShaderCode = nullptr;
	ID3D11VertexShader* m_pVS = nullptr;
	ID3D11PixelShader* m_pPS = nullptr;

	bool CreateVertexBuffer();
	//HRESULT		LoadShaderAndInputLayout();
	bool  LoadVertexShader();
	bool  LoadPixelShader();
	bool  CreateInputLayout();

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

