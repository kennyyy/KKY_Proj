#pragma once
#include <windows.h>
#include <string>

//함수매크로 GAME = 사실상 wWinMain임
#define KGAME_START  int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ KSample win;
#define KGAME_REGISTER win.SetRegisterClassWindow(hInstance);
#define KGAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define KGAME_RUN win.Run();
#define KGAME_END return 0; };

#define KGAME(s, w, h) KGAME_START;KGAME_REGISTER;KGAME_WINDOW (s, w, h);KGAME_RUN;KGAME_END;

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

