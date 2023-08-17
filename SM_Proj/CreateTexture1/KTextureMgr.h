#pragma once
#include "KStd.h"
class KTexture {
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;
public:
	std::wstring m_csName;
	std::wstring m_csPath;

	void  Apply(ID3D11DeviceContext* pImmediateContext, int iSlot) const;
	bool  LoadTexture(ID3D11Device* pDevice, std::wstring filename);
	bool  Release();
};


class KTextureMgr
{
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_plmmediateContext = nullptr;
	using List = std::map<std::wstring, KTexture*>;
public:
	List m_list;

	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);

	const KTexture* Load(std::wstring szFilepath);
	const KTexture* GetPtr(std::wstring key);
	bool Get(std::wstring key, KTexture& ret);

public:
	KTextureMgr() {}
	virtual ~KTextureMgr();
};

