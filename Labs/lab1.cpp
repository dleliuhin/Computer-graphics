#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
 
static int angleCyl = 0, angleSphere = 0;  

void  display(void) { 

    glColor3f(1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT); 
    glPushMatrix();
        glRotatef((GLfloat)angleCyl, 0.0, 0.0, 1.0);
        glTranslatef(10.0, 10.0, 0.0);
        glutWireCone (10.0, 15.0, 20, 1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0, 1, 0);
        glRotatef((GLfloat)angleSphere, 1.0, 0.0, 0.0);
        glTranslatef(10.0, 10.0, 15.0);
        glutWireSphere (5.0, 10, 10); 
    glPopMatrix(); 
    
	glPushMatrix();
		glColor3f(0, 0, 1);
		glTranslatef(30, 30, 0);
		glutWireCube (5); 
	glPopMatrix();
		
	glPushMatrix();
		glColor3f(0, 1, 1);
		glTranslatef(32.5, 32.5, 2.5);
   	    glutSolidSphere(1, 10, 10);
  glPopMatrix();

  glutSwapBuffers();
    
}

void keyboard(unsigned char key,int x, int y) 
{ 
   switch(key) 
   { 
      case 's': 
        angleCyl = (angleCyl - 180) % 360; 
        glutPostRedisplay(); 
        break;
      case 'a':
        angleSphere = (angleSphere + 45) % 360; 
        glutPostRedisplay(); 
        break;
    case 'q':
        exit(0);
        break;
      default: 
        break; 
   } 
} 

int main(int argc, char ** argv) {

    glutInit(&argc, argv);    
 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(250, 40);
    glutCreateWindow(argv[0]);   
    glMatrixMode(GL_PROJECTION);
    glOrtho(-50, 50, -50, 50, -50, 50);
    glutDisplayFunc(display); 
    gluLookAt(10, 10, 10, 
            0, 0, 0,
            0, 0, 1);
    glutKeyboardFunc(keyboard); 
 
    glutMainLoop();
    return 0;
    
}
