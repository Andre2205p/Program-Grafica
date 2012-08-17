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
    QLabel *labelLevel, *labelScore, *label_imagem, *labelLife, *scoreLabel, *labelAbout, *labelNome, *labelMsn;
    Board *quadro;
    QLCDNumber *lcdLevel, *lcdScore;
    QFile *file;
    QMenuBar *menuBar;
    QMenu *fileMenu, *helpMenu;
    QAction *exitAction, *clearAction, *saveAction, *helpAction, *openAction, *aboutAct;
    QProgressBar *barraProgresso, *barraVida;
    QPushButton * botaoStart, *botaoPause, *botaoReset, *botaoSave;
    QString texto, nome, scoreTxt, txtSave, str;
    QLineEdit *edit;    
    QTimer *tempoScore;
    QGridLayout *layout;
    QHBoxLayout *boxLayout;    
    QWidget *newWindow;

    int alturaJanela, larguraJanela, larguraBorda, alturaBorda, contadorBarra, score, baseScore, tamFimBarra, scr,
        tamInicioBarra, contadorVida;
    bool chek;

    void createMenu();    
    void telaSave();
    void chamaNovaTela();
    void editScore();
    void chamaOpenScore();
    void falhaCritica();

public slots:   
    void about();
    void save();
    void barraDeProgresso();
    void barraDeVida();
    void resetJogo();
    void resetBarraVida();

    void writeScore();
    bool readScore();
    void readWriteScore();
    void clearScore();
    void openScores();

};

#endif // WINDOW_H
