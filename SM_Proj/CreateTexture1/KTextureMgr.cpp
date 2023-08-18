#include "KTextureMgr.h"

void  KTexture::Apply(ID3D11DeviceContext* pImmediateContext, int iSlot)  const{
    pImmediateContext->PSSetShaderResources(iSlot, 1, &m_pTextureSRV);
}
bool  KTexture::LoadTexture(ID3D11Device* pDevice, std::wstring filename) {

   /*HRESULT hr;

    hr = DirectX::CreateWICTextureFromFile(pDevice, filename.c_str(), nullptr, &m_pTextureSRV);
    if (FAILED(hr)) {
        hr = DirectX::CreateDDSTextureFromFile(pDevice, filename.c_str(), nullptr, &m_pTextureSRV);
        if (FAILED(hr))
        {
            return false;
        }
    }
    return true;*/

    //더 다양한 텍스처 파일 로딩
    auto imageobj = std::make_unique<DirectX::ScratchImage>();
    DirectX::TexMetadata mdata;

    HRESULT hr = DirectX::GetMetadataFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromWICFile(filename.c_str(), DirectX::WIC_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(filename.c_str(), DirectX::WIC_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromTGAFile(filename.c_str(), DirectX::TGA_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(filename.c_str(), DirectX::TGA_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    return false;
}
bool  KTexture::Release() {
    if (m_pTextureSRV) m_pTextureSRV->Release();
    m_pTextureSRV = nullptr;
    return true;
}




void KTextureMgr::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext) {
    m_pDevice = pDevice;
    m_plmmediateContext = pImmediateContext;
}

const KTexture* KTextureMgr::Load(std::wstring szFilepath) {
    size_t splitpath = szFilepath.find_last_of(L"/");
    std::wstring path = szFilepath.substr(0, splitpath + 1);
    std::wstring name = szFilepath.substr(splitpath + 1);

    const KTexture* data = GetPtr(name);
    if (data != nullptr) {
        return data;
    }
    KTexture* newData = new KTexture;
    if (newData->LoadTexture(m_pDevice, szFilepath)) {
        m_list.insert(std::make_pair(name, newData));
        return newData;
    }
    delete newData;
    return nullptr;
}
const KTexture* KTextureMgr::GetPtr(std::wstring key) {
    auto iter = m_list.find(key);
    if (iter == m_list.end()) {
        return nullptr;
    }
    return iter->second;
}
bool KTextureMgr::Get(std::wstring key, KTexture& ret) {
    auto iter = m_list.find(key);
    if (iter == m_list.end()) {
        return false;
    }

    ret = *(iter->second);
    return true;
}

KTextureMgr::~KTextureMgr() {
    for (auto& data : m_list) {
        data.second->Release();
        delete data.second;
    }
    m_list.clear();
 }