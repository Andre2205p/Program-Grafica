#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "not_pad.h"
#include "welcome_window.h"
#include "frame.h"
#include "windows.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);    

    Not_pad note(&app);
    note.show();
    note.setarTexto("setarTexto");

    Welcome_Windows wwin;
    wwin.setText("Ok");
    wwin.show();

    QObject :: connect (&wwin,SIGNAL(clicked()),&note,SLOT(exibirTexto()));
    QObject :: connect (&wwin,SIGNAL(clicked()),&note,SLOT(incrementaDisplay()));

    /*
    QWidget mainWidget;
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    //horizontalLayout->addWidget(new Frame);
    horizontalLayout->addWidget(new Not_pad);

    mainWidget.setLayout(horizontalLayout);
    mainWidget.setWindowTitle(QObject::tr("Draggable Icons"));

    mainWidget.show();
    QObject :: connect (&mainWidget,SIGNAL(clicked()),&note,SLOT(frame()));
    */
    return app.exec();
}


