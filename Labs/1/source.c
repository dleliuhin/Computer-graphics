/**
 * \file Labs/1/source.c
 * 
 * \brief Computer graphics course Lab 1 variant 62
 * 
 * \details 
 * 1. Изобразить каркасный чайник  и каркасную сферу. 
  * 2. Выполнить сдвиг двух примитивов: чайник на dx = 50, сферу на dy = -30.
 * 3. Изобразить тетраэдр и конус.
 * 4. Осуществить сдвиг одного из примитивов таким образом, чтобы выполнить пересечение примитивов.
 * 
 * \author Leliuhin Dmitrii
 * 
 * \version 1.0
 * 
 * \date $Date: 27/10/2018 02:47:20 $ 
 * 
 * Contact: dleliuhin@mail.ru
 * 
 * Created on: 23/10/2018
 */

#include <stdlib.h>
#include <stdio.h>
//#include <GL/freeglut.h> 
//#include <GL/gl.h>
#include <GL/glut.h> 
#include <math.h>

float dx = 5;
float dy = -3;
int task = 0;

void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);


    gluLookAt(0.0, 5.0, 5.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0); 


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    switch (task) {
        
    case 1: {

        glPushMatrix();
        glTranslated(0.0, 0.0, 0.0);
        glutWireTeapot(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-5.0, 0.0, 0.0);
        glutWireSphere(1.0, 16, 16);
        glPopMatrix();


        break;
    }
            
    case 2: {
        glPushMatrix();
        glTranslated( dx, 0.0, 0.0);
        glutWireTeapot(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-5.0, dy, 0.0);
        glutWireSphere(1.0, 16, 16);
        glPopMatrix();
        
        break;
    }
            
    case 3: {

        glPushMatrix();
        glTranslated(-5, 0.0, 0.0);
        //glRotated(10, 1, 0, 0);
        glScalef(2, 2, 2);
        glutWireTetrahedron();
        glPopMatrix();

        glPushMatrix();
        
        glutWireCone(1.5,1.5,50,50);
        glPopMatrix();


        break;

    }
            
    case 4: {

        glPushMatrix();
        //glTranslated(-5, 0.0, 0.0);
        //glRotated(10, 1, 0, 0);
        glScalef(2, 2, 2);
        glutWireTetrahedron();
        glPopMatrix();

        glPushMatrix();

        glutWireCone(1.5, 1.5, 50, 50);
        glPopMatrix();
    }

    }

    glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y) {

    task = 0;

    switch (key) {

    case GLUT_KEY_RIGHT:

        task = 1;

        break;

    case GLUT_KEY_LEFT:

        task = 2;

        break;

    case GLUT_KEY_UP:

        task = 3;

        break;

    case GLUT_KEY_DOWN:

        task = 4;

        break;

    }
    glutPostRedisplay();


}

void processNormalKeys(unsigned char key, int x, int y)
{

    if (key == 27)

        exit(0);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Lab1");

    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutPostRedisplay();

    glutMainLoop();

    return EXIT_SUCCESS;
}