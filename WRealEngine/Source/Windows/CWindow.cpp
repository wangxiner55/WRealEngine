#include "CWindow.h"

void CWindow::cWindow()
{
    createWindow = std::make_unique<MainWindow>();
    
}

MainWindow& CWindow::cW()
{
    return *createWindow;
}
