#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include "imageloader.h"
#include "imageloader.cpp"
 
static int angleCyl = 0, angleSphere = 0; 

GLfloat mat_specular[] = {255.0, 255.0, 255.0, 1.0}, 
        mat_shininess[] = {10.0},
        light_position[] = {0.0, 10.0, 10.0, 10.0},
        white_light[] = {1.0, 1.0, 1.0, 1.0};
                
        
GLfloat spot_direction[] = {-1.0, -1.0, 0.0};

GLuint _textureId;

GLuint loadTexture(Image* image) {

	GLuint textureId;
	glGenTextures(1, &textureId); 
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels); 
	return textureId;
} 

void  display(void) { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    mat_shininess[0] = 100.0;
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
  
    //shine cone
    glPushMatrix();
        mat_shininess[0] = 10.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        //glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
        //glColor3f(1, 0, 0);
       
        
        glRotatef((GLfloat)angleCyl, 0.0, 0.0, 1.0);
        glTranslatef(10.0, 10.0, 0.0);
		glutSolidTeapot(10.0);
        //glutSolidCone (10.0, 15.0, 50, 30);
        
        glDisable(GL_BLEND); 
    glPopMatrix();

    //transparent sphere
    glPushMatrix();
    glColor4f(0, 1, 0, 0.5);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            
        glRotatef((GLfloat)angleSphere, 1.0, 0.0, 0.0);
        glTranslatef(10.0, 10.0, 15.0);
        glutSolidSphere (10.0, 10, 10); 
        
        glDisable(GL_BLEND);
    glPopMatrix(); 
    
    //banana cube
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId);
        
        
        glColor3f(1, 1, 1);
        glTranslatef(20, 20, 0);
        
        //top
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 0, 20);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 20, 20);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(20, 20, 20);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(20, 0, 20);
        
        glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 20, 0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 20, 20);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(20, 20, 20);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(20, 20, 0);
        
        glTexCoord2f(0.0, 0.0);
        glVertex3f(20, 0, 0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(20, 0, 20);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(20, 20, 20);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(20, 20, 0);
        
        
        glEnd();
        glDisable(GL_TEXTURE_2D); 
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
      case 'f':
      	light_position[0] += 5;
      	light_position[1] += 5;
      	light_position[2] += 5;
        break;
      case 'g':
      	light_position[0] -= 5;
      	light_position[1] -= 5;
      	light_position[2] -= 5; 
        break;  	
      case 'j':
      	mat_specular[0] = 1.0;
      	mat_specular[1] = 1.0;
      	mat_specular[2] = 0.0;
      	mat_specular[3] = 1.0;
        glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);
        break;
      case 'k':
      	mat_specular[0] = 0.0;
      	mat_specular[1] = 1.0;
      	mat_specular[2] = 0.0;
      	mat_specular[3] = 1.0;
        glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);
        break;
      case 'l':
      	mat_specular[0] = 1.0;
      	mat_specular[1] = 1.0;
      	mat_specular[2] = 1.0;
      	mat_specular[3] = 1.0;
        glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);
        break;
      case 'q':
        exit(0);
        break;
      default: 
        break; 
   } 
   glutPostRedisplay(); 
} 


void init(void) { 
   
  glClearColor(1.0,1.0,1.0,1.0); 
    
  glShadeModel(GL_SMOOTH); 
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glLightfv(GL_LIGHT0,GL_EMISSION,white_light); 
  
  Image* image = loadBMP("Banana.bmp");
    _textureId = loadTexture(image);
    delete image;
   
} 


int main(int argc, char ** argv) {

    glutInit(&argc, argv);    
 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(250, 40);
    glutCreateWindow(argv[0]);   
    glMatrixMode(GL_PROJECTION);
    glOrtho(-50, 50, -50, 50, -50, 50);
    init();
    glutDisplayFunc(display); 
    gluLookAt(10, 10, 10, 
            0, 0, 0,
            0, 0, 1);
    glutKeyboardFunc(keyboard); 
 
    glutMainLoop();
    return 0;
    
}
