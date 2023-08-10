#pragma once
#include <windows.h>
#include <string>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>			//D3DComplileFromFile
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll

#define KGAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ KSample win;
#define KGAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define KGAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define KGAME_RUN win.Run();
#define KGAME_END return 0; };

#define KGAME(s,w,h) KGAME_START;KGAME_REGISTER;KGAME_WINDOW(s,w,h);KGAME_RUN;KGAME_END;