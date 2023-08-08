#include "KWindow.h"


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


bool KWindow::SetRegisterClassWindow(HINSTANCE hInstance) {

    m_hInstance = hInstance;
    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.hCursor = LoadCursor(nullptr, IDC_WAIT);
    wcex.lpfnWndProc = WndProc;//윈도우프로시저
    wcex.hInstance = m_hInstance;
    wcex.lpszClassName = L"KGCA윈도우";
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(12, 52, 25));//(COLOR_WINDOW + 1);

    WORD ret = RegisterClassEx(&wcex);
    return true;

}

bool KWindow::SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth, DWORD dwWindowHeight) {
         /*CreateWindowEx() 정의
        _In_ DWORD dwExStyle,
        _In_opt_ LPCWSTR lpClassName,
        _In_opt_ LPCWSTR lpWindowName,
        _In_ DWORD dwStyle,
        _In_ int X,
        _In_ int Y,
        _In_ int nWidth,
        _In_ int nHeight,
        _In_opt_ HWND hWndParent,
        _In_opt_ HMENU hMenu,
        _In_opt_ HINSTANCE hInstance,
        _In_opt_ LPVOID lpParam)

      //CreateWindowEx() 값들
        DWORD m_dwExStyle = 0;
        DWORD m_dwStyle = WS_OVERLAPPEDWINDOW;
        DWORD m_dwWindowPosX = 0;
        DWORD m_dwWindowPosY = 0;
        DWORD m_dwWindowWidth;
        DWORD m_dwWIndowHeight;  */

        m_hWnd = CreateWindowEx(m_dwExStyle, L"KGCA윈도우", szTitle, m_dwStyle,//WS_POPUPWINDOW,
        m_dwWindowPosX, m_dwWindowPosY, dwWindowWidth, dwWindowHeight, nullptr,
        nullptr, m_hInstance, nullptr);

    if (!m_hWnd)
    {
        return FALSE;
    }
    //nCmdShow

    ShowWindow(m_hWnd, SW_SHOWNORMAL);

    return true;
}