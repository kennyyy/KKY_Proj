#include "KShaderMgr.h"

void  KShader::Apply(ID3D11DeviceContext* pImmediateContext)  const {
    pImmediateContext->VSSetShader(m_pVS, NULL, 0);
    pImmediateContext->PSSetShader(m_pPS, NULL, 0);
}
bool KShader::LoadVertexShader(ID3D11Device* pDevice, std::wstring filename) {
    ID3DBlob* ErrorCode;
    HRESULT hr = D3DCompileFromFile(
        filename.c_str(),
        nullptr,
        nullptr,
        "VS",
        "vs_5_0",
        0,
        0,
        &m_VertexShaderCode,
        &ErrorCode);
    if (FAILED(hr))
    {
        //ErrorCode
        TCHAR pMessage[500];
        mbstowcs(pMessage, (CHAR*)ErrorCode->GetBufferPointer(), 500);
        MessageBox(NULL, pMessage, L"ERROR", MB_OK);
        if (ErrorCode) ErrorCode->Release();
        return false;
    }
    hr = pDevice->CreateVertexShader(
        m_VertexShaderCode->GetBufferPointer(),
        m_VertexShaderCode->GetBufferSize(),
        nullptr,
        &m_pVS);

    if (ErrorCode) ErrorCode->Release();
    return true;

}
bool KShader::LoadPixelShader(ID3D11Device* pDevice, std::wstring filename) {
    ID3DBlob* ErrorCode;
    ID3DBlob* m_PixelShaderCode;
    HRESULT hr = D3DCompileFromFile(
        filename.c_str(),
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        &m_PixelShaderCode,
        &ErrorCode);
    if (FAILED(hr))
    {
        //ErrorCode
    }
    hr = pDevice->CreatePixelShader(
        m_PixelShaderCode->GetBufferPointer(),
        m_PixelShaderCode->GetBufferSize(),
        nullptr,
        &m_pPS);

    if (m_PixelShaderCode) m_PixelShaderCode->Release();
    if (ErrorCode) ErrorCode->Release();
    return true;

}
bool KShader::LoadShader(ID3D11Device* pDevice, std::wstring filename) {
    if (!LoadVertexShader(pDevice, filename)) return false;
    if (!LoadPixelShader(pDevice, filename)) return false;
   
    return true;
}
bool KShader::Release() {
    if (m_pVS) m_pVS->Release();
    if (m_pPS) m_pPS->Release();
    if (m_VertexShaderCode) m_VertexShaderCode->Release();
    m_pVS = nullptr;
    m_pPS = nullptr;
    m_VertexShaderCode = nullptr;
    return true;

}



void KShaderMgr::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext) {
    m_pDevice = pDevice;
    m_plmmediateContext = pImmediateContext;
}

const KShader* KShaderMgr::Load(std::wstring szFilepath) {
    size_t splitPath = szFilepath.find_last_of(L"/");
    std::wstring path = szFilepath.substr(0, splitPath+1);
    std::wstring name = szFilepath.substr(splitPath + 1);

    const KShader* data = GetPtr(name);
    if (data != nullptr) {
        return data;
    }
    KShader* newData = new KShader;
    if (newData->LoadShader(m_pDevice, szFilepath)) {
        m_list.insert(std::make_pair(name, newData));
        return newData;
    }
    delete newData;
    return nullptr;
}

const KShader* KShaderMgr::GetPtr(std::wstring key) {
    auto iter = m_list.find(key);
    if (iter == m_list.end()) {
        return nullptr;
    }
    return iter->second;

}

bool  KShaderMgr::Get(std::wstring key, KShader& ret) {
    auto iter = m_list.find(key);
    if (iter == m_list.end()) {
        return false;
    }
    ret = *(iter->second);
    return true;
}

KShaderMgr::~KShaderMgr() {
    for (auto& data : m_list) {
        data.second->Release();
        delete data.second;
    }
}

