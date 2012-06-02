#include "not_pad.h"
#include "menu.h"
#include "welcome_window.h"
#include <QtGui>

//Exercício: QFrame, QKeyEvent, QSound, QImage

Not_pad::Not_pad(QApplication *app){

    baseTempo = 60;
    contadorBarra = 0;

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

       botaoBarraProgresso = new QPushButton("Barra Progresso");
       if(botaoBarraProgresso == NULL){
            editor -> setText("Botão Barra Progresso Falhou!");
       }else{
           temp = log;
           log = temp + "\n" + "Botão Barra Progresso Sucesso!";
           editor -> setText(log);
       }



       //QPushButton *button1 = new QPushButton("One");
       //QPushButton *button3 = new QPushButton("Three");


       contadorAuto = 0;
       aplc = app;

       connect(tempo, SIGNAL(timeout()), this, SLOT(incrementaDisplayAuto()));
       tempo->start(1000);

       incrementaDisplay();
       barraProgresso = new QProgressBar();
       barraProgresso->setRange(0,60);

       createMenu();

       contador = 0;       

       QObject::connect(botaoSair, SIGNAL(clicked()),app, SLOT(quit()));//Comando para dar a funçao de fechar ao botão
       QObject::connect(botaoIncrementaDisplay, SIGNAL(clicked()),this, SLOT(incrementaDisplay()));//O botaoIncrementaDisplay chama a funçao incrmentaDisplay()
       QObject::connect(botaoNovaJanela, SIGNAL(clicked()),this, SLOT(chamaNovaTela()));//O botaoNovaJanela2 chama a funçao chamaNovaTela()       
       QObject :: connect (botaoBarraProgresso,SIGNAL(clicked()),this,SLOT(barraDeProgresso()));

       /*
        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));
            layout -> addWidget((botao));
        */

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
            QGridlayout->addWidget(botaoBarraProgresso, 4, 1);
            QGridlayout->addWidget(botaoSair, 4,0);
            QGridlayout->setMenuBar(menuBar);
            QGridlayout->addWidget(barraProgresso, 5,0);

            //layout->addWidget(button1, 0, 0);
            //layout->addWidget(button3, 1, 0, 1, 2);
            //layout ->addWidget(lcd1,3,0Qt::AlignBottom);

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
    }else{
        contadorBarra ++;
    }

    /*
        QVariant v = 0;
        baseTempo = 10;
        v.setValue(baseTempo);
        editor->setText(v.toString());
    }
    */
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

//***********************************

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

void Not_pad :: createMenu(){

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
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
   }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             editor = file->readAll();
         file->close();

           return;

    QFile file("i.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

         QTextStream out(&file);
         out << "The magic number is: " << 50 << "\n";
   */









