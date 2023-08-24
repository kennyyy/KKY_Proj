#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <string>
#include <vector>
#include <memory>

#include <map>

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>			//D3DComplileFromFile
#include "DirectXTex.h" // �̰� �ؽ�ó ȣȯ���� ����
#include "KUtils.h"
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll
#pragma comment (lib, "DirectXTex.lib")

//#include "./WIC/WICTextureLoader.h" // ��Ÿ
//#include "./WIC/DDSTextureLoader.h" // DDS ����

extern float g_fMapSizeX ;
extern float g_fMapSizeY ;
extern DWORD g_dwWindowWidth;
extern DWORD g_dwWindowHeight;

#define T_PI (3.141592f)
#define T_EPSILON ( 0.0001f)
#define RadianToDegree(radian) ( radian *( 180.0f / T_PI))
#define DegreeToRadian(degree) ( degree *( T_PI / 180.0f))
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

#define KGAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ KSample win;
#define KGAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define KGAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define KGAME_RUN win.Run();
#define KGAME_END return 0; };

#define KGAME(s,w,h) KGAME_START;KGAME_REGISTER;KGAME_WINDOW(s,w,h);KGAME_RUN;KGAME_END;

extern HWND g_hWnd;
extern float	 g_fGameTimer;
extern float	 g_fSecondPerFrame;

static void K_DebugString(const WCHAR* msg)
{
#ifdef _DEBUG
	OutputDebugString(msg);
#endif
}