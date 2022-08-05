#include "../Windows/WE_Window.h"
#include "../Windows/CWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{

	/*MainWindow win;
	win.Create(L"s", WS_OVERLAPPEDWINDOW);
	MainWindow wins;
	wins.Create(L"ss", WS_OVERLAPPEDWINDOW);*/

	DCWindow dcw;
	dcw.dcW().Create(L"cw", WS_OVERLAPPEDWINDOW);

	while (true)
	{
		if (const auto encode = dcw.dcW().ProcessMsg())
		{
			return *encode;
			
		}

	}
	


}