#include "window.h"

Window::Window(QWidget *parent)
{
    chek = false;

    quadro = new Board(0);
    if(quadro == NULL){
        qDebug() << "quadro Falhou!";
        chek = true;
    }else{
        qDebug() << "quadro Sucesso!";
    }

    layout = new QGridLayout;
    if(layout == NULL){
        qDebug() << "layout Falhou!";
        chek = true;
    }else{
        qDebug() << "layout Sucesso!";
    }

    file = new QFile();
    if(file == NULL){
        qDebug() << "file Falhou!";
        chek = true;
    }else{
        qDebug() << "file Sucesso!";
    }

    lcdLevel = new QLCDNumber();
    if(lcdLevel == NULL){
        qDebug() << "lcdLevel Falhou!";
        chek = true;
    }else{
        qDebug() << "lcdLevel Sucesso!";
    }

    lcdScore = new QLCDNumber();
    if(lcdScore == NULL){
        qDebug() << "lcdScore Falhou!";
        chek = true;
    }else{
        qDebug() << "lcdScore Sucesso!";
    }

    labelLevel = new QLabel("Level:",this);
    if(labelLevel == NULL){
        qDebug() << "labelLevel Falhou!";
        chek = true;
    }else{
        qDebug() << "labelLevel Sucesso!";
    }

    labelScore = new QLabel("Score:",this);    
    if(labelScore == NULL){
        qDebug() << "labelScore Falhou!";
        chek = true;
    }else{
        qDebug() << "labelScore Sucesso!";
    }

    labelLife = new QLabel("Vida:",this);
    if(labelLife == NULL){
        qDebug() << "labelLife Falhou!";
        chek = true;
    }else{
        qDebug() << "labelLife Sucesso!";
    }

    botaoStart = new QPushButton("Start");
    if(botaoStart == NULL){
        qDebug() << "botaoStart Falhou!";
        chek = true;
    }else{
        qDebug() << "botaoStart Sucesso!";
    }

    botaoPause = new QPushButton("Pause");
    if(botaoPause == NULL){
        qDebug() << "botaoPause Falhou!";
        chek = true;
    }else{
        qDebug() << "botaoPause Sucesso!";
    }

    botaoReset = new QPushButton("Reset");
    if(botaoReset == NULL){
        qDebug() << "botaoReset Falhou!";
        chek = true;
    }else{
        qDebug() << "botaoReset Sucesso!";
    }

    menuBar = new QMenuBar;
    if(menuBar == NULL){
        qDebug() << "menuBar Falhou!";
        chek = true;
    }else{
        qDebug() << "menuBar Sucesso!";
    }

    fileMenu = new QMenu(tr("&File"), this);
    if(fileMenu == NULL){
        qDebug() << "fileMenu Falhou!";
        chek = true;
    }else{
        qDebug() << "fileMenu Sucesso!";
    }

    barraProgresso = new QProgressBar();    
    if(barraProgresso == NULL){
        qDebug() << "barraProgresso Falhou!";
        chek = true;
    }else{
        qDebug() << "barraProgresso Sucesso!";
    }

    barraVida = new QProgressBar();
    if(barraVida == NULL){
        qDebug() << "barraVida Falhou!";
        chek = true;
    }else{
        qDebug() << "barraVida Sucesso!";
    }

    tempo = new QTimer(this);
    if(tempo == NULL){
        qDebug() << "tempo Falhou!";
        chek = true;
    }else{
        qDebug() << "tempo Sucesso!";
    }

    contadorBarra = 1;
    baseScore =5;
    tamInicioBarra = 0;
    tamFimBarra = baseScore;
    barraVida->setMaximum(3);
    contadorVida = 0;

    aboutAct = new QAction(tr("&About"), this);
    if(aboutAct == NULL){
        qDebug() << "aboutAct Falhou!";
        chek = true;
    }else{
        qDebug() << "aboutAct Sucesso!";
    }

    aboutAct->setStatusTip(tr("Show the application's About box"));

    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(botaoStart, SIGNAL(clicked()), quadro, SLOT(inicio()));
    connect(botaoPause, SIGNAL(clicked()), quadro, SLOT(pausa()));
    connect(botaoReset, SIGNAL(clicked()), quadro, SLOT(reset()));
    connect(quadro, SIGNAL(nivelDificuldade(int)), lcdLevel, SLOT(display(int)));
    connect(quadro, SIGNAL(pontosGanho(int)), lcdScore, SLOT(display(int)));
    connect(quadro, SIGNAL(barra_Progresso()), this, SLOT(barraDeProgresso()));
    connect(quadro, SIGNAL(barra_Vida()), this, SLOT(barraDeVida()));
    connect(quadro, SIGNAL(sinalReset()), this, SLOT(resetJogo()));
    connect(quadro, SIGNAL(salvaScore()), this, SLOT(save()));

    this->resize(304,400);
    this->setMaximumSize(304,400);

    quadro->setMinimumSize(104,200);
    quadro->setMaximumSize(304,400);

    createMenu();
    layout->addWidget(menuBar);
    layout->addWidget(quadro,3,0,10,3);
    layout->addWidget(labelLevel, 3, 4);
    layout->addWidget(lcdLevel,4,4);
    layout->addWidget(labelScore, 5,4);
    layout->addWidget(lcdScore,6,4);
    layout->addWidget(botaoStart,7,4);
    layout->addWidget(botaoPause,8,4);
    layout->addWidget(botaoReset,9,4);
    layout->addWidget(barraProgresso);
    layout->addWidget(labelLife);
    layout->addWidget(barraVida);

    this->setLayout(layout);
    this->show();

    if(chek == true)
    {
        falhaCritica();
    }
}

void Window::falhaCritica()
{
    if(chek == true)
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::critical(this, tr("ATENÇAO!"),
                                    tr("Um ou mais componentes não foram inicializados corretamente."),
                                    QMessageBox::Ok);
        if (ret == QMessageBox::Ok){
            this->close();
        }
    }
}

void Window::resetJogo()
{
    tamInicioBarra = 0;
    tamFimBarra = 5;
    baseScore =5;
    contadorBarra = 1;
    contadorVida = 0;
    barraProgresso->reset();
    barraVida->reset();
    lcdScore->display(0);
    lcdLevel->display(1);
}

void Window::resetBarraVida()
{
    barraVida->reset();
    contadorVida = 0;
}

void Window::barraDeVida()
{
    contadorVida ++;
    barraVida->setValue(contadorVida);
}

void Window::barraDeProgresso()
{
    barraProgresso->setRange(tamInicioBarra, tamFimBarra);
    barraProgresso->setValue(contadorBarra);

    if(contadorBarra == baseScore ){
        tamInicioBarra = baseScore;
        barraProgresso->reset();
        baseScore = baseScore + 5;
        tamFimBarra = baseScore;
        contadorBarra ++;
    }else{
        contadorBarra ++;
    }
}

void Window :: createMenu()
{
    saveAction = fileMenu->addAction(tr("&Save Score"));
    clearAction = fileMenu->addAction(tr("&Clear Score"));
    openAction = fileMenu->addAction(tr("&Open Score"));
    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(clearAction, SIGNAL(triggered()), this, SLOT(clearScore()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openScores()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    helpMenu = new QMenu(tr("&About"), this);
    helpMenu->addAction(aboutAct);
    menuBar->addMenu(helpMenu);
}

void Window::save()
{
    scr = quadro->saveSocore;

    boxLayout = new QHBoxLayout();
    if(boxLayout == NULL){
        qDebug() << "boxLayout Falhou!";
        chek = true;
    }else{
        qDebug() << "boxLayout Sucesso!";
    }

    labelNome = new QLabel("Nome: ",this);
    if(labelNome == NULL){
        qDebug() << "labelNome Falhou!";
        chek = true;
    }else{
        qDebug() << "labelNome Sucesso!";
    }

    botaoSave = new QPushButton("Save",this);
    if(botaoSave == NULL){
        qDebug() << "botaoSave Falhou!";
        chek = true;
    }else{
        qDebug() << "botaoSave Sucesso!";
    }

    edit = new QLineEdit(this);
    if(edit == NULL){
        qDebug() << "edit Falhou!";
        chek = true;
    }else{
        qDebug() << "edit Sucesso!";
    }

    newWindow = new QWidget;
    if(newWindow == NULL){
        qDebug() << "newWindow Falhou!";
        chek = true;
    }else{
        qDebug() << "newWindow Sucesso!";
    }

    if(chek == true)
    {
        falhaCritica();
    }else{
        boxLayout->addWidget(labelNome);
        boxLayout->addWidget(edit);
        boxLayout->addWidget(botaoSave);

        newWindow -> setLayout(boxLayout);
        newWindow -> show();

        if(readScore() == false){
            connect(botaoSave,SIGNAL(clicked()),this,SLOT(writeScore()));
        }else{
            connect(botaoSave,SIGNAL(clicked()),this,SLOT(readWriteScore()));
        }
    }
}

void Window::writeScore(){
    QFile files("score.dat");
    files.open(QIODevice::WriteOnly);
    QDataStream out(&files);

    nome = edit->text();
    scoreTxt = QString::number(scr);
    txtSave = nome + " - " + scoreTxt;

    out << QString(txtSave);
    newWindow->close();

    chamaOpenScore();
}

bool Window::readScore()
{
    bool isEmpty = false;
    QFile files("score.dat");
    files.open(QIODevice::ReadOnly);
    QDataStream in(&files);
    str;
    in >> str;

    if(str != NULL){
        isEmpty = true;
    }
    return isEmpty;
}

void Window::openScores()
{
    tempo->stop();
    newWindow->close();
    readScore();

    QWidget *windowScore = new QWidget;
    QLabel *scoreLabel =new QLabel("SCORE: ",this);
    QLabel *scoreResult =new QLabel(str,this);
    QPushButton *botaoOk = new QPushButton("Ok");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(scoreLabel);
    layout->addWidget(scoreResult);

    layout->addWidget(botaoOk);

    windowScore->setLayout(layout);
    windowScore->show();

    connect (botaoOk,SIGNAL(clicked()),windowScore,SLOT(close()));
}

void Window::readWriteScore()
{
    QFile fil("score.dat");
    fil.open(QIODevice::ReadOnly);
    QDataStream in(&fil);
    str;
    in >> str;

    QFile files("score.dat");
    files.open(QIODevice::WriteOnly);
    QDataStream out(&files);

    nome = edit->text();
    scoreTxt = QString::number(scr);
    txtSave = str + "\n" + nome + " - " + scoreTxt;

    out << QString(txtSave);
    qDebug() << "Score";
    qDebug() << txtSave;

    newWindow->close();

    chamaOpenScore();
}

void Window::chamaOpenScore()
{
    tempo->disconnect();
    connect(tempo, SIGNAL(timeout()), this, SLOT(openScores()));
    tempo->start(100);
}

void Window::clearScore()
{
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Apagar Score"),
                 tr("Todos os Scores serão apagados.\n"
                    "Você realmente deseja continuar?"),
                 QMessageBox::Ok | QMessageBox::Cancel);
    if (ret == QMessageBox::Ok){
        QFile f("score.dat");
        f.remove();
        qDebug() << "Ok";
    }
}

void Window::about()
{
    labelAbout = new QLabel();
    labelAbout->setText(tr("Invoked <b>About</b>"));
    QMessageBox::about(this, tr("About"),
            tr("Acadêmico:<b> André G. da Silva</b> - 164164<p>Curso: Engenharia da Computação</p>"
               "<p>Disciplina: Programação Móvel</p> <p>Professor: Karl Phillip</p>UNOESC"));
}
