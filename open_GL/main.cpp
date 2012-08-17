#include <QApplication>
#include "winopengl.h"
//#include <QGLWidget> //Utilizado para criar uma janela em branco somente com o main

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    //Cria uma tela em branco
    //QGLWidget glwin;
    //glwin.show();

    winopengl op;
    op.show();

    return app.exec();

}

