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


int moving = 0;
int dx = 50;
int dy = 30;

void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
    
    gluLookAt(0.0, 3.0, -2.5, // Положение глаз, взгляд "из"
              0.0, 0.2, -6.0, // Цель, взгляд "на"
              0.0, 1.0, 0.0); // Пока игнорируем

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 

void display(void)
{ 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch (moving)
    {
        case 1:
        {
            glPushMatrix();
            glTranslated(0.0 - dx, 1.2, -6.0);
            glutWireTeapot(0.6);
            glPopMatrix(); 

            glPushMatrix();
            glTranslated(0.0, -1.2, -6.0);
            glutWireSphere(0.7, 16, 16);
            glPopMatrix(); 
            
            break;
        }

        case 2:
        {
            glPushMatrix();
            glTranslated(0.0, 1.2, -6.0);
            glutWireTeapot(0.6);
            glPopMatrix(); 

            glPushMatrix();
            glTranslated(0.0, -1.2 + dy, -6.0);
            glutWireSphere(0.7, 16, 16);
            glPopMatrix(); 
            
            break;
        }     

        case 3:
        {
            glPushMatrix();
            glTranslated(0.0 + dx, 1.2, -6.0);
            glutWireTeapot(0.6);
            glPopMatrix(); 

            glPushMatrix();
            glTranslated(0.0, -1.2, -6.0);
            glutWireSphere(0.7, 16, 16);
            glPopMatrix(); 
            
            break;
        }   

        case 4:
        {
            glPushMatrix();
            glTranslated(0.0, 1.2, -6.0);
            glutWireTeapot(0.6);
            glPopMatrix(); 

            glPushMatrix();
            glTranslated(0.0, -1.2 - dy, -6.0);
            glutWireSphere(0.7, 16, 16);
            glPopMatrix(); 
            
            break;
        }        

    }

    glutSwapBuffers();
} 

void normalKeyboard(unsigned char key, int x, int y);

void specialKeyboard(int key, int x, int y);

/* Program entry point */ 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,840);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 

    glutCreateWindow("Lab1"); 

    glutDisplayFunc(display); 
    glutReshapeFunc(resize);

    glutKeyboardFunc(normalKeyboard);
    glutSpecialFunc(specialKeyboard);

    glutPostRedisplay();

    glutMainLoop(); 

    return EXIT_SUCCESS;
}

void normalKeyboard(unsigned char key, int x, int y)
{
	const char ESCAPE = '\033';

	if (key == ESCAPE)
	{
		exit(0);
	}
}

void specialKeyboard(int key, int x, int y)
{
    moving = 0;

    switch(moving)
    {
        case GLUT_KEY_LEFT:
             moving = 1;
             break;
        case GLUT_KEY_UP:
             moving = 2;
             break;
        case GLUT_KEY_RIGHT:
             moving = 3;
             break;
        case GLUT_KEY_DOWN:            
             moving = 4;
             break;
    }

    glutPostRedisplay();
}