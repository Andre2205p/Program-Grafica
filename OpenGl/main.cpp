//#include <QGLWidget> //Utilizado para criar uma janela em branco somente com o main
#include <QApplication>
#include "winopengl.h"

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
