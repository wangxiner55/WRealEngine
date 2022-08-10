#include "WE_Window.h"
#include <iostream>
#include <memory>



PCWSTR MainWindow::ClassName() const
{
    return L"WE_Window";
}

DCWindow dcw;
LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
    case WM_KEYDOWN:
        dcw.dcW().Create(L"cww",WS_OVERLAPPEDWINDOW);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(b_hWnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(b_hWnd, &ps);
    }
    return 0;

    default:
        return DefWindowProc(b_hWnd, uMsg, wParam, lParam);
    }
    return TRUE;
}

std::optional<int> MainWindow::ProcessMsg()
{
    MSG msg;
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        /*if (msg.message == WM_QUIT)
        {
            return msg.wParam;
        }*/
        TranslateMessage(&msg);
        DispatchMessage(&msg);



    }
    return {};
}



void DCWindow::dcWindow()
{
    createWindow = std::make_unique<MainWindow>();

}

MainWindow& DCWindow::dcW()
{
    return *createWindow ;
}
