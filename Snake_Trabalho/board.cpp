#include "board.h" 

Board::Board(QWidget *parent)
{
    setFrameStyle(QFrame::Panel);
    setFocusPolicy(Qt::StrongFocus);
    ctrl = true;
    pause = false;
    end = 'i';
    veloc = 8;
    vida = 0;
    vencedor = false;
}

void Board::inicio(){
    this->setFocus();
    QSound botaoSound("Media/Windows Navigation Start.wav");
    botaoSound.play();
    if(pause == false && vida == 0 || vencedor == true){
        posX = pos_x;
        posY = pos_y - 8;
        level = 1;
        score = 0;
        cont = 0;
        ctrl = false;
        pause = false;
        start();
        emit nivelDificuldade(level);
        emit pontosGanho(score);

    }else if(pause == true){
        tempo.start(timeoutTime(), this);
        pause = false;

    }else if(vida > 0 && vida < 3){
        start();
    }else if(end == 'f' && ctrl == true ){
        reset();
    }
}

void Board::start()
{
    pos_x = 64;
    pos_y = 64;
    direcao = 3;
    vencedor = false;
    posicaoMaca();
    tempo.start(timeoutTime(), this);
}

void Board::reset()
{
    QSound botaoSound("Media/Windows Navigation Start.wav");
    botaoSound.play();
    tempo.stop();
    pause = false;
    score = 0;
    vida = 0;
    end == 'i';
    ctrl == false;
    emit sinalReset();
    inicio();
}

void Board:: pausa()
{
    QSound botaoSound("Media/Windows Navigation Start.wav");
    botaoSound.play();
    if(pause == false){
        tempo.stop();
        pause = true;
    }
    this->update();
}

void Board::paintEvent(QPaintEvent *evento)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue); //pinta o quadrado de azul
    if(ctrl == false  && vencedor == false){

            //for(int i=3; i >= 0; i--){
              //  x[i]=x[i-8]; y[i]=y[i-8];
                painter.drawRect(QRectF(pos_x, pos_y, 8.0, 8.0));
                //painter.drawRect(QRectF(posX, posY, 8.0, 8.0));
                //}

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

    if(pause == true && end != 'f' && vencedor == false){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "PAUSA");
    }

    if(end == 'f' && ctrl == true && vencedor == false ){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "Fim do Jogo!!");
    }
    if(vencedor == true ){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "Você Ganhou!!!");
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
        direcao = 1;
    break;

    case Qt::Key_Right:
        pos_x = pos_x + veloc;
        posX = pos_x - 8;
        posY = pos_y;
        direcao = 2;
    break;

    case Qt::Key_Up:
        pos_y = pos_y - veloc;
        posX = pos_x;
        posY = pos_y -8;
        direcao = 3;
    break;

    case Qt::Key_Down:
        pos_y = pos_y + veloc;
        posX = pos_x;
        posY = pos_y -8;
        direcao = 4;
    break;

    default:
    QFrame::keyPressEvent(event);
    }   
    this->update();
}

void Board::timerEvent(QTimerEvent *event)
{    
    QSound som("Media/Speech On.wav");    
    if(pos_x <0 || pos_x > 200 || pos_y < 0 || pos_y > 312){
        this->update();
        fimJogo();
    }else{
        switch(direcao){
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

        if(direcao==1 && (pos_x + veloc) == (maca_x)&& (pos_y == maca_y)){
            score = score +1;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==2 && pos_x == (maca_x + veloc) && (pos_y == maca_y ) ){
            score = score +1;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==3 && (pos_y + veloc) == (maca_y)&& (pos_x == maca_x)){
            score = score +1;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==4 && (pos_y) == (maca_y + veloc)&& (pos_x == maca_x)){
            score = score +1;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }        
    }
    if(score == 50){
        fimJogo();
    }
    incrementaLevel();
}

void Board::incrementaLevel(){ //incrementa o display Score
    if(score == (level * 10)){
        QSound som("Media/Windows Notify.wav");
        som.play();
        level++;
        tempo.start(timeoutTime(), this);
        emit nivelDificuldade(level);       
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

void Board::fimJogo()
{
    if(score == 50){
        QSound killSound("Media/tada.wav");
        killSound.play();
        vencedor = true;
        tempo.stop();
        this->update();
    }else if(vida == 2){
        QSound killSound("Media/tada.wav");
        killSound.play();
        tempo.stop();
        ctrl = true;
        end = 'f';
        vida++;
        emit barra_Vida();        
        this->update();
    }else{
        QSound killSound("Media/Windows Critical Stop.wav");
        killSound.play();
        vida ++;
        emit barra_Vida();
        tempo.stop();
        start();
    }
}






