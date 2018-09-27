/**
 * \file Labs/1/source.c
 * 
 * \brief Computer graphics course Lab 1 variant 62
 * 
 * \details 
 * 1. Изобразить каркасный чайник  и каркасную сферу. 
 * 2. Выполнить сдвиг двух примитивов: чайник на dx=50, сферу на dy= -30.
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
#include <GL/freeglut.h> 
#include <GL/gl.h>

void renderFunction() 
{ 
glClearColor(0.0, 0.0, 0.0, 0.0); 
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(1.0, 1.0, 1.0); 
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
glBegin(GL_TRIANGLES); 
glVertex2f(-0.5, -0.5); 
glVertex2f(-0.5, 0.5); 
glVertex2f(0.5, 0.5); 
glEnd(); 
glFlush(); 
} 

int main(int argc, char** argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE); 
glutInitWindowSize(500,500); 
glutInitWindowPosition(100,100); 
glutCreateWindow("Lab1"); 
glutDisplayFunc(renderFunction); 
glutMainLoop(); 
return 0; 
}
