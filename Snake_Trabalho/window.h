#ifndef WINDOW_H
#define WINDOW_H

#include<QtGui>
#include "board.h"

class Window:public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parent=0);

private:
    QLabel *labelLevel, *labelScore, *label_imagem;

    Board *quadro;
    QGridLayout *layout;

    QLCDNumber *lcdLevel_1, *lcdLevel_2;
    QFile *file;

    QMenuBar *menuBar;
    QMenu *fileMenu, *helpMenu;
    QAction *exitAction, *openAction, *saveAction, *helpAction;

    QProgressBar *barraProgresso;
    QPushButton * botaoStart, *botaoPause, *botaoReset;

    QApplication * aplc;

    QImage* imagem;
    QString texto;
    QLabel *labelAbout;
    QAction *aboutAct;

    int alturaJanela, larguraJanela, larguraBorda, alturaBorda;

    void createMenu();

public slots:
    void open();
    void about();



};

#endif // WINDOW_H
