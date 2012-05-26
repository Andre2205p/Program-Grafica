#include "not_pad.h"

QPushButton * quitButton;
//QTextEdit *editor;

Not_pad::Not_pad(QApplication *app){

       editor = new QTextEdit();//Cria um editor de texto dinamicamente
       //editor -> setText("Texto1");

       quitButton = new QPushButton("Quit"); // Cria um Botao dinamicamente no Layout

       QPushButton *button1 = new QPushButton("One");
       QPushButton *button2 = new QPushButton("Two");
       QPushButton *button3 = new QPushButton("Three");
       QPushButton *button4 = new QPushButton("Four");
       QPushButton *button5 = new QPushButton("Five");
       //lineEdit3 = new QLineEdit();

       QObject::connect(quitButton, SIGNAL(clicked()),app, SLOT(quit()));//Comando para dar a funçao de fechar ao botão

       /*
        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));
            layout -> addWidget((botao));
        */

       QGridLayout *layout = new QGridLayout;

            layout->addWidget(editor, 0,0,Qt::AlignCenter);
            //layout->addWidget(button1, 0, 0);
            layout->addWidget(button2, 0, 1);
            layout->addWidget(button3, 1, 0, 1, 2);
            layout->addWidget(button4, 2, 0);
            layout->addWidget(button5, 2, 1);


        window = new QWidget;
        window -> setLayout(layout);
}

void Not_pad :: show(){
     window -> show();     
}

void Not_pad :: setarTexto(QString string){
    texto = string;
}

void Not_pad :: exibirTexto(){
    editor -> setText(texto);
}







