#include "not_pad.h"
#include "welcome_window.h"

QPushButton * botaoSair;
//QTextEdit *editor;

Not_pad::Not_pad(QApplication *app){

       editor = new QTextEdit();//Cria um editor de texto dinamicamente
       lcd1 = new QLCDNumber();
       lcd2 = new QLCDNumber();


       tempo = new QTimer(this);
       connect(tempo, SIGNAL(timeout()), this, SLOT(incrementaDisplayAuto()));
       tempo->start(1000);

       incrementaDisplay();


       //editor -> setText("Texto1");

       botaoSair = new QPushButton("Quit"); // Cria um Botao dinamicamente no Layout
       contador = 0;

       QPushButton *button1 = new QPushButton("One");
       QPushButton *botaoIncrementaDisplay = new QPushButton("Contador");
       QPushButton *button3 = new QPushButton("Three");
       QPushButton *botaoNovaJanela = new QPushButton("Nova Janela");
       QPushButton *button5 = new QPushButton("Five");

       //lineEdit3 = new QLineEdit();

       QObject::connect(botaoSair, SIGNAL(clicked()),app, SLOT(quit()));//Comando para dar a funçao de fechar ao botão
       QObject::connect(botaoIncrementaDisplay, SIGNAL(clicked()),this, SLOT(incrementaDisplay()));//O botaoIncrementaDisplay chama a funçao incrmentaDisplay()
       QObject::connect(botaoNovaJanela, SIGNAL(clicked()),this, SLOT(chamaNovaTela()));//O botaoNovaJanela2 chama a funçao chamaNovaTela()

       /*
        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));
            layout -> addWidget((botao));
        */

       QGridLayout *layout = new QGridLayout;

            layout->addWidget(editor, 0,0,Qt::AlignCenter);            
            layout ->addWidget(lcd1,1,1);
            layout->addWidget(botaoIncrementaDisplay, 2, 1);
            layout ->addWidget(lcd2,3,1);
            layout->addWidget(botaoNovaJanela, 2, 0);
            layout->addWidget(button5, 4, 1);
            layout->addWidget(botaoSair, 4,0);

            //layout->addWidget(button1, 0, 0);
            //layout->addWidget(button3, 1, 0, 1, 2);
            //layout ->addWidget(lcd1,3,0Qt::AlignBottom);


        window = new QWidget;
        window -> setLayout(layout);
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

void Not_pad :: incrementaDisplayAuto(){
    contadorAuto ++;
    lcd1 -> display(contadorAuto);
}

void Not_pad :: exibirTexto(){
    editor -> setText(texto);
}
//***********************************8s
void Not_pad:: chamaNovaTela(){
   layout = new QVBoxLayout;
   newWindow = new QWidget;
   newWindow -> setLayout(layout);
   newWindow -> show();

}






