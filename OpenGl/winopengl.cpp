#include "winopengl.h"
#include <GL/glu.h>

winopengl::winopengl()
{
}
    void winopengl::initializeGL(){
         glClearColor(0.1f, 1.0f, 0.0f, 0.0f); //Verde
        //glClearColor(0, 0, 0, 0.0f); //Preto
        //glClearColor(1, 1, 1, 0.0f); //Branco

        glMatrixMode(GL_PROJECTION);
        glClearColor(-1.0, 1.0, -1.0, 1.0);

        glMatrixMode(GL_MODELVIEW);
    }


    void winopengl::paintGL(){
        //glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //O f quer dizer que é float
        glClearColor(0.1f, 1.0f, 0.0f, 0.0f); //Verde

        //limpa a janela de visualizaçao com a cor
        //de fundo definida previamente
        glClear(GL_COLOR_BUFFER_BIT);

        //Altera a cor do desenho para azul
        ///glColor3f(0.0f, 0.0f, 1.0f);
        //Desenha o triangulo
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.5f, -0.5f, 0.f);
        glVertex3f(0.0f, 0.5f, 0.f);
        glVertex3f(0.5f, -0.5f, 0.f);
        glEnd();
    /*
        //Altera a cor do desenho para azul do 2º triângulo
        glColor3f(0.5f, 0.5f, 1.0f);
        //Desenha o triangulo invertido
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.5f, 0.f);
        glVertex3f(1.0f, 0.5f, 0.f);
        glVertex3f(0.5f, -0.5f, 0.f);
        glEnd();
    */
        //Altera a cor do quadrado para
        //glColor3f(0.4f, 0.7f, 1.0f);
        //Desenha o triangulo invertido
        //glBegin(GL_QUADS);
        //glVertex3f(0.5f, 0.5f, 0.0f);
        //glVertex3f( 0.5f, -0.5f, 0.0f);
        //glVertex3f( 0.8f,0.5f, 0.0f);
        //glVertex3f(0.8f,-0.5f, 0.0f);
        //glEnd();

        //Executa os comandos OpenGL
        //glFlush();
    }

    void winopengl:: resizeGL(int w, int h){
        /*
        glViewport(0,0,w,h);

        glMatrixMode   ( GL_PROJECTION );  // Select The Projection Matrix
        glLoadIdentity ( );                // Reset The Projection Matrix
        if ( h==0 )  // Calculate The Aspect Ratio Of The Window
           gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
        else
           gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
        glMatrixMode   ( GL_MODELVIEW );  // Select The Model View Matrix
        glLoadIdentity ( );
    */


    }


