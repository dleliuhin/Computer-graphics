#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints[4][4][3] = {
   {{-1.5, -1.5, 0.0}, {-0.5, -1.5, 0.0},
    {0.5, -1.5, 0.0}, {1.5, -1.5, 0.0}},
   {{-1.5, -0.5, 0.0}, {-0.5, -0.5, 0.0},
    {0.5, -0.5, 0.0}, {1.5, -0.5, 0.0}},
   {{-1.5, 0.5, 0.0}, {-0.5, 0.5, 0.0},
    {0.5, 0.5, 0.0}, {1.5, 0.5, 0.0}},
   {{-1.5, 1.5, 0.0}, {-0.5, 1.5, 0.0},
    {0.5, 1.5, 0.0}, {1.5, 1.5, 0.0}}
};

static void idle(void)
{
    glutPostRedisplay();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
             ctrlpoints[3][3][2] -= 0.1;
             ctrlpoints[3][2][2] -= 0.1;
             ctrlpoints[3][1][2] -= 0.1;
             ctrlpoints[3][0][2] -= 0.1;

             ctrlpoints[3][3][1] -= 0.2;
             ctrlpoints[3][2][1] -= 0.2;
             ctrlpoints[3][1][1] -= 0.2;
             ctrlpoints[3][0][1] -= 0.2;

             ctrlpoints[0][3][1] -= 0.2;
             ctrlpoints[0][2][1] -= 0.2;
             ctrlpoints[0][1][1] -= 0.2;
             ctrlpoints[0][0][1] -= 0.2;
             
             ctrlpoints[0][3][2] -= 0.1;
             ctrlpoints[0][2][2] -= 0.1;
             ctrlpoints[0][1][2] -= 0.1;
             ctrlpoints[0][0][2] -= 0.1;

            break;

        case '-':
            ctrlpoints[3][3][2] += 0.1;
             ctrlpoints[3][2][2] += 0.1;
             ctrlpoints[3][1][2] += 0.1;
             ctrlpoints[3][0][2] += 0.1;

             ctrlpoints[3][3][1] += 0.2;
             ctrlpoints[3][2][1] += 0.2;
             ctrlpoints[3][1][1] += 0.2;
             ctrlpoints[3][0][1] += 0.2;

             ctrlpoints[0][3][1] += 0.2;
             ctrlpoints[0][2][1] += 0.2;
             ctrlpoints[0][1][1] += 0.2;
             ctrlpoints[0][0][1] += 0.2;

             ctrlpoints[0][3][2] += 0.1;
             ctrlpoints[0][2][2] += 0.1;
             ctrlpoints[0][1][2] += 0.1;
             ctrlpoints[0][0][2] += 0.1;
            break;
    }

    float fraction = 0.1f;


    glutPostRedisplay();
}


void initlights(void)
{
   GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
   GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
   GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
   GLfloat mat_specular[] = {1.0, 0.0, 0.0, 1.0};
   GLfloat mat_shininess[] = {50.0};

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0,0.3,0);
   glPushMatrix();
   glRotatef(85.0, 1.0, 1.0, 1.0);
   ctrlpoints[2][2][2];
   glEvalMesh2(GL_FILL, 0, 20, 0, 20);
   glPopMatrix();
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &ctrlpoints[0][0][0]);
   glEnable(GL_MAP2_VERTEX_3);
   glEnable(GL_AUTO_NORMAL);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
   glFlush();
}

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &ctrlpoints[0][0][0]);
   glEnable(GL_MAP2_VERTEX_3);
   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_COLOR_MATERIAL);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
   initlights();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
               5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
   else
      glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
               5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(key);
   glutIdleFunc(idle);
   glutMainLoop();
   return 0;
}
