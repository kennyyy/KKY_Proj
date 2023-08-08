#include <windows.h>

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;//인스턴스 핸들 전역변수

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}





//windowMain
int APIENTRY wWinMain( HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine, 
	int nCmdShow) 
{
    //확장버전
    //typedef struct tagWNDCLASS
    //{
    //    UINT       style;     // 윈도우 스타일 정의
    //    WNDPROC      lpfnWndProc;    // 메시지 처리 함수 지정
    //    int            cbClsExtra;    // 예약어
    //    int            cbWndExtra;    // 예약어
    //    HINSTANCE    hInstance;    // WinMain의 인수로 전달된  hInstance값을 대입해주면 된다.
    //    HICON         hIcon;     // 출력 아이콘
    //    HCURSOR     hCursor;    // 마우스 커서
    //    HBRUSH        hbrBackground;   // 배경색
    //    LPCSTR        lpszMenuName;   // 사용할 메뉴 지정
    //    LPCSTR        lpszClassName;   // 윈도우 클래스 이름 지정
    //} WNDCLASS
    
    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.hCursor = LoadCursor(nullptr, IDC_WAIT);
    wcex.lpfnWndProc = WndProc;//윈도우프로시저
    wcex.hInstance = hInstance;
    wcex.lpszClassName = L"KGCA윈도우";
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255,255,0));//(COLOR_WINDOW + 1);


    WORD ret = RegisterClassExW(&wcex);//리턴값 = WORD = typedef unsigned short
   


//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
    hInst = hInstance;

    DWORD dwExStyle = 0;
    DWORD dwStyle = WS_OVERLAPPEDWINDOW;
    //DWORD dwWindowPosX = 0;
    //DWORD dwWindowPosY = 0;
    //DWORD dwWindowPosX = 0;
    //DWORD dwWindowPosX = 0;

#ifndef _DEBUG
    dwExStyle = WS_EX_TOPMOST;
#else
    dwExStyle = WS_EX_APPWINDOW;
#endif
  
    HWND hWnd = CreateWindowEx(dwExStyle,L"KGCA윈도우", L"타이틀", WS_OVERLAPPEDWINDOW,//WS_POPUPWINDOW,
        0, 0, 800, 600, nullptr, 
        nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }
    //nCmdShow
 
    ShowWindow(hWnd, SW_SHOWNORMAL);

 //
 //
 //
    
    MSG msg = { 0 };

    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {

        }
    }


    //// 기본 메시지 루프입니다:
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
 
    //}


	//::MessageBox(NULL, L"내용", L"dd", MB_OK);

	return 0;
}