#ifndef WINDOW_H
#define WINDOW_H

#include<QtGui>
#include "board.h"

class windows:public QWidget
{
    Q_OBJECT
public:
    windows(QWidget *parent=0);
    Board *quadro;
    QGridLayout *layout;

    int alturaJanela, larguraJanela, larguraBorda, alturaBorda;

};

#endif // WINDOW_H
