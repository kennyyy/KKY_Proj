#pragma once
#include "KWindow.h"


class KDevice : public KWindow
{


public:
	IDXGIFactory* m_pGIFacotry = nullptr;
	ID3D11Device* m_pDevice = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
	D3D_FEATURE_LEVEL       m_FeatureLevel;
	D3D11_VIEWPORT			m_ViewPort;

public:
	HRESULT CreateDevice();
	HRESULT CreateGIFactory();
	HRESULT CreateSwapChain();

	HRESULT SetRenderTargetView();
	HRESULT SetViewPort();



public:
	bool  Init();
	bool  Frame();
	bool  PreRender();
	bool  PostRender();
	bool  Render();
	bool  Release();
};


