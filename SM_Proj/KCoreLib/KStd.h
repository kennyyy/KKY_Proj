#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
#include <codecvt>
#include <map>
#include <unordered_map> 
#include <queue>


#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>			//D3DComplileFromFile
#include "DirectXTex.h" // 이게 텍스처 호환성이 넓음
#include "KUtils.h"
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll
#pragma comment (lib, "DirectXTex.lib")
#pragma comment (lib, "KCoreLib.lib")

//#include "./WIC/WICTextureLoader.h" // 기타
//#include "./WIC/DDSTextureLoader.h" // DDS 전용

typedef std::basic_string<TCHAR>			T_STR;
typedef std::basic_string<wchar_t>			W_STR;
typedef std::basic_string<char>				C_STR;
typedef std::vector<T_STR>					T_STR_VECTOR;
typedef std::basic_string<TCHAR>::iterator		T_ITOR;
typedef std::basic_string<wchar_t>::iterator	W_ITOR;
typedef std::basic_string<char>::iterator	C_ITOR;
typedef std::vector<T_STR>				T_ARRAY_ITOR;
typedef std::vector<DWORD>				DWORD_VECTOR;
typedef	std::vector< DWORD >::iterator	DWORD_VECTOR_ITOR;
typedef std::list<DWORD>				DWORD_LIST;
typedef std::list<DWORD>::iterator		DWORD_LIST_ITOR;
typedef std::list< HANDLE >				HANDLE_LIST;
typedef	std::list< HANDLE >::iterator	HANDLE_LIST_ITOR;



static std::wstring mtw(std::string str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
	return conv.from_bytes(str);
}

static std::string wtm(std::wstring str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
	return conv.to_bytes(str);
}

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

extern float g_fMapSizeX;
extern float g_fMapSizeY;
extern DWORD g_dwWindowWidth;
extern DWORD g_dwWindowHeight;

static void K_DebugString(const WCHAR* msg)
{
#ifdef _DEBUG
	OutputDebugString(msg);
#endif
}