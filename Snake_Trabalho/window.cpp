#include "window.h"

Window::Window(QWidget *parent)
{
    quadro = new Board(0);   

    layout = new QGridLayout;
    file = new QFile();
    lcdLevel_1 = new QLCDNumber();
    lcdLevel_2 = new QLCDNumber();
    labelLevel = new QLabel("Level:",this);
    labelScore = new QLabel("Score:",this);    
    botaoStart = new QPushButton("Start");
    botaoPause = new QPushButton("Pause");
    botaoReset = new QPushButton("Reset");
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);
    barraProgresso = new QProgressBar();

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(botaoStart, SIGNAL(clicked()), quadro, SLOT(inicio()));
    connect(botaoPause, SIGNAL(clicked()), quadro, SLOT(pausa()));
    connect(quadro, SIGNAL(nivelDificuldade(int)), lcdLevel_1, SLOT(display(int)));
    connect(quadro, SIGNAL(pontosGanho(int)), lcdLevel_2, SLOT(display(int)));

    this->resize(304,400);
    this->setMaximumSize(304,400);

    quadro->setMinimumSize(104,200);
    quadro->setMaximumSize(304,400);

    createMenu();
    layout->addWidget(menuBar);        
    layout->addWidget(quadro,3,0,10,2);
    layout->addWidget(labelLevel, 3, 3);
    layout->addWidget(lcdLevel_1,4,3);
    layout->addWidget(labelScore, 5, 3);
    layout->addWidget(lcdLevel_2,6,3);
    layout->addWidget(botaoStart,7,3);
    layout->addWidget(botaoPause,8,3);
    layout->addWidget(botaoReset,9,3);
    layout->addWidget(barraProgresso);

    this->setLayout(layout);
    this->show();
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
            tr("<b>André G. da Silva</b> - 164164<p>Engenharia da Computação</p>UNOESC"));
}
