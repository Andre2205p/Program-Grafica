/*
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class Notpad
{
public:    
    Notpad(){
        QTextEdit *editor = new QTextEdit("texto");//Cria um editor de texto dinamicamente

        QPushButton * quitButton = new QPushButton("Quit"); // Cria um Botao dinamicamente

        //Layout Vertical
        QVBoxLayout *layout = new QVBoxLayout;
            layout -> addWidget(editor);
            layout -> addWidget((quitButton));

        QWidget * window = new QWidget;
            window -> setLayout(layout);
            window -> show();
    }
};
*/

