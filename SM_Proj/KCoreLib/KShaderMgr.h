#pragma once
#include "KStd.h"

class KShader {
	ID3D11VertexShader* m_pVS = nullptr;
	ID3D11PixelShader* m_pPS = nullptr;
public:
	std::wstring m_csName;
	std::wstring m_csPath;
	ID3DBlob* m_VertexShaderCode = nullptr;

	void  Apply(ID3D11DeviceContext* pImmediateContext) const;
	bool  LoadVertexShader(ID3D11Device* pDevice, std::wstring filename);
	bool  LoadPixelShader(ID3D11Device* pDevice, std::wstring filename);
	bool  LoadShader(ID3D11Device* pDevice, std::wstring filename);
	bool  Release();
};


class KShaderMgr
{
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_plmmediateContext = nullptr;
	using List = std::map<std::wstring, KShader*>;
public:
	static KShaderMgr& GetInstance() {
		static KShaderMgr sdmgr;
		return sdmgr;
	}
public:
	List m_list;

	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);

	const KShader* Load(std::wstring szFilepath);
	const KShader* GetPtr(std::wstring key);
	bool Get(std::wstring key, KShader& ret);

private:
	KShaderMgr() {}
public:
	virtual ~KShaderMgr();
};

#define I_Shader KShaderMgr::GetInstance()