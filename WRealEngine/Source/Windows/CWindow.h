#pragma once
#include <memory>
#include "WE_Window.h"


class CWindow
{

public:

	void cWindow();

	MainWindow& cW();

private :
	std::unique_ptr<MainWindow> createWindow;
};