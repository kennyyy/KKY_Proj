#pragma once
#include <windows.h>
#include <string>
#include <d3d11.h>
#include <dxgi.h>
#include "KStd.h"

class KWindow 
{
public:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	//CreateWindowEx()속성 값들
	DWORD m_dwExStyle = 0;
	DWORD m_dwStyle = WS_OVERLAPPEDWINDOW;
	DWORD m_dwWindowPosX = 0;
	DWORD m_dwWindowPosY = 0;
	DWORD m_dwWindowWidth;
	DWORD m_dwWindowHeight;

public:
	bool SetRegisterClassWindow(HINSTANCE m_hInstance);
	bool SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth = 800, DWORD  dwWindowHeight = 600);

public:
	virtual ~KWindow() {};
};

