#include "board.h"

Board::Board(QWidget *parent)
{
    setFrameStyle(QFrame::Panel);
    setFocusPolicy(Qt::StrongFocus);
    ctrl = true;
    end = 'i';
    veloc = 8;
    //QSound som("Media/Music.wav");
    //som.play();
}

void Board::inicio(){
    if(pause == false){
        this->setFocus();
        pos_x = 64;
        pos_y = 64;
        posX = pos_x;
        posY = pos_y - 8;
        maca_x = 96;
        maca_y = 80;
        opc = 3;
        level = 1;
        score = 0;
        cont = 0;
        ctrl = false;
        pause = false;
        tempo.start(timeoutTime(), this);
        emit nivelDificuldade(level);
    }
}

void Board:: pausa()
{
    if(pause == false){
        tempo.stop();
        pause = true;
    }else if(pause == true){
        tempo.start(timeoutTime(), this);
        pause = false;
    }
    this->update();
}

void Board::paintEvent(QPaintEvent *evento)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue); //pinta o quadrado de azul
    if(ctrl == false){

            for(int i=3; i >= 0; i--){
                x[i]=x[i-8]; y[i]=y[i-8];
                painter.drawRect(QRectF(pos_x, pos_y, 8.0, 8.0));
                }

            /*

        //painter.setBrush(Qt::blue); //pinta o quadrado de azul
        //QRectF rectangle(pos_x, pos_y, 8.0, 8.0); //cria um retangulo nas as coordenadas x, y e a largura e altura pré-definidos
        //painter.drawRect(rectangle);
/*
        painter.setBrush(Qt::blue); //pinta o quadrado de azul
        QRectF rect(posX, posY, 8.0, 8.0); //cria um retangulo nas as coordenadas x, y e a largura e altura pré-definidos
        painter.drawRect(rect);
*/

        painter.setBrush(Qt::red); //pinta o quadrado de vermelho
        QRectF maca(maca_x, maca_y, 8.0, 8.0); //cria um retangulo nas as coordenadas x, y e a largura e altura pré-definidos
        painter.drawRect(maca); //
    }

    if(pause == true && end != 'f'){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "PAUSA!");
    }

    if(end == 'f' && ctrl == true ){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "Fim do Jogo");
    }
    QFrame::paintEvent(evento);
}

void Board::keyPressEvent(QKeyEvent *event)
{
    QFrame::keyPressEvent(event);
    switch (event->key()) {
    case Qt::Key_Left:
        pos_x = pos_x - veloc;
        posX = pos_x - 8;
        posY = pos_y;

        opc = 1;
    break;

    case Qt::Key_Right:
        pos_x = pos_x + veloc;
        posX = pos_x - 8;
        posY = pos_y;
        opc = 2;
    break;

    case Qt::Key_Up:
        pos_y = pos_y - veloc;
        posX = pos_x;
        posY = pos_y -8;
        opc = 3;
    break;

    case Qt::Key_Down:
        pos_y = pos_y + veloc;
        posX = pos_x;
        posY = pos_y -8;
        opc = 4;
    break;

    default:
    QFrame::keyPressEvent(event);
    }
    /*
    qDebug() << "-----------------";
    qDebug() << "pos_y:" << pos_y;
    qDebug() << "pos_x:" << pos_x;
    qDebug() << "-----------------";
    qDebug() << "maca_y:" << maca_y;
    qDebug() << "maca_x:" << maca_x;
    */
    this->update();
}

void Board::timerEvent(QTimerEvent *event)
{    
    QSound som("Media/Speech On.wav");

    if(pos_x <0 || pos_x > 200 || pos_y < 0 || pos_y > 312){
        this->update();
        fimJogo();
    }else{
        switch(opc){
        case 1:
            pos_x = pos_x - veloc;
            posX = pos_x -8;

            break;
        case 2:
            pos_x = pos_x + veloc;
            posX = pos_x + 8;
            break;
        case 3:
            pos_y = pos_y - veloc;
            posY = pos_y - 8;

            break;
        case 4:
            pos_y = pos_y + veloc;
            posY = pos_y + 8;

            break;
        }
        if(pos_x >= 0 && pos_x <= 200 && pos_y >=0 && pos_y < 313){
            this->update();
        }        
        qDebug() << "pos_y:" << pos_y;
        qDebug() << "pos_x:" << pos_x;
        qDebug() << "maca_y:" << maca_y;
        qDebug() << "maca_x:" << maca_x;
        qDebug() << "-----------------";

        if(opc==1 && (pos_x + veloc) == (maca_x)&& (pos_y == maca_y)){
            score = score +1;
            som.play();

            qDebug() << "pos_y_1:" << pos_y;
            qDebug() << "pos_x_1:" << pos_x;
            qDebug() << "maca_y_1:" << maca_y;
            qDebug() << "maca_x_1:" << maca_x;

            posicaoMaca();
            emit pontosGanho(score);
        }

        if(opc==2 && pos_x == (maca_x + veloc) && (pos_y == maca_y ) ){
            score = score +1;
            som.play();

            qDebug() << "pos_y_2:" << pos_y;
            qDebug() << "pos_x_2:" << pos_x;
            qDebug() << "maca_y_2:" << maca_y;
            qDebug() << "maca_x_2:" << maca_x;

            posicaoMaca();
            emit pontosGanho(score);
        }

        if(opc==3 && (pos_y + veloc) == (maca_y)&& (pos_x == maca_x)){
            score = score +1;
            som.play();

            qDebug() << "pos_y_3:" << pos_y;
            qDebug() << "pos_x_3:" << pos_x;
            qDebug() << "maca_y_3:" << maca_y;
            qDebug() << "maca_x_3:" << maca_x;

            posicaoMaca();
            emit pontosGanho(score);
        }

        if(opc==4 && (pos_y) == (maca_y + veloc)&& (pos_x == maca_x)){
            score = score +1;
            som.play();

            qDebug() << "pos_y_4:" << pos_y;
            qDebug() << "pos_x_4:" << pos_x;
            qDebug() << "maca_y_4:" << maca_y;
            qDebug() << "maca_x_4:" << maca_x;

            posicaoMaca();
            emit pontosGanho(score);

        }
        incrementaLevel();
    }
}

void Board::incrementaLevel(){ //incrementa o display Score
    if(score == (level *10)){
        level++;
        emit nivelDificuldade(level);
        QSound som("Media/Windows Notify.wav");
        som.play();
    }

}

int Board::randInt_x() { // retorna um valor aleatório entre 0 e 192
    return qrand() % 192;
}

int Board:: randInt_y() { // retorna um valor aleatório entre 0 e 304
    return qrand() % 304;
}

void Board::posicaoMaca(){
    int x = 0, y = 0;
    int px = 0, py = 0;

    maca_x = (randInt_x());
    maca_y = (randInt_y());

    px = (maca_x +(2* veloc));
    py = (maca_y +(2* veloc));

    if(maca_x < 8){
        maca_x = 0;
    }else if(maca_x > 8){
        for(int i = 0; i < px; i++){
            x = x + 8;
            if(x == maca_x){
                break ;
            }else if(x > maca_x){
                maca_x = x;
                break;
            }
        }
        if(maca_x > 200){
            maca_x = 192;
        }
    }


    if(maca_y < 8){
        maca_y = 0;
    }else if(maca_y > 8){
        for(int i = 0; i < py; i++){
            y = y + 8;
            if(y == maca_y){
                break;
            }else if(y > maca_y){
                maca_y = y;
                break;
            }
        }
        if(maca_y > 304){
            maca_y = 304;
        }
    }

    this->update();
}

void Board::fimJogo(){
    tempo.stop();
    ctrl = true;
    end = 'f';
    this->update();
}





