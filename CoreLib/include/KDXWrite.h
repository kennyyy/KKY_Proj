#pragma once
#include <string>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <vector>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

struct TextData {
	std::wstring text;
	D2D1_RECT_F layoutRt;
	D2D1::ColorF color = { 0.0f, 0.0f, 0.0f, 1.0f };
};



class KDXWrite
{
public:
	IDXGISwapChain* m_pSwapChain = nullptr;
	std::vector<TextData> m_TextList;
public:
	IDXGISurface1* m_pSurface1 = nullptr;
	ID2D1Factory* m_pDirect2dFactory= nullptr;
	IDWriteFactory* m_pDWriteFactory = nullptr;
	IDWriteTextFormat* m_pDTextFormat = nullptr;
	ID2D1RenderTarget* m_pRt = nullptr;
	ID2D1SolidColorBrush* m_pSColorBrush = nullptr;
public:
	bool Set(IDXGISwapChain* pSwapChain);
	bool Create(std::wstring fontName, INT foneSize, std::wstring localeName);
	void AddText(std::wstring text, float x, float y, float width, float height, D2D1::ColorF color = { 0.0f, 0.0f, 0.0f,1.0f });
	bool CreateFactoryAndCreateTextFormat(std::wstring fontName, INT foneSize, std::wstring localeName);
	bool CreateDeviceResources(IDXGISurface1* pBackBuffer);
public:
	bool Init();
	bool Frame();
	bool PreRender();
	bool Render();
	bool PostRender();
	bool Release();

	KDXWrite() {};
};

