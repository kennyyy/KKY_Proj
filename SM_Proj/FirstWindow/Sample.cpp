#include <windows.h>

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;//�ν��Ͻ� �ڵ� ��������

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
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
    //Ȯ�����
    //typedef struct tagWNDCLASS
    //{
    //    UINT       style;     // ������ ��Ÿ�� ����
    //    WNDPROC      lpfnWndProc;    // �޽��� ó�� �Լ� ����
    //    int            cbClsExtra;    // �����
    //    int            cbWndExtra;    // �����
    //    HINSTANCE    hInstance;    // WinMain�� �μ��� ���޵�  hInstance���� �������ָ� �ȴ�.
    //    HICON         hIcon;     // ��� ������
    //    HCURSOR     hCursor;    // ���콺 Ŀ��
    //    HBRUSH        hbrBackground;   // ����
    //    LPCSTR        lpszMenuName;   // ����� �޴� ����
    //    LPCSTR        lpszClassName;   // ������ Ŭ���� �̸� ����
    //} WNDCLASS
    
    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.hCursor = LoadCursor(nullptr, IDC_WAIT);
    wcex.lpfnWndProc = WndProc;//���������ν���
    wcex.hInstance = hInstance;
    wcex.lpszClassName = L"KGCA������";
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255,255,0));//(COLOR_WINDOW + 1);


    WORD ret = RegisterClassExW(&wcex);//���ϰ� = WORD = typedef unsigned short
   


//   �Լ�: InitInstance(HINSTANCE, int)
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
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
  
    HWND hWnd = CreateWindowEx(dwExStyle,L"KGCA������", L"Ÿ��Ʋ", WS_OVERLAPPEDWINDOW,//WS_POPUPWINDOW,
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


    //// �⺻ �޽��� �����Դϴ�:
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
 
    //}


	//::MessageBox(NULL, L"����", L"dd", MB_OK);

	return 0;
}