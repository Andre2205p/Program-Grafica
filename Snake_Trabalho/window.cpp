#include "window.h"

Window::Window(QWidget *parent)
{
    quadro = new Board(0);   

    layout = new QGridLayout;
    file = new QFile();
    lcdLevel = new QLCDNumber();
    lcdScore = new QLCDNumber();
    labelLevel = new QLabel("Level:",this);
    labelScore = new QLabel("Score:",this);    
    labelLife = new QLabel("Vida:",this);
    botaoStart = new QPushButton("Start");
    botaoPause = new QPushButton("Pause");
    botaoReset = new QPushButton("Reset");
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);
    barraProgresso = new QProgressBar();    
    barraVida = new QProgressBar();
    contadorBarra = 1;
    baseScore = 10;
    tamInicioBarra = 0;
    tamFimBarra = baseScore;
    barraVida->setMaximum(3);
    contadorVida = 0;

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(botaoStart, SIGNAL(clicked()), quadro, SLOT(inicio()));
    connect(botaoPause, SIGNAL(clicked()), quadro, SLOT(pausa()));
    connect(botaoReset, SIGNAL(clicked()), quadro, SLOT(reset()));
    connect(quadro, SIGNAL(nivelDificuldade(int)), lcdLevel, SLOT(display(int)));
    connect(quadro, SIGNAL(pontosGanho(int)), lcdScore, SLOT(display(int)));
    connect(quadro, SIGNAL(barra_Progresso()), this, SLOT(barraDeProgresso()));
    connect(quadro, SIGNAL(barra_Vida()), this, SLOT(barraDeVida()));
    connect(quadro, SIGNAL(sinalReset()), this, SLOT(resetBarraProgresso()));

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
}

void Window::resetBarraProgresso()
{
    tamInicioBarra = 0;
    tamFimBarra = 10;
    baseScore =10;
    contadorBarra = 0;
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
    barraProgresso->setRange(tamInicioBarra, tamFimBarra); // Range de 60 segundos para o barra de progresso
    barraProgresso->setValue(contadorBarra);   

    if(contadorBarra == baseScore ){
        tamInicioBarra = baseScore;
        barraProgresso->reset();
        baseScore = baseScore + 10;
        tamFimBarra = baseScore;
        contadorBarra ++;
    }else{
        contadorBarra ++;
    }
}

void Window :: createMenu()
{
    saveAction = fileMenu->addAction(tr("S&ave"));
    openAction = fileMenu->addAction(tr("O&pen..."));
    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    helpMenu = new QMenu(tr("&About"), this);
    helpMenu->addAction(aboutAct);
    menuBar->addMenu(helpMenu);
}

void Window::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    file -> setFileName(fileName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
            texto = file->readAll();
            file->close();
}

void Window::about()
{
    labelAbout = new QLabel();
    labelAbout->setText(tr("Invoked <b>About</b>"));
    QMessageBox::about(this, tr("About"),
            tr("Acadêmico:<b> André G. da Silva</b> - 164164<p>Curso: Engenharia da Computação</p>"
               "<p>Disciplina: Programação Móvel</p> UNOESC"));
}
