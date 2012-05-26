#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "not_pad.h"
#include "welcome_window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    //Notpad note;

    Not_pad note(&app);
    note.show();
    note.setarTexto("setarTexto");

    Welcome_Windows wwin;
    wwin.setText("Ok");

    wwin.show();
    QObject :: connect (&wwin,SIGNAL(clicked()),&note,SLOT(exibirTexto()));
    QObject :: connect (&wwin,SIGNAL(clicked()),&note,SLOT(incrementaDisplay()));

    return app.exec();
}
