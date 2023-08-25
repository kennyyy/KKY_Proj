#include "KDXWrite.h"
#include "KStd.h"

bool KDXWrite::Set(IDXGISwapChain* pSwapChain) {
    m_pSwapChain = pSwapChain;
    //IDXGISurface1* pSurface1;// pBackBuffer

    HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface1), (LPVOID*)&m_pSurface1);

    if (SUCCEEDED(hr)) {
        return true;
    }
    return false;
}

bool KDXWrite::Create(std::wstring fontName, INT foneSize, std::wstring localeName) {
    CreateFactoryAndCreateTextFormat(fontName, foneSize, localeName);
    if (CreateDeviceResources(m_pSurface1)) {
        if (m_pSurface1) m_pSurface1->Release();
        return true;
    }
    if (m_pSurface1) m_pSurface1->Release();
    return false;
}

void KDXWrite::AddText(std::wstring text, float x, float y, float width, float height, D2D1::ColorF color ) {
    TextData textdata;
    textdata.text = text;
    textdata.layoutRt = { x, y,width,
       height };
    textdata.color = color;
    m_TextList.push_back(textdata);
   
}
bool KDXWrite::CreateFactoryAndCreateTextFormat(std::wstring fontName, INT foneSize, std::wstring localeName) {
    HRESULT hr;

    hr = D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &m_pDirect2dFactory);

    if (SUCCEEDED(hr)) {
        hr = DWriteCreateFactory(
            DWRITE_FACTORY_TYPE_SHARED,
            __uuidof(IDWriteFactory),
            (IUnknown**)&m_pDWriteFactory);
        
        if (SUCCEEDED(hr)) {
            hr = m_pDWriteFactory->CreateTextFormat(
                fontName.c_str(),
                nullptr,
                DWRITE_FONT_WEIGHT_NORMAL,
                DWRITE_FONT_STYLE_NORMAL,
                DWRITE_FONT_STRETCH_NORMAL,
                foneSize,
                localeName.c_str(),
                &m_pDTextFormat);
            return true;
        }
    }
    return false;
}

bool  KDXWrite::CreateDeviceResources(IDXGISurface1* pBackBuffer) {
    HRESULT hr;

    float dpi = GetDpiForWindow(g_hWnd);
    D2D1_RENDER_TARGET_PROPERTIES prop;
    ZeroMemory(&prop, sizeof(prop));
    prop.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
    prop.pixelFormat.format = DXGI_FORMAT_UNKNOWN;
    prop.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
    prop.dpiX = dpi;
    prop.dpiY = dpi;
    prop.usage = D2D1_RENDER_TARGET_USAGE_NONE;
    prop.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;


    hr = m_pDirect2dFactory->CreateDxgiSurfaceRenderTarget(
        pBackBuffer,
        &prop,
        &m_pRt);

    if (FAILED(hr))
    {
        return false;
    }
    hr = m_pRt->CreateSolidColorBrush(
        D2D1::ColorF(0, 0, 0, 1),
        &m_pSColorBrush);
    if (FAILED(hr))
    {
        return false;
    }
   
    return true;
}

bool  KDXWrite::Init()
{
    return true;
}
bool  KDXWrite::Frame()
{
    return true;
}
bool KDXWrite::PreRender() {
    if (m_pRt) {
        m_pRt->BeginDraw();
        m_pRt->SetTransform(D2D1::IdentityMatrix());
    }
    return true;
}

bool  KDXWrite::Render()
{
    PreRender();
    if (m_pRt) {
        for (int iText = 0; iText < m_TextList.size(); iText++)
        {
            std::wstring text = m_TextList[iText].text;
            D2D1_RECT_F layout = m_TextList[iText].layoutRt;
            m_pSColorBrush->SetColor(m_TextList[iText].color);
            m_pSColorBrush->SetOpacity(1.0f);
            m_pRt->DrawText(text.c_str(), text.size(),
                m_pDTextFormat, &layout, m_pSColorBrush);
        }
    }
    PostRender();
    return true;
}

bool KDXWrite::PostRender() {
    if (m_pRt) {
        m_pRt->EndDraw();
    }
    return true;
}

bool  KDXWrite::Release()
{
    if (m_pDirect2dFactory)m_pDirect2dFactory->Release();
    if (m_pDWriteFactory)m_pDWriteFactory->Release();
    if (m_pDTextFormat)m_pDTextFormat->Release();
    if (m_pRt)m_pRt->Release();
    if (m_pSColorBrush)m_pSColorBrush->Release();

    return true;
}

