#ifndef WINOPENGL_H
#define WINOPENGL_H
#include <QGLWidget>
#include<QtGui>

class winopengl: public QGLWidget //O QGLWidget é herdado para class winopenGL
{
public:
    winopengl();
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    float angle_quad, angle_triang ;
    float triangulo_x, quadrado_x, triangulo_y, quadrado_y, triangulo_z, quadrado_z;
};

#endif // WINOPENGL_H
