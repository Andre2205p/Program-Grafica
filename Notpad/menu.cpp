#include "menu.h"

menu::menu()
{
}

    void menu :: createMenu(){

    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    newAction = fileMenu->addAction(tr("N&ew"));
    openAction = fileMenu->addAction(tr("O&pen..."));
    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    //connect(openAction, SIGNAL(triggered()), aplc, SLOT(open()));
    //connect(exitAction, SIGNAL(triggered()), aplc, SLOT(quit()));

    helpMenu = new QMenu(tr("&Help"), this);
    helpAction = helpMenu->addAction(tr("H&elp"));
    menuBar->addMenu(helpMenu);
    }
