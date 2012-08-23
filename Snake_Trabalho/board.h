#ifndef BOARD_H
#define BOARD_H
#include<QtGui>
#include <QProgressBar>

class Board : public QFrame
{
    Q_OBJECT
public:
    Board(QWidget *parent=0);
    int saveSocore;

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    int pos_x, pos_y, maca_x, maca_y, direcao, cont, level, veloc, score, contagem, vida, gameOver, tamSnake;
    int timeoutTime() { return 1000 / (2 + 2 * level); }
    bool ctrlFim,pause,vencedor, run;
    char end;        

    void fimJogo();
    void posicaoMaca();
    int randInt_x();
    int randInt_y();
    void incrementaLevel();
    void start();
    void colisaoSanke();
    int colisaoMaca();

    QBasicTimer tempo;
    QMessageBox msn;
    QFile *file;
    QProgressBar *barraProgresso;    
    QVector<int> vetorSnakeX;
    QVector<int> vetorSnakeY;

public slots:
    void inicio();    
    void pausa();
    void reset();

signals:
    void nivelDificuldade(int level);
    void pontosGanho(int score);
    void barra_Progresso();
    void barra_Vida();
    void sinalReset();
    void salvaScore();
};

#endif // BOARD_H
