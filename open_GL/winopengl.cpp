#define _STDCALL_SUPPORTED
#define GLUT_NO_LIB_PRAGMA
#define GLUT_NO_WARNING_DISABLE

#include "winopengl.h"
#include <stdlib.h>
#include <GL/glu.h>



winopengl::winopengl()
{
    angle_quad = 0.0f;
    angle_triang = 0.0f;
    quadrado_z = -2.0f;
    triangulo_z = -2.0f;
}

void winopengl::initializeGL(){
    //glClearColor(0.1f, 1.0f, 0.0f, 0.0f); //Atribui o Verde para ser pintado
    //glClearColor(0, 0, 0, 0.0f); //Atribui o Preto para ser pintado
    //glClearColor(1, 1, 1, 0.0f); //Atribui o Branco para ser pintado
    //glClear(GL_COLOR_BUFFER_BIT); //Pinta o fundo previamente definido acima

    glMatrixMode(GL_PROJECTION);
    //Define uma projeçao paralela ortográfica
    //gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
}

void winopengl::paintGL(){
    glClearColor(0.1f, 1.0f, 0.0f, 0.0f); //Atribui o Verde para ser pintado
    glClearColor(1, 1, 1, 0.0f);

    //limpa a janela de visualizaçao com a cor
    //de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    //glPushMatrix();

    //define a posiçao do triângulo nos eixos x, y e z
    glTranslatef(triangulo_x, triangulo_y, triangulo_z);
    //realiza o giro no triângulo e define em qual eixo será este giro
    glRotatef(angle_triang, 0.0f, 1.0f, 0.0f);

    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.25f, 0.5f);
    glEnd();

    glLoadIdentity();
    //define a posiçao do quadrado nos eixos x, y e z
    glTranslatef(quadrado_x, quadrado_y, quadrado_z);
    //realiza o giro no quadrado e define em qual eixo será este giro
    glRotatef(angle_quad, 0.0f, 1.0f, 0.0f);

    //Altera a cor do quadrado para
    glColor3f(0.2f, 0.2f, 1.0f);
    //Desenha o triangulo invertido
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();

    //Executa os comandos OpenGL
    glFlush();
}

void winopengl::resizeGL(int w, int h){    

    glViewport(0,0,w,h);

    glMatrixMode   ( GL_PROJECTION );  // Select The Projection Matrix
    glLoadIdentity ( );                // Reset The Projection Matrix - Traz a camera para o ponto central da tela
    if ( h==0 )  // Calculate The Aspect Ratio Of The Window
        gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
    else
        gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
    glMatrixMode ( GL_MODELVIEW );  // Select The Model View Matrix
    glLoadIdentity ( );
}

void winopengl::keyPressEvent(QKeyEvent *event){
    //qDebug() << Qt::Key_Z;

    switch (event->key()) {

    case Qt::Key_Left:
        angle_quad += 0.5f;
        break;

    case Qt::Key_Right:
        angle_quad -= 0.5f;
        break;

    case Qt::Key_Up:
        angle_triang += 0.5f;
        break;

    case Qt::Key_Down:
        angle_triang -= 0.5f;
        break;

    case Qt::Key_A:
        triangulo_x -= 0.5f;
        break;

    case Qt::Key_D:
        triangulo_x += 0.5f;
        break;

    case Qt::Key_W:
        triangulo_y += 0.5f;
        break;

    case Qt::Key_S:
        triangulo_y -= 0.5f;
        break;

    case Qt::Key_Z:
        triangulo_z += 0.5f;
        break;

    case Qt::Key_X:
        triangulo_z -= 0.5f;
        break;

    case Qt::Key_J:
        quadrado_x -= 0.5f;
        break;

    case Qt::Key_L:
        quadrado_x += 0.5f;
        break;

    case Qt::Key_I:
        quadrado_y += 0.5f;
        break;

    case Qt::Key_K:
        quadrado_y -= 0.5f;
        break;

    case Qt::Key_N:
        quadrado_z += 0.5f;
        break;

    case Qt::Key_M:
        quadrado_z -= 0.5f;
        break;

    }
    updateGL();
}

void winopengl::mouseMoveEvent(QMouseEvent *event){


}



