#include "windows.h"

windows::windows(QWidget *parent)
{

    layout = new QGridLayout();
    quadro = new Board(0);
    this->resize(500,500);
    this->setMaximumSize(500,500);

 //  quadro->resize(200,200);
   quadro->setMinimumSize(500,500);
   quadro->setMaximumSize(500,500);

    layout->addWidget(quadro);

    this->setLayout(layout);
    this->show();


}
