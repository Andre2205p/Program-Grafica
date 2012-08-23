#ifndef WINOPENGL_H
#define WINOPENGL_H
#include <QGLWidget>

class winopengl: public QGLWidget//O QGLWidget é herdado para class winopenGL
{
public:
    winopengl();
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // WINOPENGL_H


