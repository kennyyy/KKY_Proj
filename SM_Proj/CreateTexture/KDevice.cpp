#include "KDevice.h"
HRESULT hr;

HRESULT KDevice::CreateDevice() {
    HRESULT hr;
    D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
    UINT Flags = 0;
    D3D_FEATURE_LEVEL pFeatureLevels = D3D_FEATURE_LEVEL_11_0;

    hr = D3D11CreateDevice(
        NULL,
        DriverType,
        NULL,
        Flags,
        &pFeatureLevels,
        1,
        D3D11_SDK_VERSION,
        &m_pDevice,
        &m_FeatureLevel,
        &m_pImmediateContext);
    if (FAILED(hr)) {
        return S_FALSE;
    }
    return S_OK;
}

HRESULT KDevice::CreateGIFactory() {
    HRESULT hr;
    hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pGIFacotry);
    if (FAILED(hr)) {
        return S_FALSE;
    }
    return S_OK;

}

HRESULT KDevice::CreateSwapChain() {
    HRESULT hr = S_OK;
    if (m_pGIFacotry == NULL) return S_FALSE;
    DXGI_SWAP_CHAIN_DESC SwapChainDesc;
    ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
    SwapChainDesc.BufferDesc.Width = 800;
    SwapChainDesc.BufferDesc.Height = 600;
    SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    SwapChainDesc.SampleDesc.Count = 1;
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.OutputWindow = m_hWnd;
    SwapChainDesc.Windowed = true;
   
    hr = m_pGIFacotry->CreateSwapChain(
        m_pDevice,
        &SwapChainDesc,
        &m_pSwapChain);

    if (FAILED(hr)) {
        return S_FALSE;
    }
    return S_OK;
}

HRESULT KDevice::SetRenderTargetView() {
    ID3D11Texture2D* pBackBuffer;
    hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (SUCCEEDED(hr))
    {

        hr = m_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRenderTargetView);
        if (FAILED(hr))
        {
            pBackBuffer->Release();
            return S_FALSE;
        }
        m_pImmediateContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);
    }
    pBackBuffer->Release();
    return S_OK;
}
HRESULT KDevice::SetViewPort() {
    HRESULT hr = S_OK;
    D3D11_VIEWPORT pViewport;
    pViewport.Width = 800;
    pViewport.Height = 600;
    pViewport.MinDepth = 0.0f;
    pViewport.MaxDepth = 1.0f;
    pViewport.TopLeftX = 0;
    pViewport.TopLeftY = 0;

    m_pImmediateContext->RSSetViewports(
        1,
        &pViewport );
    return S_OK;
}
bool KDevice::Init() {
    if (FAILED(CreateDevice())) return false;
    if (FAILED(CreateGIFactory())) return false;
    if (FAILED(CreateSwapChain())) return false;
    if (FAILED(SetRenderTargetView())) return false;
    if (FAILED(SetViewPort())) return false;

    return true;
}
bool KDevice::Frame() {
    return true;
}
bool  KDevice::PreRender()
{
    float color[4] = { 1,1,0.64333f,1 };
    m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, color);
    return true;
}
bool  KDevice::PostRender()
{
    HRESULT hr = m_pSwapChain->Present(0, 0);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}
bool  KDevice::Render()
{
    PreRender();
    PostRender();
    return true;
}
bool KDevice::Release() {
    if (m_pSwapChain)m_pSwapChain->Release();
    if (m_pDevice)m_pDevice->Release();
    if (m_pGIFacotry)m_pGIFacotry->Release();
    if (m_pImmediateContext)m_pImmediateContext->Release();
    if (m_pRenderTargetView)m_pRenderTargetView->Release();
  
    return true;
}

