#include "board.h" 

Board::Board(QWidget *parent)
{
    setFrameStyle(QFrame::Panel);
    setFocusPolicy(Qt::StrongFocus);
    ctrlFim = true;
    pause = false;
    end = 'i';
    veloc = 8;
    vida = 0;
    vencedor = false;
    run = false;
    gameOver = 11;
}

void Board::inicio(){
    this->setFocus();
    QSound botaoSound("Media/Windows Navigation Start.wav");
    botaoSound.play();

    if((pause == false) && (vida == 0) && (run == false)||(vencedor == true)){
        qDebug() << "inicio()";
        level = 1;
        score = 0;
        cont = 0;
        ctrlFim = false;
        pause = false;
        tamSnake = 1;
        start();        
        emit nivelDificuldade(level);
        emit pontosGanho(score);

    }else if(pause == true){
        tempo.start(timeoutTime(), this);
        pause = false;

    }else if(vida > 0 && vida < 3){
        start();
    }else if(end == 'f' && ctrlFim == true ){
        reset();
    }
}

void Board::start()
{
    if(run == false){
        qDebug() << "start()";
        vetorSnakeX.clear();
        vetorSnakeY.clear();
        run = true;
        pos_x = 64;
        pos_y = 64;
        direcao = 4;
        vencedor = false;
        posicaoMaca();
        tempo.start(timeoutTime(), this);
    }
}

void Board::reset()
{
    vetorSnakeX.clear();
    vetorSnakeY.clear();
    QSound botaoSound("Media/Windows Navigation Start.wav");
    botaoSound.play();            
    tempo.stop();            
    pause = false;
    score = 0;
    vida = 0;
    end == 'i';
    ctrlFim == false;
    tamSnake = 1;
    run = false;
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
    painter.drawRect(QRectF(0, 0, 208, 304)); //Área do Jogo
    painter.setBrush(Qt::blue); //pinta o Snake de de azul

    if((ctrlFim == false)  && (vencedor == false)){

        painter.drawRect(QRectF(pos_x, pos_y, 8.0, 8.0)); //Cabeça do Snake

        for(int i=0; i < vetorSnakeX.size(); i++){
            painter.drawRect(QRect(vetorSnakeX[i],vetorSnakeY[i],8,8));            
        }

        painter.setBrush(Qt::red); //pinta a Maçã de vermelho
        QRectF maca(maca_x, maca_y, 8.0, 8.0); //cria um retangulo nas as coordenadas x, y e a largura e altura pré-definidos
        painter.drawRect(maca); //
    }

    if(pause == true && end != 'f' && vencedor == false){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "PAUSA");
    }

    if(end == 'f' && ctrlFim == true && vencedor == false ){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "Fim de Jogo!!");
    }
    if(vencedor == true ){
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 20));
        painter.drawText(rect(), Qt::AlignCenter, "Você Ganhou!!!");               
    }    
}

void Board::keyPressEvent(QKeyEvent *event)
{
    QFrame::keyPressEvent(event);
    switch (event->key()) {
    case Qt::Key_Left:
        if(direcao != 2)
            direcao = 1;
        break;

    case Qt::Key_Right:
        if(direcao != 1)
            direcao = 2;
        break;

    case Qt::Key_Up:
        if(direcao != 4)
            direcao = 3;
        break;

    case Qt::Key_Down:
        if(direcao != 3)
            direcao = 4;
        break;

    default:
    QFrame::keyPressEvent(event);
    }
    this->update();
}

void Board::timerEvent(QTimerEvent *event)
{    
    saveSocore = score;
    QSound som("Media/Speech On.wav");
    if(pos_x <0 || pos_x > 200 || pos_y < 0 || pos_y > 296){
        this->update();
        fimJogo();
    }else{
        switch(direcao){
        case 1:
            pos_x = pos_x - veloc;
            break;
        case 2:
            pos_x = pos_x + veloc;            
            break;
        case 3:
            pos_y = pos_y - veloc;
            break;
        case 4:
            pos_y = pos_y + veloc;
            break;
        }
        if(pos_x >= 0 && pos_x <= 200 && pos_y >=0 && pos_y < 297){
            this->update();
        }                

        if(direcao==1 && (pos_x + veloc) == (maca_x)&& (pos_y == maca_y)){
            score = score +1;
            tamSnake++;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==2 && pos_x == (maca_x + veloc) && (pos_y == maca_y ) ){
            score = score +1;
            tamSnake++;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==3 && (pos_y + veloc) == (maca_y)&& (pos_x == maca_x)){
            score = score +1;
            tamSnake++;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }

        if(direcao==4 && (pos_y) == (maca_y + veloc)&& (pos_x == maca_x)){
            score = score +1;
            tamSnake++;
            som.play();
            posicaoMaca();
            emit pontosGanho(score);            
            emit barra_Progresso();
        }        
    }    
    colisaoSnke();
    vetorSnakeX.push_front(pos_x);
    vetorSnakeY.push_front(pos_y);

    while(vetorSnakeX.size()>tamSnake){
        vetorSnakeX.pop_back();
        vetorSnakeY.pop_back();
    }

    if(score == gameOver){
        fimJogo();
    }else{
        incrementaLevel();
    }
}

int Board::colisaoSnke(){ //Detecta se o Snake bate no próprio corpo
    for(int x = 1; x < vetorSnakeX.size(); x++){
        if(vetorSnakeX[x] == pos_x && vetorSnakeY[x] == pos_y){
            fimJogo();
        }
    }
}

int Board::colisaoMaca(){ //Detecta se a Maçã está sobre o Snake
    int posMaca = 0;
    for(int x = 1; x < vetorSnakeX.size(); x++){
        if(vetorSnakeX[x] == maca_x && vetorSnakeY[x] == maca_y)
            qDebug() << "Maca == Snake";
            posMaca = 1;
    }
    posMaca = 0;
}

void Board::incrementaLevel(){ //incrementa o display Level
    if(score == (level * 5)){
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
    return qrand() % 296;
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
        if(maca_y > 296){
            maca_y = 296;
        }
    }    
    if(colisaoMaca() == 1){
        posicaoMaca();
    }
    this->update();
}

void Board::fimJogo()
{
    vetorSnakeX.clear();
    vetorSnakeY.clear();
    saveSocore = score;
    run = false;    
    qDebug() << "saveSocore:" << saveSocore;

    if(score == gameOver){ //Você ganhou
        emit salvaScore();
        QSound killSound("Media/tada.wav");
        killSound.play();
        vencedor = true;
        tempo.stop();
        this->update();
    }else if(vida == 2){ //Fim de Jogo
        QSound killSound("Media/tada.wav");
        killSound.play();
        tempo.stop();
        ctrlFim = true;
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






