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

//  ------------------------        -----------------------//
Base_Windows::WindowClass::~WindowClass() noexcept
{
    UnregisterClass(GetName(), GetInstance());
}
const char* Base_Windows::WindowClass::GetName() noexcept
{
    return wndClassname;
}
inline HINSTANCE Base_Windows::WindowClass::GetInstance() noexcept
{
    return wndClass.hInst;
}
//  -------------   RegisterClass   ----------------------//




Base_Windows::Base_Windows(HWND hWnd) noexcept
{

}

BOOL Base_Windows::Create(LPCSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu)
{
    hWnd = CreateWindowExA(
        dwExStyle, WindowClass::GetName(), lpWindowName, dwStyle, x, y,
        nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
    );

    ShowWindow(hWnd, SW_SHOWDEFAULT);

}

Base_Windows::~Base_Windows() noexcept
{
    DestroyWindow(hWnd);
}

HWND Base_Windows::GetHwnd() noexcept
{
    return hWnd;
}
