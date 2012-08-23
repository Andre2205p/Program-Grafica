#ifndef BOARD_H
#define BOARD_H

#include<QtGui>

class Board : public QFrame
{
    Q_OBJECT
public:
    Board(QWidget *parent=0);
protected:
   // void paintEvent(QPaintEvent *event);
   // void keyPressEvent(QKeyEvent *event);
   // void timerEvent(QTimerEvent *event);

private:
    //void _move(int new_pos_x, int new_pos_y);
    //void _draw_square(QPainter &painters, int x, int y);

    int _pos_x, _pos_y;



};

#endif // BOARD_H









/*
#ifndef BOARD_H
#define BOARD_H
#include <QFrame>

class board : QFrame
{
    Q_OBJECT
public:
    board();

private:
    void _move(int new_Pos_x, int new_Pos_Y);
    void _drawSquare(QPainel, int x, int y);

    int _borad_widht;
    int _borad_height;
    int _pos_x;
    int _pos_y;

protected:
    void pointEvent(QPaintEvent *event);

};

#endif // BOARD_H
*/
