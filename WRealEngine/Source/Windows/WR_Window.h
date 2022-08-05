#pragma once
#include <Windows.h>
#include "../../Resoure/resource.h"

class Base_Windows
{

//    ---------------    WindowClass     -----------------      //
private:
	class WindowClass {

	private:
		WindowClass() noexcept;
		~WindowClass() noexcept;
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator = (const WindowClass&) = delete;

	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;

	private:

		static WindowClass wndClass;
		HINSTANCE hInst;

	private:
		static constexpr const char* wndClassname = "DX11";

	};
//    ---------------    WindowClass     -----------------      //

public:

	Base_Windows(HWND hWnd) noexcept;
	BOOL Create(
		PCWSTR lpWindowName,
		DWORD dwStyle,
		DWORD dwExStyle = 0,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT,
		int nHeight = CW_USEDEFAULT,
		HWND hWndParent = 0,
		HMENU hMenu = 0);
	~Base_Windows() noexcept;
	Base_Windows(const Base_Windows&) = delete;
	Base_Windows& operator = (const Base_Windows&) = delete;

	HWND GetHwnd() noexcept;



private:
	int width;
	int height;
	HWND hWnd;


};