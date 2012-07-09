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
    QLabel *labelLevel, *labelScore, *label_imagem, *labelLife;

    Board *quadro;
    QGridLayout *layout;

    QLCDNumber *lcdLevel, *lcdScore;
    QFile *file;

    QMenuBar *menuBar;
    QMenu *fileMenu, *helpMenu;
    QAction *exitAction, *openAction, *saveAction, *helpAction;

    QProgressBar *barraProgresso, *barraVida;
    QPushButton * botaoStart, *botaoPause, *botaoReset;

    QApplication * aplc;

    QImage* imagem;
    QString texto;
    QLabel *labelAbout;
    QAction *aboutAct;

    int alturaJanela, larguraJanela, larguraBorda, alturaBorda, contadorBarra, score, baseScore, tamFimBarra,
        tamInicioBarra, contadorVida;

    void createMenu();

public slots:
    void open();
    void about();
    void barraDeProgresso();
    void barraDeVida();
    void resetBarraProgresso();
    void resetBarraVida();

};

#endif // WINDOW_H
