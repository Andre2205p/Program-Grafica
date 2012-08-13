#include <QGLWidget>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGLWidget glwin;
    glwin.show();

    return app.exec();
}
