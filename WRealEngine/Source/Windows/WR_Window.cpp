#include "WR_Window.h"


//  -------------   RegisterClass   ----------------------//
Base_Windows::WindowClass::WindowClass() noexcept
{
    WNDCLASSEX wc = {};

    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = HandleMegSetup;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetInstance();
    wc.hIcon = static_cast<HICON>(LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, 0));
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = GetName();
    wc.hIconSm = static_cast<HICON>(LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, 0));
    RegisterClassEx(&wc);
}
//  -------------   RegisterClass   ----------------------//




Base_Windows::Base_Windows(HWND hWnd) noexcept
{

}

BOOL Base_Windows::Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu)
{
    hWnd = CreateWindowEx(
        dwExStyle, WindowClass::GetName(), lpWindowName, dwStyle, x, y,
        nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
    );
}

Base_Windows::~Base_Windows() noexcept
{
    DestroyWindow(hWnd);
}

HWND Base_Windows::GetHwnd() noexcept
{
    return hWnd;
}
