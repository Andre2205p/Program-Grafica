#include "not_pad.h"

QPushButton * quitButton;

Not_pad::Not_pad(QApplication *app){

       QTextEdit *editor = new QTextEdit("texto");//Cria um editor de texto dinamicamente

       quitButton = new QPushButton("Quit"); // Cria um Botao dinamicamente
       QObject::connect(quitButton, SIGNAL(clicked()),app, SLOT(quit()));//Comando para dar a funçao de fechar ao botão

        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));

        window = new QWidget;
            window -> setLayout(layout);
}

void Not_pad :: show(){
     window -> show();
}



