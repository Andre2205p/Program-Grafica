#include "not_pad.h"
#include "menu.h"
#include "welcome_window.h"
#include "frame.h"
#include <QtGui>
#include <QSound>
#include <QLabel>
#include <QFrame>
#include"windows.h"

Not_pad::Not_pad(QApplication *app){

    baseTempo = 60;
    contadorBarra = 0;

    imagem = new QImage("C:/smiley.png");
    imgDisplayLabel = new QLabel("");
    imgDisplayLabel->setPixmap(QPixmap::fromImage(*imagem));
    imgDisplayLabel->adjustSize();

    QSound sound("c:/Windows/Media/chimes.wav");
    sound.play();

       editor = new QTextEdit();//Cria um editor de texto dinamicamente
       if(editor == NULL){
            editor -> setText("Editor Falhou");
       }else{
           log = "Editor Sucesso!";
           editor -> setText(log);
       }

       lcd1 = new QLCDNumber();
       if(lcd1 == NULL){
            editor -> setText("LCD1 Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "LCD1 Sucesso!";
           editor -> setText(log);
       }

       lcd2 = new QLCDNumber();
       if(lcd2 == NULL){
            editor -> setText("LCD2 Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "LCD2 Sucesso!";
           editor -> setText(log);
       }

       file = new QFile();
       if(file == NULL){
            editor -> setText("File Falhou!");
       }else{
           //editor -> setText("File Sucesso!");
           temp = log;
           log = temp + "\n" + "File Sucesso!";
           editor -> setText(log);
       }

       tempo = new QTimer(this);
       if(tempo == NULL){
            editor -> setText("Tempo Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Tempo Sucesso!";
           editor -> setText(log);
       }

       botaoSair = new QPushButton("Quit"); // Cria um Botao dinamicamente no Layout
       if(botaoSair == NULL){
            editor -> setText("Botão Sair Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Botão Sair Sucesso!";
           editor -> setText(log);
       }

       botaoIncrementaDisplay = new QPushButton("Contador");
       if(botaoIncrementaDisplay == NULL){
            editor -> setText("Botao Incrementa Display Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Botao Incrementa Display Sucesso!";
           editor -> setText(log);
       }

       botaoNovaJanela = new QPushButton("Nova Janela");
       if(botaoNovaJanela == NULL){
            editor -> setText("Botao Nova Janela Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Botao Nova Janela Sucesso!";
           editor -> setText(log);
       }

       botaoQFrame = new QPushButton("QFrame");
       if(botaoQFrame == NULL){
            editor -> setText("Botão QFrame Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Botão QFrame Sucesso!";
           editor -> setText(log);
       }

       menuBar = new QMenuBar;
       if(menuBar == NULL){
            editor -> setText("Menu Bar Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Menu Bar Sucesso!";
           editor -> setText(log);
       }

       fileMenu = new QMenu(tr("&File"), this);
       if(fileMenu == NULL){
            editor -> setText("File Menu Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "File Menu Sucesso!";
           editor -> setText(log);
       }

       botaoSound = new QPushButton("Sound");
       if(botaoSound == NULL){
                   editor -> setText("Botao Sound Falhou!");
              }else{
                  temp = log;
                  log = temp + "\n" + "Botao Sound Sucesso!";
                  editor -> setText(log);
              }

       contadorAuto = 0;
       aplc = app;

       connect(tempo, SIGNAL(timeout()), this, SLOT(incrementaDisplayAuto()));
       tempo->start(1000);

       incrementaDisplay();
       barraProgresso = new QProgressBar();
       barraProgresso->setRange(0,60); // Range de 60 segundos para o barra de progresso

       createMenu();
       contador = 0;

       QObject::connect(botaoSair, SIGNAL(clicked()),app, SLOT(quit()));//Comando para dar a funçao de fechar ao botão
       QObject::connect(botaoIncrementaDisplay, SIGNAL(clicked()),this, SLOT(incrementaDisplay()));//O botaoIncrementaDisplay chama a funçao incrmentaDisplay()
       QObject::connect(botaoNovaJanela, SIGNAL(clicked()),this, SLOT(chamaNovaTela()));//O botaoNovaJanela2 chama a funçao chamaNovaTela()       
       QObject::connect(botaoSound, SIGNAL(clicked()),this, SLOT(play()));
       QObject::connect(botaoSound, SIGNAL(clicked()),this, SLOT(play()));
       QObject::connect(botaoQFrame, SIGNAL(clicked()),this, SLOT(frame()));

       QGridlayout = new QGridLayout;
       if(QGridlayout == NULL){
            editor -> setText("QGridlayout Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "QGridlayout Sucesso!";
           editor -> setText(log);
       }
            //layout->addWidget(me);            
            QGridlayout->addWidget(editor, 0,0,Qt::AlignCenter);
            QGridlayout ->addWidget(lcd1,1,1);
            QGridlayout->addWidget(botaoIncrementaDisplay, 2, 1);
            QGridlayout ->addWidget(lcd2,3,1);
            QGridlayout->addWidget(botaoNovaJanela, 2, 0);
            QGridlayout->addWidget(botaoQFrame, 4, 1);
            QGridlayout->addWidget(botaoSair, 4,0);
            QGridlayout->setMenuBar(menuBar);
            QGridlayout->addWidget(barraProgresso, 5,0);
            QGridlayout->addWidget(botaoSound, 5,1);            
            QGridlayout->addWidget(imgDisplayLabel);

        window = new QWidget;
        if(window == NULL){
             editor -> setText("Window Falhou!");
        }else{
            temp = log;
            log = temp + "\n" + "Window Sucesso!";
            editor -> setText(log);
        }
        window -> setLayout(QGridlayout);
}

void Not_pad :: frame(){

    windows win;
    win.show();
    QObject :: connect (&win,SIGNAL(clicked()),this,SLOT(frame()));

    /*
    qframe = new QWidget;
//    qframe -> setLayout(QBoxlayout);
    qframe -> show();
   */


    //windows win;
    //win.show();

}

void Not_pad :: play(){
    QString fileSound = QFileDialog::getOpenFileName(this);//Abre uma Janela para escplher o Som
    QSound sound(fileSound);
    sound.play();
}

void Not_pad :: som(){
    QSound som("c:/Windows/Media/chimes.wav");
    som.play();
}

void Not_pad :: show(){
     window -> show();     
}

void Not_pad :: setarTexto(QString string){
    texto = string;
}

void Not_pad :: incrementaDisplay(){
    contador ++;
    lcd2 -> display(contador);
}

void Not_pad :: barraDeProgresso(){
    barraProgresso->setValue(contadorBarra);

    if(contadorAuto == baseTempo ){
        contadorBarra = 0;
        baseTempo = baseTempo + 60;
        som();
    }else{
        contadorBarra ++;
    }

}

void Not_pad :: incrementaDisplayAuto(){
    contadorAuto ++;
    lcd1 -> display(contadorAuto);

barraDeProgresso();
}

void Not_pad :: exibirTexto(){
    editor -> setText(texto);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
            texto = file->readAll();
            file->close();
    file -> setFileName("i.txt");
}

void Not_pad:: chamaNovaTela(){
   QBoxlayout = new QVBoxLayout;
   if(QBoxlayout == NULL){
        editor -> setText("QBoxlayout Falhou!");
   }else{
       temp = log;
       log = temp + "\n" + "QBoxlayout Sucesso!";
       editor -> setText(log);
   }

   newWindow = new QWidget;
   if(newWindow == NULL){
        editor -> setText("New Window Falhou!");
   }else{
       temp = log;
       log = temp + "\n" + "New Window Sucesso!";
       editor -> setText(log);
   }

   newWindow -> setLayout(QBoxlayout);
   newWindow -> show();
}

// Cria uma barra de menu superior da Janela
void Not_pad :: createMenu()
{
    newAction = fileMenu->addAction(tr("N&ew"));
    openAction = fileMenu->addAction(tr("O&pen..."));
    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(exitAction, SIGNAL(triggered()), aplc, SLOT(quit()));

    helpMenu = new QMenu(tr("&Help"), this);
    if(helpMenu == NULL){
         editor -> setText("Help Menu Falhou!");
    }else{
        temp = log;
        log = temp + "\n" + "Help Menu Sucesso!";
        editor -> setText(log);
    }
    helpAction = helpMenu->addAction(tr("H&elp"));
    menuBar->addMenu(helpMenu);
}

// Abre uma janela para escolher o arquivo
void Not_pad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    file -> setFileName(fileName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
            texto = file->readAll();
            file->close();
            editor -> setText(texto);
}

/*
    //scrollArea = new QScrollArea();
    //scrollArea->setWidget(imgDisplayLabel);
    ///scrollArea->setMinimumSize(256,256);
    //scrollArea->setMaximumSize(512,512);
    //gridLayout->addWidget(scrollArea,6,0);
    //setLayout(gridLayout);

QLabel *boatIcon = new QLabel(this);
boatIcon->setPixmap(QPixmap("c:/boat.png"));
boatIcon->move(10, 10);
//boatIcon->show();

QLabel *carIcon = new QLabel(this);
carIcon->setPixmap(QPixmap("c:/car.png"));
carIcon->move(100, 10);
//carIcon->show();

QLabel *houseIcon = new QLabel(this);
houseIcon->setPixmap(QPixmap("c:/house.png"));
houseIcon->move(10, 80);
//houseIcon->show();


        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));
            layout -> addWidget((botao));


*/

/*
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
   }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             editor = file->readAll();
         file->close();

           return;

    //Escreve em um arquivo escolhido
    QFile file("i.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

         QTextStream out(&file);
         out << "The magic number is: " << 50 << "\n";
   */

//QPushButton *button3 = new QPushButton("Three");

/*Converte Inteiro em String
    QVariant v = 0;
    baseTempo = 10;
    v.setValue(baseTempo);
    editor->setText(v.toString());
}
*/







