#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#endif
#include <stdlib.h>
#define PI 3.1415927

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xtrans = 0.0f;
float ytrans = 0.0f;
float ztrans = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Hizkia Christanto - 672019016");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.662, 0.937, 0.933,0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
}

void bangunankanan(){
    glBegin(GL_LINE_LOOP);
        //depan dari kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(150.0, -150.0, 20.0);
    glVertex3f(150.0, 135.0, 20.0);
    glVertex3f(150.0, 135.0, 0.0);
    glVertex3f(150.0, -150.0, 0.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -150.0, 0.0);
    glVertex3f(150.0, 135.0, 0.0);
    glVertex3f(150.0, 135.0,  -20.0);
    glVertex3f(150.0, -150.0, -20.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(150.0, -150.0, -20.0);
    glVertex3f(150.0, 135.0, -20.0);
    glVertex3f(150.0, 135.0, -40.0);
    glVertex3f(150.0, -150.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -150.0, -40.0);
    glVertex3f(150.0, 135.0, -40.0);
    glVertex3f(150.0, 135.0,  -80.0);
    glVertex3f(150.0, -150.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -150.0, 40.0);
    glVertex3f(150.0, 135.0, 40.0);
    glVertex3f(150.0, 135.0, 20.0);
    glVertex3f(150.0, -150.0, 20.0);
    glEnd();

    //tembok tulisan aeon
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(50.0, -150.0, 40.0);
    glVertex3f(50.0, 150.0, 40.0);
    glVertex3f(150.0, 150.0, 40.0);
    glVertex3f(150.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(70.0, -10.0, 40.1);
    glVertex3f(70.0, 180.0, 40.1);
    glVertex3f(150.0, 180.0, 40.1);
    glVertex3f(150.0, -10.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(150.1, -10.0, 30);
    glVertex3f(150.1, 180.0, 30);
    glVertex3f(150.1, 180.0, 40.1);
    glVertex3f(150.1, -10.0, 40.1);
    glEnd();

    //bagian 1
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-150.0, 90.0, 40.0);
    glVertex3f(-150.0, 140.0, 40.0);
    glVertex3f(50.0, 140.0, 40.0);
    glVertex3f(50.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-220.0, 120.0, 40.0);
    glVertex3f(-220.0, 140.0, 40.0);
    glVertex3f(-150.0, 140.0, 40.0);
    glVertex3f(-150.0, 120.0, 40.0);
    glEnd();
 	glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-220.0, -150.0, 40.0);
    glVertex3f(-220.0, -40.0, 40.0);
    glVertex3f(-150.0, -40.0, 40.0);
    glVertex3f(-150.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(-270.0, 140.0, 40.0);
    glVertex3f(-220.0, 140.0, 40.0);
    glVertex3f(-220.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(50.0, 90.0, 40.0);
    glVertex3f(50.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-60.0, -150.0, 40.0);
    glVertex3f(-60.0, 50.0, 40.0);
    glVertex3f(50.0, 50.0, 40.0);
    glVertex3f(50.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-130.0, -150.0, 40.0);
    glVertex3f(-130.0, 50.0, 40.0);
    glVertex3f(-60.0, 50.0, 40.0);
    glVertex3f(-60.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, 30.0, 40.0);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-130.0, 50.0, 40.0);
    glVertex3f(-130.0, 30.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-150.0, 0.0, 40.0);
    glVertex3f(-150.0, 30.0, 40.0);
    glVertex3f(-130.0, 30.0, 40.0);
    glVertex3f(-130.0, 0.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, 0.0, 40.0);
    glVertex3f(-270.0, 30.0, 40.0);
    glVertex3f(-220.0, 30.0, 40.0);
    glVertex3f(-220.0, 0.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-270.0, 0.0, 40.0);
    glVertex3f(-130.0, 0.0, 40.0);
    glVertex3f(-130.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-150.0, -150.0, 40.0);
    glVertex3f(-150.0, -20.0, 40.0);
    glVertex3f(-130.0, -20.0, 40.0);
    glVertex3f(-130.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, -150.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-220.0, -20.0, 40.0);
    glVertex3f(-220.0, -150.0, 40.0);
    glEnd();

    //bagian 2
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 120.0, 40.0);
    glVertex3f(-430.0, 135.0, 40.0);
    glVertex3f(-270.0, 135.0, 40.0);
    glVertex3f(-270.0, 120.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-350.0, 120.0, 40.0);
    glVertex3f(-345.0, 120.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glVertex3f(-345.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-345.0, 80.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(-270.0, 80.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, -150.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-345.0, -20.0, 40.0);
    glVertex3f(-345.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-345.0, -150.0, 40.0);
    glVertex3f(-345.0, -40.0, 40.0);
    glVertex3f(-270.0, -40.0, 40.0);
    glVertex3f(-270.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-275.0, -150.0, 40.0);
    glVertex3f(-275.0, -20.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-270.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-430.0, 120.0, 40.0);
    glVertex3f(-425.0, 120.0, 40.0);
    glVertex3f(-425.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, 80.0, 40.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-350.0, 80.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, 50.0, 40.0);
    glVertex3f(-430.0, 80.0, 40.0);
    glVertex3f(-425.0, 80.0, 40.0);
    glVertex3f(-425.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -20.0, 40.0);
    glVertex3f(-430.0, 50.0, 40.0);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -150.0, 40.0);
    glVertex3f(-430.0, -20.0, 40.0);
    glVertex3f(-425.0, -20.0, 40.0);
    glVertex3f(-425.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-355.0, -150.0, 40.0);
    glVertex3f(-355.0, -20.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-350.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -150.0, 40.0);
    glVertex3f(-430.0, -40.0, 40.0);
    glVertex3f(-350.0, -40.0, 40.0);
    glVertex3f(-350.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -150.0, 20.0);
    glVertex3f(-430.0, 90.0, 20.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-430.0, -150.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 90.0, 20.0);
    glVertex3f(-430.0, 135.0, 20.0);
    glVertex3f(-430.0, 135.0, 40.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glEnd();

}

void gariskaca(){
     //garis garis kaca besar
    	glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, 120.0, 40.0);
		glVertex3f(-220.0, 120.0, 40.0);
		glVertex3f(-220.0, 90.0, 40.0);
		glVertex3f(-150.0, 90.0, 40.0);
		glEnd();
		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, 90.0, 40.0);
		glVertex3f(-210.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 90.0, 40.0);
		glVertex3f(-200.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, 90.0, 40.0);
		glVertex3f(-190.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 90.0, 40.0);
		glVertex3f(-180.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, 90.0, 40.0);
		glVertex3f(-170.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 90.0, 40.0);
		glVertex3f(-160.0, 120.0, 40.0);
		glEnd();

    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, 30.0, 40.0);
		glVertex3f(-220.0, 30.0, 40.0);
		glVertex3f(-220.0, 0.0, 40.0);
		glVertex3f(-150.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, -20.0, 40.0);
		glVertex3f(-220.0, -20.0, 40.0);
		glVertex3f(-220.0, -40.0, 40.0);
		glVertex3f(-150.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-270.0, 120.0, 40.0);
		glVertex3f(-345.0, 120.0, 40.0);
		glVertex3f(-345.0, 90.0, 40.0);
		glVertex3f(-270.0, 90.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-270.0, 80.0, 40.0);
		glVertex3f(-345.0, 80.0, 40.0);
		glVertex3f(-345.0, 50.0, 40.0);
		glVertex3f(-270.0, 50.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-275.0, -20.0, 40.0);
		glVertex3f(-345.0, -20.0, 40.0);
		glVertex3f(-345.0, -40.0, 40.0);
		glVertex3f(-275.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-355.0, -20.0, 40.0);
		glVertex3f(-425.0, -20.0, 40.0);
		glVertex3f(-425.0, -40.0, 40.0);
		glVertex3f(-355.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-350.0, 80.0, 40.0);
		glVertex3f(-425.0, 80.0, 40.0);
		glVertex3f(-425.0, 50.0, 40.0);
		glVertex3f(-350.0, 50.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-350.0, 120.0, 40.0);
		glVertex3f(-425.0, 120.0, 40.0);
		glVertex3f(-425.0, 90.0, 40.0);
		glVertex3f(-350.0, 90.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, 30.0, 40.0);
		glVertex3f(-210.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 30.0, 40.0);
		glVertex3f(-200.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, 30.0, 40.0);
		glVertex3f(-190.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 30.0, 40.0);
		glVertex3f(-180.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, 30.0, 40.0);
		glVertex3f(-170.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 30.0, 40.0);
		glVertex3f(-160.0, 0.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, -20.0, 40.0);
		glVertex3f(-210.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, -20.0, 40.0);
		glVertex3f(-200.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, -20.0, 40.0);
		glVertex3f(-190.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, -20.0, 40.0);
		glVertex3f(-180.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, -20.0, 40.0);
		glVertex3f(-170.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, -20.0, 40.0);
		glVertex3f(-160.0, -40.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, 90.0, 40.0);
		glVertex3f(-330.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, 90.0, 40.0);
		glVertex3f(-320.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, 90.0, 40.0);
		glVertex3f(-310.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 90.0, 40.0);
		glVertex3f(-300.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, 90.0, 40.0);
		glVertex3f(-290.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 90.0, 40.0);
		glVertex3f(-280.0, 120.0, 40.0);
		glEnd();

			glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, 50.0, 40.0);
		glVertex3f(-330.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, 50.0, 40.0);
		glVertex3f(-320.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, 50.0, 40.0);
		glVertex3f(-310.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 50.0, 40.0);
		glVertex3f(-300.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, 50.0, 40.0);
		glVertex3f(-290.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 50.0, 40.0);
		glVertex3f(-280.0, 80.0, 40.0);
		glEnd();

			glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, -20.0, 40.0);
		glVertex3f(-330.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, -20.0, 40.0);
		glVertex3f(-320.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, -20.0, 40.0);
		glVertex3f(-310.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, -20.0, 40.0);
		glVertex3f(-300.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, -20.0, 40.0);
		glVertex3f(-290.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, -20.0, 40.0);
		glVertex3f(-280.0, -40.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, 90.0, 40.0);
		glVertex3f(-410.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 90.0, 40.0);
		glVertex3f(-400.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, 90.0, 40.0);
		glVertex3f(-390.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 90.0, 40.0);
		glVertex3f(-380.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, 90.0, 40.0);
		glVertex3f(-370.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 90.0, 40.0);
		glVertex3f(-360.0, 120.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, 50.0, 40.0);
		glVertex3f(-410.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 50.0, 40.0);
		glVertex3f(-400.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, 50.0, 40.0);
		glVertex3f(-390.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 50.0, 40.0);
		glVertex3f(-380.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, 50.0, 40.0);
		glVertex3f(-370.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 50.0, 40.0);
		glVertex3f(-360.0, 80.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, -20.0, 40.0);
		glVertex3f(-410.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, -20.0, 40.0);
		glVertex3f(-400.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, -20.0, 40.0);
		glVertex3f(-390.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, -20.0, 40.0);
		glVertex3f(-380.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, -20.0, 40.0);
		glVertex3f(-370.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, -20.0, 40.0);
		glVertex3f(-360.0, -40.0, 40.0);
		glEnd();
}

void jendelakotak3(){
    //kaca yang kotak 3
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-130.0, 100.0, 40.1);
    glVertex3f(-130.0, 120.0, 40.1);
    glVertex3f(-110.0, 120.0, 40.1);
    glVertex3f(-110.0, 100.0, 40.1);
    glEnd();
        glLineWidth(2);
    glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
    glVertex3f(-130.0, 100.0, 40.1);
    glVertex3f(-130.0, 120.0, 40.1);
    glVertex3f(-110.0, 120.0, 40.1);
    glVertex3f(-110.0, 100.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-100.0, 100.0, 40.1);
    glVertex3f(-100.0, 120.0, 40.1);
    glVertex3f(-80.0, 120.0, 40.1);
    glVertex3f(-80.0, 100.0, 40.1);
    glEnd();
    glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-100.0, 100.0, 40.1);
    glVertex3f(-100.0, 120.0, 40.1);
    glVertex3f(-80.0, 120.0, 40.1);
    glVertex3f(-80.0, 100.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-70.0, 100.0, 40.1);
    glVertex3f(-70.0, 120.0, 40.1);
    glVertex3f(-50.0, 120.0, 40.1);
    glVertex3f(-50.0, 100.0, 40.1);
    glEnd();
    glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
    glVertex3f(-70.0, 100.0, 40.1);
    glVertex3f(-70.0, 120.0, 40.1);
    glVertex3f(-50.0, 120.0, 40.1);
    glVertex3f(-50.0, 100.0, 40.1);
    glEnd();
}

void bagian_tengah(){
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-900.0, 120.0, 20.0);
    glVertex3f(-430.0, 120.0, 20.0);
    glVertex3f(-430.0, 135.0, 20.0);
    glVertex3f(-900.0, 135.0, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-900.0, -150.0, 20.0);
    glVertex3f(-430.0, -150.0, 20.0);
    glVertex3f(-430.0, 50.0, 20.0);
    glVertex3f(-900.0, 50.0, 20.0);
    glEnd();
}

void jendelagaris_kiritengah(){
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-900.0, 50.0, 20.0);
    glVertex3f(-850.0, 50.0, 20.0);
    glVertex3f(-850.0, 120.0, 20.0);
    glVertex3f(-900.0, 120.0, 20.0);
    glEnd();
    
    //garis jendela kiri tengah
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-890.0, 50.0, 20.0);
    glVertex3f(-890.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-880.0, 50.0, 20.0);
    glVertex3f(-880.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-870.0, 50.0, 20.0);
    glVertex3f(-870.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-860.0, 50.0, 20.0);
    glVertex3f(-860.0, 120.0, 20.0);
    glEnd();
    
    //lantai kiri
   glBegin(GL_QUADS);
   	glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1100.0, -150.0, 200.1);
    glVertex3f(-1100.0, -150.0, 70.1);
    glVertex3f(-1600.0, -150.0, 70.1);
    glVertex3f(-1600.0, -150.0, 200.1);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1100.0, -150.0, 70.0);
    glVertex3f(-500.0, -150.0, -80.0);
    glVertex3f(-1200.0, -150.0, -80.0);
    glVertex3f(-1600.0, -150.0, 70.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, -150.0, 40.0);
    glVertex3f(-430.0, -150.0, -80.0);
    glVertex3f(150.0, -150.0, -80.0);
    glVertex3f(150.0, -150.0, 40.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-900.0, -150.0, 20.0);
    glVertex3f(-500.0, -150.0, -80.0);
    glVertex3f(-430.0, -150.0, -80.0);
    glVertex3f(-430.0, -150.0, 20.0);
    glEnd();
    
}

void jendelagaris_kanantengah(){
	//Jendela kanan
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, 20.0);
    glVertex3f(-430.0, 50.0, 20.0);
    glVertex3f(-430.0, 90.0, 20.0);
    glVertex3f(-530.0, 90.0, 20.0);
    glEnd();
    
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, 20.0);
    glVertex3f(-430.0, 90.0, 20.0);
    glVertex3f(-430.0, 120.0, 20.0);
    glVertex3f(-530.0, 120.0, 20.0);
    glEnd();
    
    //garis jendela kanan tengah
   	glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-520.0, 50.0, 20.0);
    glVertex3f(-520.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-510.0, 50.0, 20.0);
    glVertex3f(-510.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-500.0, 50.0, 20.0);
    glVertex3f(-500.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-490.0, 50.0, 20.0);
    glVertex3f(-490.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-480.0, 50.0, 20.0);
    glVertex3f(-480.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-470.0, 50.0, 20.0);
    glVertex3f(-470.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-460.0, 50.0, 20.0);
    glVertex3f(-460.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-450.0, 50.0, 20.0);
    glVertex3f(-450.0, 120.0, 20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-440.0, 50.0, 20.0);
    glVertex3f(-440.0, 120.0, 20.0);
    
    glEnd();
}

void jendelahitam_tengah(){
	//jendela hitam tengah
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, 20.0);
    glVertex3f(-530.0, 50.0, 20.0);
    glVertex3f(-530.0, 90.0, 20.0);
    glVertex3f(-850.0, 90.0, 20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, 20.0);
    glVertex3f(-850.0, 50.0, 40.0);
    glVertex3f(-850.0, 90.0, 40.0);
    glVertex3f(-850.0, 90.0, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, 20.0);
    glVertex3f(-530.0, 50.0, 40.0);
    glVertex3f(-530.0, 90.0, 40.0);
    glVertex3f(-530.0, 90.0, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 40.0);
    glVertex3f(-530.0, 90.0, 40.0);
    glVertex3f(-530.0, 90.0,20.0);
    glVertex3f(-850.0, 90.0,20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, 40.0);
    glVertex3f(-530.0, 50.0, 40.0);
    glVertex3f(-530.0, 50.0, 20.0);
    glVertex3f(-850.0, 50.0, 20.0);
    glEnd();
    
    //garis-garis jendela hitam
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-840.0, 50.0, 40.0);
    glVertex3f(-840.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-830.0, 50.0, 40.0);
    glVertex3f(-830.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-820.0, 50.0, 40.0);
    glVertex3f(-820.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-810.0, 50.0, 40.0);
    glVertex3f(-810.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-800.0, 50.0, 40.0);
    glVertex3f(-800.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-790.0, 50.0, 40.0);
    glVertex3f(-790.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-780.0, 50.0, 40.0);
    glVertex3f(-780.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-770.0, 50.0, 40.0);
    glVertex3f(-770.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-760.0, 50.0, 40.0);
    glVertex3f(-760.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-750.0, 50.0, 40.0);
    glVertex3f(-750.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-740.0, 50.0, 40.0);
    glVertex3f(-740.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-730.0, 50.0, 40.0);
    glVertex3f(-730.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-720.0, 50.0, 40.0);
    glVertex3f(-720.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-710.0, 50.0, 40.0);
    glVertex3f(-710.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-700.0, 50.0, 40.0);
    glVertex3f(-700.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-690.0, 50.0, 40.0);
    glVertex3f(-690.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-680.0, 50.0, 40.0);
    glVertex3f(-680.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-670.0, 50.0, 40.0);
    glVertex3f(-670.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-660.0, 50.0, 40.0);
    glVertex3f(-660.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-650.0, 50.0, 40.0);
    glVertex3f(-650.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-640.0, 50.0, 40.0);
    glVertex3f(-640.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-630.0, 50.0, 40.0);
    glVertex3f(-630.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-620.0, 50.0, 40.0);
    glVertex3f(-620.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-610.0, 50.0, 40.0);
    glVertex3f(-610.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-600.0, 50.0, 40.0);
    glVertex3f(-600.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-590.0, 50.0, 40.0);
    glVertex3f(-590.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-580.0, 50.0, 40.0);
    glVertex3f(-580.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-570.0, 50.0, 40.0);
    glVertex3f(-570.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-560.0, 50.0, 40.0);
    glVertex3f(-560.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-550.0, 50.0, 40.0);
    glVertex3f(-550.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-540.0, 50.0, 40.0);
    glVertex3f(-540.0, 90.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, 40.0);
    glVertex3f(-530.0, 90.0, 40.0);
    glEnd();
}

void pembatas_jendela(){
	 
    //pembatas tengah jendela
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 20.0);
    glVertex3f(-530.0, 90.0, 20.0);
    glVertex3f(-530.0, 120.0, 20.0);
    glVertex3f(-850.0, 120.0, 20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 20.0);
    glVertex3f(-850.0, 90.0, 40.0);
    glVertex3f(-850.0, 120.0, 40.0);
    glVertex3f(-850.0, 120.0, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, 20.0);
    glVertex3f(-530.0, 90.0, 40.0);
    glVertex3f(-530.0, 120.0, 40.0);
    glVertex3f(-530.0, 120.0, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 120.0, 40.0);
    glVertex3f(-530.0, 120.0, 40.0);
    glVertex3f(-530.0, 120.0,20.0);
    glVertex3f(-850.0, 120.0,20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 40.0);
    glVertex3f(-530.0, 90.0, 40.0);
    glVertex3f(-530.0, 90.0, 20.0);
    glVertex3f(-850.0, 90.0, 20.0);
    glEnd();
}

void bagianatas_pembatasjendela(){
	//garis atas tengah (bagian atas) pembatas jendela
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-840.0, 90.0, 40.0);
    glVertex3f(-840.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-830.0, 90.0, 40.0);
    glVertex3f(-830.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-820.0, 90.0, 40.0);
    glVertex3f(-820.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-810.0, 90.0, 40.0);
    glVertex3f(-810.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-800.0, 90.0, 40.0);
    glVertex3f(-800.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-790.0, 90.0, 40.0);
    glVertex3f(-790.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-780.0, 90.0, 40.0);
    glVertex3f(-780.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-770.0, 90.0, 40.0);
    glVertex3f(-770.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-760.0, 90.0, 40.0);
    glVertex3f(-760.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-750.0, 90.0, 40.0);
    glVertex3f(-750.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-740.0, 90.0, 40.0);
    glVertex3f(-740.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-730.0, 90.0, 40.0);
    glVertex3f(-730.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-720.0, 90.0, 40.0);
    glVertex3f(-720.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-710.0, 90.0, 40.0);
    glVertex3f(-710.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-700.0, 90.0, 40.0);
    glVertex3f(-700.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-690.0, 90.0, 40.0);
    glVertex3f(-690.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-680.0, 90.0, 40.0);
    glVertex3f(-680.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-670.0, 90.0, 40.0);
    glVertex3f(-670.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-660.0, 90.0, 40.0);
    glVertex3f(-660.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-650.0, 90.0, 40.0);
    glVertex3f(-650.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-640.0, 90.0, 40.0);
    glVertex3f(-640.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-630.0, 90.0, 40.0);
    glVertex3f(-630.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-620.0, 90.0, 40.0);
    glVertex3f(-620.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-610.0, 90.0, 40.0);
    glVertex3f(-610.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-600.0, 90.0, 40.0);
    glVertex3f(-600.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-590.0, 90.0, 40.0);
    glVertex3f(-590.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-580.0, 90.0, 40.0);
    glVertex3f(-580.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-570.0, 90.0, 40.0);
    glVertex3f(-570.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-560.0, 90.0, 40.0);
    glVertex3f(-560.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-550.0, 90.0, 40.0);
    glVertex3f(-550.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-540.0, 90.0, 40.0);
    glVertex3f(-540.0, 120.0, 40.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, 40.0);
    glVertex3f(-530.0, 120.0, 40.0);
    glEnd();
}

void bagian_serong(){
    /*glBegin(GL_QUADS);
    glColor3f(0.811, 0.882, 0.890);
    glVertex3f(-900.0, -150.0, 20.0);
    glVertex3f(-900.0, 135.0, 20.0);
    glVertex3f(-1100.0, 135.0, 70.0);
    glVertex3f(-1100.0, -150.0, 70.0);
    glEnd();*/
    
    glBegin(GL_QUADS); //kanan setelah pintu
    glColor3f(0.811, 0.882, 0.890);
    glVertex3f(-900.0, -150.0, 20.0);
    glVertex3f(-900.0, 135.0, 20.0);
    glVertex3f(-950.0, 135.0, 30.0);
    glVertex3f(-950.0, -150.0, 30.0);
    glEnd();
    
    glBegin(GL_QUADS); // atasnya pintu 
   	glColor3f(0.811, 0.882, 0.890);
    glVertex3f(-950.0, -80.0, 30.0);
    glVertex3f(-950.0, 135.0, 30.0);
    glVertex3f(-1050.0, 135.0, 60.0);
    glVertex3f(-1050.0, -80.0, 60.0);
    glEnd();
    
      glBegin(GL_QUADS); // pintu kanan
   	glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-950.0, -150.0, 30.0);
    glVertex3f(-950.0, -80.0, 30.0);
    glVertex3f(-1000.0, -80.0, 45.0);
    glVertex3f(-1000.0, -150.0, 45.0);
    glEnd();
    
     glBegin(GL_QUADS); // pintu kiri
   	glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1025.0, -150.0, 30.0);
    glVertex3f(-1025.0, -80.0, 30.0);
    glVertex3f(-1050.0, -80.0, 60.0);
    glVertex3f(-1050.0, -150.0, 60.0);
    glEnd();
    
    glBegin(GL_QUADS); //kiri sebelum pintu
    glColor3f(0.811, 0.882, 0.890);
    glVertex3f(-1050.0, -150.0, 60.0);
    glVertex3f(-1050.0, 135.0, 60.0);
    glVertex3f(-1100.0, 135.0, 70.0);
    glVertex3f(-1100.0, -150.0, 70.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.811, 0.882, 0.890);
    glVertex3f(-1200.0, -150.0, -80.0);
    glVertex3f(-1200.0, 135.0, -80.0);
    glVertex3f(-1600.0, 135.0, 70.0);
    glVertex3f(-1600.0, -150.0, 70.0);
    glEnd();
    
    
}

void bagian_belakang(){
	    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -150.0, -80.0);
    glVertex3f(150.0, 135.0, -80.0);
    glVertex3f(-1200.0, 135.0, -80.0);
    glVertex3f(-1200.0, -150.0, -80.0);
    glEnd();
}

void knopi(){
    glBegin(GL_QUADS);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-430.0, -50.0, 40.0);
    glVertex3f(-430.0, -50.0, 60.0);
    glVertex3f(50.0, -50.0, 60.0);
    glVertex3f(50.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-480.0, -50.0, 40.0);
    glVertex3f(-480.0, -50.0, 60.0);
    glVertex3f(-430.0, -50.0, 60.0);
    glVertex3f(-430.0, -50.0, 40.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-900.0, -50.0, 40.0);
    glVertex3f(-900.0, -50.0, 20.0);
    glVertex3f(-430.0, -50.0, 20.0);
    glVertex3f(-430.0, -50.0, 40.0);
    glEnd();
}

void bangunankiri(){
    glBegin(GL_QUADS);//sisi kanan
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1100.0, -150.0, 70.0);
    glVertex3f(-1100.0, 135.0, 70.0);
    glVertex3f(-1100.0, 135.0, 130.0);
    glVertex3f(-1100.0, -150.0, 130.0);
    glEnd();
        glBegin(GL_QUADS);//sisi kanan
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1100.0, -150.0, 180.0);
    glVertex3f(-1100.0, 135.0, 180.0);
    glVertex3f(-1100.0, 135.0, 200.0);
    glVertex3f(-1100.0, -150.0, 200.0);
    glEnd();
    	glBegin(GL_QUADS);//sisi kanan
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1100.0, -150.0, 130.0);
    glVertex3f(-1100.0, -30.0, 130.0);
    glVertex3f(-1100.0, -30.0, 180.0);
    glVertex3f(-1100.0, -150.0, 180.0);
    glEnd();
    	glBegin(GL_QUADS);//sisi kanan
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1100.0, 80.0, 130.0);
    glVertex3f(-1100.0, 135.0, 130.0);
    glVertex3f(-1100.0, 135.0, 180.0);
    glVertex3f(-1100.0, 80.0, 180.0);
    glEnd();

    glBegin(GL_QUADS);//sisi depan
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1100.0, -150.0, 200.0);
    glVertex3f(-1100.0, 135.0, 200.0);
    glVertex3f(-1250.0, 135.0, 200.0);
    glVertex3f(-1250.0, -150.0, 200.0);
    glEnd();

}

void jendela_kiri(){
	//kiri
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 80.0, 140.0);
    glVertex3f(-1100.0, -30.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 80.0, 150.0);
    glVertex3f(-1100.0, -30.0, 150.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 80.0, 160.0);
    glVertex3f(-1100.0, -30.0, 160.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 80.0, 170.0);
    glVertex3f(-1100.0, -30.0, 170.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 80.0, 180.0);
    glVertex3f(-1100.0, -30.0, 180.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1100.0, 20.0, 130.0);
    glVertex3f(-1100.0, 20.0, 180.0);
    glEnd();
    
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1250.0, -80.0, 200.0);
    glVertex3f(-1250.0, 20.0, 200.0);
    glVertex3f(-1600.0, 20.0, 200.0);
    glVertex3f(-1600.0, -80.0, 200.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1600.0, -80.0, 160.0);
    glVertex3f(-1600.0, 20.0, 160.0);
    glVertex3f(-1600.0, 20.0, 200.0);
    glVertex3f(-1600.0, -80.0, 200.0);
    glEnd();
    
    //garis jendela
    glLineWidth(2);
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1270.0, 20.0, 200.1);
    glVertex3f(-1270.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1290.0, 20.0, 200.1);
    glVertex3f(-1290.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1310.0, 20.0, 200.1);
    glVertex3f(-1310.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1330.0, 20.0, 200.1);
    glVertex3f(-1330.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1350.0, 20.0, 200.1);
    glVertex3f(-1350.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1370.0, 20.0, 200.1);
    glVertex3f(-1370.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1390.0, 20.0, 200.1);
    glVertex3f(-1390.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1410.0, 20.0, 200.1);
    glVertex3f(-1410.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1430.0, 20.0, 200.1);
    glVertex3f(-1430.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1450.0, 20.0, 200.1);
    glVertex3f(-1450.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1470.0, 20.0, 200.1);
    glVertex3f(-1470.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1490.0, 20.0, 200.1);
    glVertex3f(-1490.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1510.0, 20.0, 200.1);
    glVertex3f(-1510.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1530.0, 20.0, 200.1);
    glVertex3f(-1530.0, -80.0, 200.1);
    glEnd();    
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1550.0, 20.0, 200.1);
    glVertex3f(-1550.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1570.0, 20.0, 200.1);
    glVertex3f(-1570.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1590.0, 20.0, 200.1);
    glVertex3f(-1590.0, -80.0, 200.1);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, 20.0, 190.0);
    glVertex3f(-1600.0, -80.0, 190.0);
    glEnd();
        glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, 20.0, 180.0);
    glVertex3f(-1600.0, -80.0, 180.0);
    glEnd();
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, 20.0, 170.0);
    glVertex3f(-1600.0, -80.0, 170.0);
    glEnd();
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, -10.0, 160.0);
    glVertex3f(-1600.0, -10.0, 200.0);
    glEnd();
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1250.0, -10.0, 200.1);
    glVertex3f(-1600.0, -10.0, 200.1);
    glEnd();
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, -40.0, 160.0);
    glVertex3f(-1600.0, -40.0, 200.0);
    glEnd();
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1250.0, -40.0, 200.1);
    glVertex3f(-1600.0, -40.0, 200.1);
    glEnd();
    
    
    //tembok hitam
        glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1250.0, 20.0, 200.0);
    glVertex3f(-1250.0, 135.0, 200.0);
    glVertex3f(-1600.0, 135.0, 200.0);
    glVertex3f(-1600.0, 20.0, 200.0);
    glEnd();
            glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1250.0, -150.0, 200.0);
    glVertex3f(-1250.0, -80.0, 200.0);
    glVertex3f(-1600.0, -80.0, 200.0);
    glVertex3f(-1600.0, -150.0, 200.0);
    glEnd();
    	glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1600.0, 100.0, 150.0);
    glVertex3f(-1600.0, 20.0, 150.0);
    glVertex3f(-1600.0, 20.0, 170.0);
    glVertex3f(-1600.0, 100.0, 170.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1600.0, 20.0, 150.0);
    glVertex3f(-1600.0, -150.0, 150.0);
    glVertex3f(-1600.0, -150.0, 160.0);
    glVertex3f(-1600.0, 20.0, 160.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1600.0, -80.0, 150.0);
    glVertex3f(-1600.0, -150.0, 150.0);
    glVertex3f(-1600.0, -150.0, 200.0);
    glVertex3f(-1600.0, -80.0, 200.0);
    glEnd();
    
    	glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, -150.0, 130.0);
    glVertex3f(-1600.0, 135.0, 130.0);
    glVertex3f(-1600.0, 135.0, 150.0);
    glVertex3f(-1600.0, -150.0, 150.0);
    glEnd();
    
        glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1600.0, -150.0, 120.0);
    glVertex3f(-1600.0, 135.0, 120.0);
    glVertex3f(-1600.0, 135.0, 130.0);
    glVertex3f(-1600.0, -150.0, 130.0);
    glEnd();
    
    	glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-1600.0, 70.0, 70.0);
    glVertex3f(-1600.0, 135.0, 70.0);
    glVertex3f(-1600.0, 135.0, 120.0);
    glVertex3f(-1600.0, 70.0, 120.0);
    glEnd();
    
        glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, -150.0, 110.0);
    glVertex3f(-1600.0, 70.0, 110.0);
    glVertex3f(-1600.0, 70.0, 120.0);
    glVertex3f(-1600.0, -150.0, 120.0);
    glEnd();
    
        glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, 20.0, 70.0);
    glVertex3f(-1600.0, 70.0, 70.0);
    glVertex3f(-1600.0, 70.0, 110.0);
    glVertex3f(-1600.0, 20.0, 110.0);
    glEnd();
    
        glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, -50.0, 70.0);
    glVertex3f(-1600.0, -70.0, 70.0);
    glVertex3f(-1600.0, -70.0, 110.0);
    glVertex3f(-1600.0, -50.0, 110.0);
    glEnd();
            glBegin(GL_QUADS);//sisi kiri
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, -120.0, 70.0);
    glVertex3f(-1600.0, -150.0, 70.0);
    glVertex3f(-1600.0, -150.0, 110.0);
    glVertex3f(-1600.0, -120.0, 110.0);
    glEnd();
    
    //jendela paling kiri
            glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, -120.0, 100.0);
    glVertex3f(-1600.0, 20.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, -120.0, 90.0);
    glVertex3f(-1600.0, 20.0, 90.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-1600.0, -120.0, 80.0);
    glVertex3f(-1600.0, 20.0, 80.0);
    glEnd();
    
    //tulisan aeon bagian kiri
        glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(-1550.0, 20.0, 200.1);
    glVertex3f(-1550.0, 135.0, 200.1);
    glVertex3f(-1600.1, 135.0, 200.1);
    glVertex3f(-1600.1, 20.0, 200.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(-1600.1, 20.0, 170.0);
    glVertex3f(-1600.1, 135.0, 170.0);
    glVertex3f(-1600.1, 135.0, 200.0);
    glVertex3f(-1600.1, 20.0, 200.0);
    glEnd();
}

void pitatasbangunankiri(){
    glBegin(GL_QUADS);//sisi kanan
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1099.9, 100.0, 70.0);
    glVertex3f(-1099.9, 135.0, 70.0);
    glVertex3f(-1099.9, 135.0, 200.0);
    glVertex3f(-1099.9, 100.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);//sisi depan
   	glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1100.0, 100.0, 200.1);
    glVertex3f(-1100.0, 135.0, 200.1);
    glVertex3f(-1550.0, 135.0, 200.1);
    glVertex3f(-1550.0, 100.0, 200.1);
    glEnd();
    
    glBegin(GL_QUADS);
   	glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1600.0, 100.0, 150.0);
    glVertex3f(-1600.0, 135.0, 150.0);
    glVertex3f(-1600.0, 135.0, 170.0);
    glVertex3f(-1600.0, 100.0, 170.0);
    glEnd();
}

void kanopikiri(){
    glBegin(GL_QUADS);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-1060.0, -50.0, 130.0);
    glVertex3f(-1100.0, -50.0, 120.0);
    glVertex3f(-1100.1, -50.0, 190.0);
    glVertex3f(-1060.1, -50.0, 190.0);
    glEnd();
    
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1150.0, -90.0, 210.0);
    glVertex3f(-1150.0, -90.0, 200.0);
    glVertex3f(-1430.0, -90.0, 200.0);
    glVertex3f(-1430.0, -90.0, 210.0);
    glEnd();
            glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1170.0, -90.0, 220.0);
    glVertex3f(-1170.0, -90.0, 210.0);
    glVertex3f(-1410.0, -90.0, 210.0);
    glVertex3f(-1410.0, -90.0, 220.0);
    glEnd();
}

void atap(){
	glBegin(GL_QUADS);
   	glColor3f(0.905, 0.874, 0.874);
    glVertex3f(-1100.0, 135.0, 200.1);
    glVertex3f(-1100.0, 135.0, 70.1);
    glVertex3f(-1600.0, 135.0, 70.1);
    glVertex3f(-1600.0, 135.0, 200.1);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.717, 0.717);
    glVertex3f(-1100.0, 135.0, 70.0);
    glVertex3f(-500.0, 135.0, -80.0);
    glVertex3f(-1200.0, 135.0, -80.0);
    glVertex3f(-1600.0, 135.0, 70.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.717, 0.717);
    glVertex3f(-430.0, 135.0, 40.0);
    glVertex3f(-430.0, 135.0, -80.0);
    glVertex3f(150.0, 135.0, -80.0);
    glVertex3f(150.0, 135.0, 40.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.717, 0.717);
    glVertex3f(-900.0, 135.0, 20.0);
    glVertex3f(-500.0, 135.0, -80.0);
    glVertex3f(-430.0, 135.0, -80.0);
    glVertex3f(-430.0, 135.0, 20.0);
    glEnd();
}


void kaca_atap(){
	//garis depan
		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-120.0, 170.0, 10.0);
		glVertex3f(-120.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-140.0, 170.0, 10.0);
		glVertex3f(-140.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 170.0, 10.0);
		glVertex3f(-160.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 170.0, 10.0);
		glVertex3f(-180.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 170.0, 10.0);
		glVertex3f(-200.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-240.0, 170.0, 10.0);
		glVertex3f(-240.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-260.0, 170.0, 10.0);
		glVertex3f(-260.0, 135.0, 10.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 170.0, 10.0);
		glVertex3f(-280.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 170.0, 10.0);
		glVertex3f(-300.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-340.0, 170.0, 10.0);
		glVertex3f(-340.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 170.0, 10.0);
		glVertex3f(-360.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 170.0, 10.0);
		glVertex3f(-380.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 170.0, 10.0);
		glVertex3f(-400.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-420.0, 170.0, 10.0);
		glVertex3f(-420.0, 135.0, 10.0);
		glEnd();	
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-460.0, 170.0, 10.0);
		glVertex3f(-460.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-480.0, 170.0, 10.0);
		glVertex3f(-480.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-500.0, 170.0, 10.0);
		glVertex3f(-500.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-520.0, 170.0, 10.0);
		glVertex3f(-520.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-560.0, 170.0, 10.0);
		glVertex3f(-560.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-580.0, 170.0, 10.0);
		glVertex3f(-580.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-600.0, 170.0, 10.0);
		glVertex3f(-600.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-620.0, 170.0, 10.0);
		glVertex3f(-620.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-640.0, 170.0, 10.0);
		glVertex3f(-640.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-680.0, 170.0, 10.0);
		glVertex3f(-680.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-700.0, 170.0, 10.0);
		glVertex3f(-700.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-720.0, 170.0, 10.0);
		glVertex3f(-720.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-740.0, 170.0, 10.0);
		glVertex3f(-740.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-780.0, 170.0, 10.0);
		glVertex3f(-780.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-800.0, 170.0, 10.0);
		glVertex3f(-800.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-820.0, 170.0, 10.0);
		glVertex3f(-820.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-840.0, 170.0, 10.0);
		glVertex3f(-840.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-860.0, 170.0, 10.0);
		glVertex3f(-860.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-900.0, 170.0, 10.0);
		glVertex3f(-900.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-920.0, 170.0, 10.0);
		glVertex3f(-920.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-940.0, 170.0, 10.0);
		glVertex3f(-940.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-960.0, 170.0, 10.0);
		glVertex3f(-960.0, 135.0, 10.0);
		glEnd();
		
		//serong
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1000.0, 170.0, 10.0);
		glVertex3f(-1000.0, 135.0, 10.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1020.0, 170.0, 15.0);
		glVertex3f(-1020.0, 135.0, 15.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1055.0, 170.0, 25.0);
		glVertex3f(-1055.0, 135.0, 25.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1075.0, 170.0, 30.0);
		glVertex3f(-1075.0, 135.0, 30.0);
		glEnd();
		
		//garis belakang
		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-120.0, 170.0, -30.0);
		glVertex3f(-120.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-140.0, 170.0, -30.0);
		glVertex3f(-140.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 170.0, -30.0);
		glVertex3f(-160.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 170.0, -30.0);
		glVertex3f(-180.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 170.0, -30.0);
		glVertex3f(-200.0, 135.0, -30.0);
		glEnd();
		
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-240.0, 170.0, -30.0);
		glVertex3f(-240.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-260.0, 170.0, -30.0);
		glVertex3f(-260.0, 135.0, -30.0);
		glEnd();
		    glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 170.0, -30.0);
		glVertex3f(-280.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 170.0, -30.0);
		glVertex3f(-300.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-340.0, 170.0, -30.0);
		glVertex3f(-340.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 170.0, -30.0);
		glVertex3f(-360.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 170.0, -30.0);
		glVertex3f(-380.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 170.0, -30.0);
		glVertex3f(-400.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-420.0, 170.0, -30.0);
		glVertex3f(-420.0, 135.0, -30.0);
		glEnd();	
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-460.0, 170.0, -30.0);
		glVertex3f(-460.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-480.0, 170.0, -30.0);
		glVertex3f(-480.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-500.0, 170.0, -30.0);
		glVertex3f(-500.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-520.0, 170.0, -30.0);
		glVertex3f(-520.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-560.0, 170.0, -30.0);
		glVertex3f(-560.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-580.0, 170.0, -30.0);
		glVertex3f(-580.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-600.0, 170.0, -30.0);
		glVertex3f(-600.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-620.0, 170.0, -30.0);
		glVertex3f(-620.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-640.0, 170.0, -30.0);
		glVertex3f(-640.0, 135.0, -30.0);
		glEnd();
		
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-680.0, 170.0, -30.0);
		glVertex3f(-680.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-700.0, 170.0, -30.0);
		glVertex3f(-700.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-720.0, 170.0, -30.0);
		glVertex3f(-720.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-740.0, 170.0, -30.0);
		glVertex3f(-740.0, 135.0, -30.0);
		glEnd();
		
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-780.0, 170.0, -30.0);
		glVertex3f(-780.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-800.0, 170.0, -30.0);
		glVertex3f(-800.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-820.0, 170.0, -30.0);
		glVertex3f(-820.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-840.0, 170.0, -30.0);
		glVertex3f(-840.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-860.0, 170.0, -30.0);
		glVertex3f(-860.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-900.0, 170.0, -30.0);
		glVertex3f(-900.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-920.0, 170.0, -30.0);
		glVertex3f(-920.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-940.0, 170.0, -30.0);
		glVertex3f(-940.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-960.0, 170.0, -30.0);
		glVertex3f(-960.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1000.0, 170.0, -30.0);
		glVertex3f(-1000.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1020.0, 170.0, -30.0);
		glVertex3f(-1020.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1040.0, 170.0, -30.0);
		glVertex3f(-1040.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1060.0, 170.0, -30.0);
		glVertex3f(-1060.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1080.0, 170.0, -30.0);
		glVertex3f(-1080.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1120.0, 170.0, -30.0);
		glVertex3f(-1120.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1140.0, 170.0, -30.0);
		glVertex3f(-1140.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1160.0, 170.0, -30.0);
		glVertex3f(-1160.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1180.0, 170.0, -30.0);
		glVertex3f(-1180.0, 135.0, -30.0);
		glEnd();
			glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-1200.0, 170.0, -30.0);
		glVertex3f(-1200.0, 135.0, -30.0);
		glEnd();
}
void diatas_atap(){
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(80.0, 170.0, 40.0);
    glVertex3f(80.0, 170.0, -20.0);
    glVertex3f(80.0, 135.0, -20.0);
    glVertex3f(80.0, 135.0, 40.0);
    glEnd();
    	glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(80.0, 170.0, -20.0);
    glVertex3f(150.0, 170.0, -20.0);
    glVertex3f(150.0, 135.0, -20.0);
    glVertex3f(80.0, 135.0, -20.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, 170.0, 30.0);
    glVertex3f(150.0, 170.0, -20.0);
    glVertex3f(150.0, 135.0, -20.0);
    glVertex3f(150.0, 135.0, 30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.721, 0.717, 0.717);
    glVertex3f(150.0, 170.0, 40.0);
    glVertex3f(150.0, 170.0, -20.0);
    glVertex3f(70.0, 170.0, -20.0);
    glVertex3f(70.0, 170.0, 40.0);
    glEnd();
   
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-100.0, 170.0, 10.0);
    glVertex3f(-100.0, 170.0, -30.0);
    glVertex3f(-100.0, 135.0, -30.0);
    glVertex3f(-100.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-100.0, 145.0, 10.0);
    glVertex3f(-1000.0, 145.0, 10.0);
    glVertex3f(-1000.0, 135.0, 10.0);
    glVertex3f(-100.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1000.0, 145.0, 10.0);
    glVertex3f(-1100.0, 145.0,40.0);
    glVertex3f(-1100.0, 135.0,40.0);
    glVertex3f(-1000.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-100.0, 145.0, -30.0);
    glVertex3f(-1200.0, 145.0, -30.0);
    glVertex3f(-1200.0, 135.0, -30.0);
    glVertex3f(-100.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1200.0, 145.0, -30.0);
    glVertex3f(-1400.0, 145.0, 20.0);
    glVertex3f(-1400.0, 135.0, 20.0);
    glVertex3f(-1200.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-1100.0, 170.0, 40.0);
    glVertex3f(-1400.0, 170.0, 20.0);
    glVertex3f(-1400.0, 135.0, 20.0);
    glVertex3f(-1100.0, 135.0, 40.0);
    glEnd();
    
    //depan
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-210.0, 170.0, 10.0);
    glVertex3f(-220.0, 170.0, 10.0);
    glVertex3f(-220.0, 135.0, 10.0);
    glVertex3f(-210.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-320.0, 170.0, 10.0);
    glVertex3f(-330.0, 170.0, 10.0);
    glVertex3f(-330.0, 135.0, 10.0);
    glVertex3f(-320.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-430.0, 170.0, 10.0);
    glVertex3f(-440.0, 170.0, 10.0);
    glVertex3f(-440.0, 135.0, 10.0);
    glVertex3f(-430.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-540.0, 170.0, 10.0);
    glVertex3f(-550.0, 170.0, 10.0);
    glVertex3f(-550.0, 135.0, 10.0);
    glVertex3f(-540.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-650.0, 170.0, 10.0);
    glVertex3f(-660.0, 170.0, 10.0);
    glVertex3f(-660.0, 135.0, 10.0);
    glVertex3f(-650.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-760.0, 170.0, 10.0);
    glVertex3f(-770.0, 170.0, 10.0);
    glVertex3f(-770.0, 135.0, 10.0);
    glVertex3f(-760.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-870.0, 170.0, 10.0);
    glVertex3f(-880.0, 170.0, 10.0);
    glVertex3f(-880.0, 135.0, 10.0);
    glVertex3f(-870.0, 135.0, 10.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-980.0, 170.0, 10.0);
    glVertex3f(-990.0, 170.0, 10.0);
    glVertex3f(-990.0, 135.0, 10.0);
    glVertex3f(-980.0, 135.0, 10.0);
    glEnd();
    
    //belakang
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-210.0, 170.0, -30.0);
    glVertex3f(-220.0, 170.0, -30.0);
    glVertex3f(-220.0, 135.0, -30.0);
    glVertex3f(-210.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-320.0, 170.0, -30.0);
    glVertex3f(-330.0, 170.0, -30.0);
    glVertex3f(-330.0, 135.0, -30.0);
    glVertex3f(-320.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-430.0, 170.0, -30.0);
    glVertex3f(-440.0, 170.0, -30.0);
    glVertex3f(-440.0, 135.0, -30.0);
    glVertex3f(-430.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-540.0, 170.0, -30.0);
    glVertex3f(-550.0, 170.0, -30.0);
    glVertex3f(-550.0, 135.0, -30.0);
    glVertex3f(-540.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-650.0, 170.0, -30.0);
    glVertex3f(-660.0, 170.0, -30.0);
    glVertex3f(-660.0, 135.0, -30.0);
    glVertex3f(-650.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-760.0, 170.0, -30.0);
    glVertex3f(-770.0, 170.0, -30.0);
    glVertex3f(-770.0, 135.0, -30.0);
    glVertex3f(-760.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-870.0, 170.0, -30.0);
    glVertex3f(-880.0, 170.0, -30.0);
    glVertex3f(-880.0, 135.0, -30.0);
    glVertex3f(-870.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-980.0, 170.0, -30.0);
    glVertex3f(-990.0, 170.0, -30.0);
    glVertex3f(-990.0, 135.0, -30.0);
    glVertex3f(-980.0, 135.0, -30.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1090.0, 170.0, -30.0);
    glVertex3f(-1100.0, 170.0, -30.0);
    glVertex3f(-1100.0, 135.0, -30.0);
    glVertex3f(-1090.0, 135.0, -30.0);
    glEnd();
    
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1035.0, 170.0, 20.0);
    glVertex3f(-1050.0, 170.0, 25.0);
    glVertex3f(-1050.0, 135.0, 25.0);
    glVertex3f(-1035.0, 135.0, 20.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1320.0, 170.0, 0.0);
    glVertex3f(-1305.0, 170.0, -5.0);
    glVertex3f(-1305.0, 135.0, -5.0);
    glVertex3f(-1320.0, 135.0, 0.0);
    glEnd();

	//atap penutup
	glBegin(GL_QUADS);
    glColor3f(0.741, 0.756, 0.756);
    glVertex3f(-1000.0, 170.0, 10.0);
    glVertex3f(-1200.0, 170.0, -30.0);
    glVertex3f(-100.0, 170.0, -30.0);
    glVertex3f(-100.0, 170.0, 10.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.741, 0.756, 0.756);
    glVertex3f(-1400.0, 170.0, 20.0);
    glVertex3f(-1200.0, 170.0, -30.0);
    glVertex3f(-1000.0, 170.0, 10.0);
    glVertex3f(-1100.0, 170.0, 40.0);
    glEnd();
    
    //penutup yg ijo
    //depan
     glBegin(GL_QUADS);
    glColor3f(0.580, 0.956, 0.839);
    glVertex3f(-100.0, 170.0, 9.9);
    glVertex3f(-1000.0, 170.0, 9.9);
    glVertex3f(-1000.0, 145.0, 9.9);
    glVertex3f(-100.0, 145.0, 9.9);
    glEnd();
    
        glBegin(GL_QUADS);
    glColor3f(0.580, 0.956, 0.839);
    glVertex3f(-1000.9, 170.0, 10.0);
    glVertex3f(-1100.9, 170.0,40.0);
    glVertex3f(-1100.9, 145.0,40.0);
    glVertex3f(-1000.9, 145.0, 10.0);
    glEnd();
    
    //belakang
         glBegin(GL_QUADS);
    glColor3f(0.580, 0.956, 0.839);
    glVertex3f(-100.0, 170.0, -30.1);
    glVertex3f(-1200.0, 170.0, -30.1);
    glVertex3f(-1200.0, 145.0, -30.1);
    glVertex3f(-100.0, 145.0, -30.1);
    glEnd();
         glBegin(GL_QUADS);
    glColor3f(0.580, 0.956, 0.839);
    glVertex3f(-1200.0, 170.0, -30.1);
    glVertex3f(-1400.0, 170.0, 20.1);
    glVertex3f(-1400.0, 145.0, 20.1);
    glVertex3f(-1200.0, 145.0, -30.1);
    glEnd();
}
void parkiran(){   
    glBegin(GL_QUADS);
    glColor3f(0.478, 0.458, 0.458);
    glVertex3f(-1000.0, -150.0, 60.0);
    glVertex3f(30.0, -150.0, 60.0);
    glVertex3f(30.0, -150.0, 200.0);
    glVertex3f(-1000.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.588, 0.584, 0.572);
    glVertex3f(-1000.0, -150.0, 60.0);
    glVertex3f(30.0, -150.0, 60.0);
    glVertex3f(30.0, -150.0, 200.0);
    glVertex3f(-1000.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-900.0, -150.0, 60.0);
    glVertex3f(-900.0, -130.0, 60.0);
    glVertex3f(-900.0, -130.0, 200.0);
    glVertex3f(-900.0, -150.0, 200.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-1000.0, -130.0, 60.0);
    glVertex3f(-900.0, -130.0, 60.0);
    glVertex3f(-900.0, -150.0, 60.0);
    glVertex3f(-1000.0, -150.0, 60.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-1000.0, -130.0, 200.0);
    glVertex3f(-900.0, -130.0, 200.0);
    glVertex3f(-900.0, -150.0, 200.0);
    glVertex3f(-1000.0, -150.0, 200.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-1000.0, -150.0, 60.0);
    glVertex3f(-1000.0, -130.0, 60.0);
    glVertex3f(-1000.0, -130.0, 200.0);
    glVertex3f(-1000.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.478, 0.713, 0.145);
    glVertex3f(-900.0, -135.0, 60.0);
    glVertex3f(-1000.0, -135.0, 60.0);
     glColor3f(0.643, 0.956, 0.203);
    glVertex3f(-1000.0, -135.0, 200.0);
    glVertex3f(-900.0, -135.0, 200.0);
    glEnd();
    
    //parkiran tengah
  glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-850.0, -150.0, 60.0);
    glVertex3f(-850.0, -130.0, 60.0);
    glVertex3f(-850.0, -130.0, 200.0);
    glVertex3f(-850.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-850.0, -130.0, 60.0);
    glVertex3f(-450.0, -130.0, 60.0);
    glVertex3f(-450.0, -150.0, 60.0);
    glVertex3f(-850.0, -150.0, 60.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-350.0, -130.0, 60.0);
    glVertex3f(-250.0, -130.0, 60.0);
    glVertex3f(-250.0, -150.0, 60.0);
    glVertex3f(-350.0, -150.0, 60.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-200.0, -130.0, 60.0);
    glVertex3f(30.0, -130.0, 60.0);
    glVertex3f(30.0, -150.0, 60.0);
    glVertex3f(-200.0, -150.0, 60.0);
    glEnd();
    
      glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(30.0, -150.0, 60.0);
    glVertex3f(30.0, -130.0, 60.0);
    glVertex3f(30.0, -130.0, 200.0);
    glVertex3f(30.0, -150.0, 200.0);
    glEnd();
    
    //parkiran depan
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-200.0, -130.0, 200.0);
    glVertex3f(30.0, -130.0, 200.0);
    glVertex3f(30.0, -150.0, 200.0);
    glVertex3f(-200.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 200.0);
    glVertex3f(-400.0, -130.0, 200.0);
    glVertex3f(-400.0, -150.0, 200.0);
    glVertex3f(-300.0, -150.0, 200.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 200.0);
    glVertex3f(-800.0, -130.0, 200.0);
    glVertex3f(-800.0, -150.0, 200.0);
    glVertex3f(-500.0, -150.0, 200.0);
    glEnd();
    
    //bagian tengah parkiran
    glBegin(GL_QUADS); //1
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 180.0);
    glVertex3f(-550.0, -130.0, 180.0);
    glVertex3f(-550.0, -140.0, 180.0);
    glVertex3f(-500.0, -140.0, 180.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 170.0);
    glVertex3f(-550.0, -130.0, 170.0);
    glVertex3f(-550.0, -140.0, 170.0);
    glVertex3f(-500.0, -140.0, 170.0);
    glEnd();
    
    glBegin(GL_QUADS); //2
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 150.0);
    glVertex3f(-550.0, -130.0, 150.0);
    glVertex3f(-550.0, -140.0, 150.0);
    glVertex3f(-500.0, -140.0, 150.0);
    glEnd();
    
    glBegin(GL_QUADS); //2
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 140.0);
    glVertex3f(-550.0, -130.0, 140.0);
    glVertex3f(-550.0, -140.0, 140.0);
    glVertex3f(-500.0, -140.0, 140.0);
    glEnd();
    
    glBegin(GL_QUADS); //3
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 120.0);
    glVertex3f(-550.0, -130.0, 120.0);
    glVertex3f(-550.0, -140.0, 120.0);
    glVertex3f(-500.0, -140.0, 120.0);
    glEnd();
    
    glBegin(GL_QUADS); //3
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 110.0);
    glVertex3f(-550.0, -130.0, 110.0);
    glVertex3f(-550.0, -140.0, 110.0);
    glVertex3f(-500.0, -140.0, 110.0);
    glEnd();
    
    glBegin(GL_QUADS); //4
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 90.0);
    glVertex3f(-550.0, -130.0, 90.0);
    glVertex3f(-550.0, -140.0, 90.0);
    glVertex3f(-500.0, -140.0, 90.0);
    glEnd();
    
    glBegin(GL_QUADS); //4
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-500.0, -130.0, 90.0);
    glVertex3f(-550.0, -130.0, 90.0);
    glVertex3f(-550.0, -140.0, 90.0);
    glVertex3f(-500.0, -140.0, 90.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 90.0);
    glVertex3f(-450.0, -130.0, 90.0);
    glVertex3f(-450.0, -140.0, 90.0);
    glVertex3f(-400.0, -140.0, 90.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 110.0);
    glVertex3f(-450.0, -130.0, 110.0);
    glVertex3f(-450.0, -140.0, 110.0);
    glVertex3f(-400.0, -140.0, 110.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 120.0);
    glVertex3f(-450.0, -130.0, 120.0);
    glVertex3f(-450.0, -140.0, 120.0);
    glVertex3f(-400.0, -140.0, 120.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 140.0);
    glVertex3f(-450.0, -130.0, 140.0);
    glVertex3f(-450.0, -140.0, 140.0);
    glVertex3f(-400.0, -140.0, 140.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 150.0);
    glVertex3f(-450.0, -130.0, 150.0);
    glVertex3f(-450.0, -140.0, 150.0);
    glVertex3f(-400.0, -140.0, 150.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 170.0);
    glVertex3f(-450.0, -130.0, 170.0);
    glVertex3f(-450.0, -140.0, 170.0);
    glVertex3f(-400.0, -140.0, 170.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-400.0, -130.0, 180.0);
    glVertex3f(-450.0, -130.0, 180.0);
    glVertex3f(-450.0, -140.0, 180.0);
    glVertex3f(-400.0, -140.0, 180.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 180.0);
    glVertex3f(-350.0, -130.0, 180.0);
    glVertex3f(-350.0, -140.0, 180.0);
    glVertex3f(-300.0, -140.0, 180.0);
    glEnd();
    
      glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 170.0);
    glVertex3f(-350.0, -130.0, 170.0);
    glVertex3f(-350.0, -140.0, 170.0);
    glVertex3f(-300.0, -140.0, 170.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 150.0);
    glVertex3f(-350.0, -130.0, 150.0);
    glVertex3f(-350.0, -140.0, 150.0);
    glVertex3f(-300.0, -140.0, 150.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 140.0);
    glVertex3f(-350.0, -130.0, 140.0);
    glVertex3f(-350.0, -140.0, 140.0);
    glVertex3f(-300.0, -140.0, 140.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 120.0);
    glVertex3f(-350.0, -130.0, 120.0);
    glVertex3f(-350.0, -140.0, 120.0);
    glVertex3f(-300.0, -140.0, 120.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 110.0);
    glVertex3f(-350.0, -130.0, 110.0);
    glVertex3f(-350.0, -140.0, 110.0);
    glVertex3f(-300.0, -140.0, 110.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-300.0, -130.0, 90.0);
    glVertex3f(-350.0, -130.0, 90.0);
    glVertex3f(-350.0, -140.0, 90.0);
    glVertex3f(-300.0, -140.0, 90.0);
    glEnd();
    
    //tengah kotak parkiran
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-200.0, -130.0, 90.0);
    glVertex3f(-225.0, -130.0, 90.0);
    glVertex3f(-225.0, -145.0, 90.0);
    glVertex3f(-200.0, -145.0, 90.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-200.0, -130.0, 170.0);
    glVertex3f(-225.0, -130.0, 170.0);
    glVertex3f(-225.0, -145.0, 170.0);
    glVertex3f(-200.0, -145.0, 170.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-200.0, -130.0, 90.0);
    glVertex3f(-200.0, -130.0, 170.0);
    glVertex3f(-200.0, -145.0, 170.0);
    glVertex3f(-200.0, -145.0, 90.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-225.0, -130.0, 90.0);
    glVertex3f(-225.0, -130.0, 170.0);
    glVertex3f(-225.0, -145.0, 170.0);
    glVertex3f(-225.0, -145.0, 90.0);
    glEnd();
    
    
     glBegin(GL_QUADS);
    glColor3f(0.576, 0.505, 0.282);
    glVertex3f(-225.0, -140.0, 90.0);
    glVertex3f(-200.0, -140.0, 90.0);
    glColor3f(0.796, 0.650, 0.203);
    glVertex3f(-200.0, -140.0, 170.0);
    glVertex3f(-225.0, -140.0, 170.0);
    glEnd();
    
    //kotak parkiran tengah 2
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-100.0, -130.0, 90.0);
    glVertex3f(-125.0, -130.0, 90.0);
    glVertex3f(-125.0, -145.0, 90.0);
    glVertex3f(-100.0, -145.0, 90.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-100.0, -130.0, 170.0);
    glVertex3f(-125.0, -130.0, 170.0);
    glVertex3f(-125.0, -145.0, 170.0);
    glVertex3f(-100.0, -145.0, 170.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-100.0, -130.0, 90.0);
    glVertex3f(-100.0, -130.0, 170.0);
    glVertex3f(-100.0, -145.0, 170.0);
    glVertex3f(-100.0, -145.0, 90.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0.776, 0.745, 0.643);
    glVertex3f(-125.0, -130.0, 90.0);
    glVertex3f(-125.0, -130.0, 170.0);
    glVertex3f(-125.0, -145.0, 170.0);
    glVertex3f(-125.0, -145.0, 90.0);
    glEnd();
    
    
     glBegin(GL_QUADS);
    glColor3f(0.576, 0.505, 0.282);
    glVertex3f(-125.0, -140.0, 90.0);
    glVertex3f(-100.0, -140.0, 90.0);
    glColor3f(0.796, 0.650, 0.203);
    glVertex3f(-100.0, -140.0, 170.0);
    glVertex3f(-125.0, -140.0, 170.0);
    glEnd();
    
}
void tv(){
	glBegin(GL_QUADS);//atas
    glColor3f(0.1,0.1,0.1);
    
    //Penyangga
    glVertex3f(-40.0, 55.0, 20.0);
    glVertex3f(-25.0 , 55.0, 20.0);
    glVertex3f(-25.0, 100.0, 20.0);
    glVertex3f(-40.0, 100.0, 20.0);
    
    glVertex3f(-40.0, 40.0, 30.0);
    glVertex3f(-25.0 , 40.0,30.0);
    glVertex3f(-25.0, 100.0, 30.0);
    glVertex3f(-40.0, 100.0, 30.0);
    
    glVertex3f(-40.0, 40.0, -10.0);
    glVertex3f(-25.0 , 40.0,-10.0);
    glVertex3f(-25.0, 40.0, 30.0);
    glVertex3f(-40.0, 40.0, 30.0);
    
    glVertex3f(-40.0, 55.0, -10.0);
    glVertex3f(-25.0 , 55.0,-10.0);
    glVertex3f(-25.0, 55.0, 20.0);
    glVertex3f(-40.0, 55.0, 20.0);
    
    glVertex3f(-40.0, 40.0, 20.0);
    glVertex3f(-40.0, 40.0, 30.0);
    glVertex3f(-40.0, 100.0, 30.0);
    glVertex3f(-40.0, 100.0, 20.0);
    
    glVertex3f(-40.0, 40.0, 20.0);
    glVertex3f(-40.0, 40.0, -10.0);
    glVertex3f(-40.0, 55.0, -10.0);
    glVertex3f(-40.0, 55.0, 20.0);
    
    glVertex3f(-25.0, 40.0, 20.0);
    glVertex3f(-25.0, 40.0, 30.0);
    glVertex3f(-25.0, 100.0, 30.0);
    glVertex3f(-25.0, 100.0, 20.0);
    
    
    //TV
    glVertex3f(-75.0, 20.0, -10.0);
    glVertex3f(0 , 20.0, -10.0);
    glVertex3f(0, 70.0, -10.0);
    glVertex3f(-75.0, 70.0, -10.0);
    
    glVertex3f(-75.0, 20.0, -13.0);
    glVertex3f(0 , 20.0, -13.0);
    glVertex3f(0, 70.0, -13.0);
    glVertex3f(-75.0, 70.0, -13.0);
    
    glVertex3f(-75.0, 20.0, -13.0);
    glVertex3f(-75 , 20.0, -10.0);
    glVertex3f(-75, 70.0, -10.0);
    glVertex3f(-75.0, 70.0, -13.0);
    
    glVertex3f(0, 20.0, -13.0);
    glVertex3f(0 , 20.0, -10.0);
    glVertex3f(0, 70.0, -10.0);
    glVertex3f(0, 70.0, -13.0);
    
    glVertex3f(-75.0, 20.0, -10.0);
    glVertex3f(0 , 20.0, -10.0);
    glVertex3f(0, 20.0, -13.0);
    glVertex3f(-75.0, 20.0, -13.0);
    
    glVertex3f(-75.0, 70.0, -10.0);
    glVertex3f(0 , 70.0, -10.0);
    glVertex3f(0, 70.0, -13.0);
    glVertex3f(-75.0, 70.0, -13.0);
    
    glColor3f(0,0,1);
    glVertex3f(-70.0, 25.0, -13.1);
    glVertex3f(-5 , 25.0, -13.1);
    glVertex3f(-7, 65.0, -13.1);
    glVertex3f(-70.0, 65.0, -13.1);
    
    glEnd();
}

void lemari(){
	glBegin(GL_QUADS);//Lemari
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-50.0, -150.0, 39.0);
    glVertex3f(-50.0 , 0.0, 39.0);
    glVertex3f(50.0, 0.0, 39.0);
    glVertex3f(50.0, -150.0, 39.0);
    
    glVertex3f(50.0, -150.0, 39.0);
    glVertex3f(50.0 , 0.0, 39.0);
    glVertex3f(50.0, 0.0, 10.0);
    glVertex3f(50.0, -150.0, 10.0);
    
    glVertex3f(-50.0, -150.0, 39.0);
    glVertex3f(-50.0 , 0.0, 39.0);
    glVertex3f(-50.0, 0.0, 10.0);
    glVertex3f(-50.0, -150.0, 10.0);
    
    glVertex3f(-50.0, 0.0, 39.0);
    glVertex3f(-50.0, 0.0, 10.0);
    glVertex3f(50.0, 0.0, 10.0);
    glVertex3f(50.0, 0.0, 39.0);
    
    glVertex3f(-50.0, -149.0, 39.0);
    glVertex3f(-50.0, -149.0, 10.0);
    glVertex3f(50.0, -149.0, 10.0);
    glVertex3f(50.0, -149.0, 39.0);
    
    glColor3f(0.7, 0.3, 0.1);
    glVertex3f(-50.0, -110.0, 39.0);
    glVertex3f(-50.0, -110.0, 15.0);
    glVertex3f(50.0, -110.0, 15.0);
    glVertex3f(50.0, -110.0, 39.0);
    
    glVertex3f(-50.0, -70.0, 39.0);
    glVertex3f(-50.0, -70.0, 15.0);
    glVertex3f(50.0, -70.0, 15.0);
    glVertex3f(50.0, -70.0, 39.0);
    
    glVertex3f(-50.0, -30.0, 39.0);
    glVertex3f(-50.0, -30.0, 15.0);
    glVertex3f(50.0, -30.0, 15.0);
    glVertex3f(50.0, -30.0, 39.0);
    
    glColor3f(0.65, 0.3, 0.1);
    glVertex3f(20.0, -150.0, 39.0);
    glVertex3f(20.0 , 0.0, 39.0);
    glVertex3f(20.0, 0.0, 15.0);
    glVertex3f(20.0, -150.0, 15.0);
    
    glVertex3f(-20.0, -150.0, 39.0);
    glVertex3f(-20.0 , 0.0, 39.0);
    glVertex3f(-20.0, 0.0, 15.0);
    glVertex3f(-20.0, -150.0, 15.0);
    
    glEnd();
}

void draw_cylinder(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	/** Draw the tube */

	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
}

void buletan(){
    glPushMatrix();//buletan bawah
    glColor3f(0.537, 0.592, 0.603);
    glTranslatef(-1035.0, -50.0, 110.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(60.0, 7.0, 235, 52,52);
    glPopMatrix();
    glFlush();

    glPushMatrix();//buletan tengah
    glColor3f(0.811, 0.882, 0.890);
    glTranslatef(-1035.0, -50.0, 110.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(55.0, 50.0, 235, 52,52);
    glPopMatrix();
    glFlush();

    glPushMatrix();// buletan atas
    glColor3f(0.537, 0.592, 0.603);
    glTranslatef(-1035.0, 0.0, 110.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(60.0, 7.0, 235, 52,52);
    glPopMatrix();
    glFlush();

    glPushMatrix(); //kiri bawah
    glTranslatef( -30.0, 3.0, -5.0);
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-990.0, -50.0, 150.0);//pivot kiri
    glVertex3f(-1000.0, -50.0, 190.0);//sudut kiri
     glVertex3f(-990.0, -50.0, 189.0);//tengah kiri
    glVertex3f(-980.0, -50.0, 188.0);//tengah
     //glVertex3f(-972.0, -50.0, 187.0);//tengah kanan
    glVertex3f(-965.0, -50.0, 180.0);//sudut kanan
    glVertex3f(-975.0, -50.0, 150.0);//pivot kanan
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix();//kiri atas
    glTranslatef( -30.0, 53.0, -5.0);
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-990.0, -50.0, 150.0);//pivot kiri
    glVertex3f(-1000.0, -50.0, 190.0);//sudut kiri
     glVertex3f(-990.0, -50.0, 189.0);//tengah kiri
    glVertex3f(-980.0, -50.0, 188.0);//tengah
     //glVertex3f(-972.0, -50.0, 187.0);//tengah kanan
    glVertex3f(-965.0, -50.0, 180.0);//sudut kanan
    glVertex3f(-975.0, -50.0, 150.0);//pivot kanan
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix(); //kanan bawah
    glRotatef(60.0, 0.0, 1.0, 0.0);
    glTranslatef( 390.0, 3.0, -940.0);
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-990.0, -50.0, 150.0);//pivot kiri
    glVertex3f(-1000.0, -50.0, 190.0);//sudut kiri
     glVertex3f(-990.0, -50.0, 189.0);//tengah kiri
    glVertex3f(-980.0, -50.0, 188.0);//tengah
     //glVertex3f(-972.0, -50.0, 187.0);//tengah kanan
    glVertex3f(-965.0, -50.0, 180.0);//sudut kanan
    glVertex3f(-975.0, -50.0, 150.0);//pivot kanan
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix(); //kanan atas
    glRotatef(60.0, 0.0, 1.0, 0.0);
    glTranslatef( 390.0, 53.0, -940.0);
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-990.0, -50.0, 150.0);//pivot kiri
    glVertex3f(-1000.0, -50.0, 190.0);//sudut kiri
     glVertex3f(-990.0, -50.0, 189.0);//tengah kiri
    glVertex3f(-980.0, -50.0, 188.0);//tengah
     //glVertex3f(-972.0, -50.0, 187.0);//tengah kanan
    glVertex3f(-965.0, -50.0, 180.0);//sudut kanan
    glVertex3f(-975.0, -50.0, 150.0);//pivot kanan
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix();//buletan bawah serong
    glColor3f(0.537, 0.592, 0.603);
    glTranslatef(-950.0, -50.0, 50.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(40.0, 1.0, 235, 52,52);
    glPopMatrix();
    glFlush();
    glPushMatrix();//buletan atas serong
    glColor3f(0.911, 0.982, 0.990);
    glTranslatef(-950.0, -50.0, 50.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(30.0, 2.0, 235, 52,52);
    glPopMatrix();
    glFlush();

    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-900.0, -50.0, 20.0);
    glVertex3f(-910.0, -50.0, 60.0);
    glVertex3f(-950.0, -50.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.592, 0.603);
    glVertex3f(-1090.0, -50.0, 30.0);
    glVertex3f(-980.0, -50.0, 70.0);
    glVertex3f(-950.0, -50.0, 35.0);
    glEnd();

}

void kursi(){
     glBegin(GL_QUADS);//depan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -90.0, -10.0);
    glVertex3f(-43.0 , -100.0, -10.0);
    glVertex3f(-18.0, -100.0, -10.0);
    glVertex3f(-18.0, -90.0, -10.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkanandepan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-18.0, -140.0, -10.0);
    glVertex3f(-18.0 , -100.0, -10.0);
    glVertex3f(-18.0, -100.0, -15.0);
    glVertex3f(-18.0, -140.0, -15.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkananblkg
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-18.0, -140.0, -30.0);
    glVertex3f(-18.0 , -100.0, -30.0);
    glVertex3f(-18.0, -100.0, -35.0);
    glVertex3f(-18.0, -140.0, -35.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiridepan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -140.0, -10.0);
    glVertex3f(-43.0 , -100.0, -10.0);
    glVertex3f(-43.0, -100.0, -15.0);
    glVertex3f(-43.0, -140.0, -15.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkiriblkg
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -140.0, -30.0);
    glVertex3f(-43.0 , -100.0, -30.0);
    glVertex3f(-43.0, -100.0, -35.0);
    glVertex3f(-43.0, -140.0, -35.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -140.0, -35.0);
    glVertex3f(-43.0 , -100.0, -35.0);
    glVertex3f(-38.0, -100.0, -35.0);
    glVertex3f(-38.0, -140.0, -35.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-18.0, -140.0, -35.0);
    glVertex3f(-18.0 , -100.0, -35.0);
    glVertex3f(-23.0, -100.0, -35.0);
    glVertex3f(-23.0, -140.0, -35.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -140.0, -10.0);
    glVertex3f(-43.0 , -100.0, -10.0);
    glVertex3f(-38.0, -100.0, -10.0);
    glVertex3f(-38.0, -140.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-18.0, -140.0, -10.0);
    glVertex3f(-18.0 , -100.0, -10.0);
    glVertex3f(-23.0, -100.0, -10.0);
    glVertex3f(-23.0, -140.0, -10.0);
    glEnd();


    glBegin(GL_QUADS);//belakang
    glColor3f(0.8, 0.4, 0.2);
     glVertex3f(-43.0, -40.0, -35.0);
    glVertex3f(-43.0 , -100.0, -35.0);
    glVertex3f(-18.0, -100.0, -35.0);
    glVertex3f(-18.0, -40.0, -35.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-18.0, -90.0, -10.0);
    glVertex3f(-18.0 , -100.0, -10.0);
    glVertex3f(-18.0, -100.0, -35.0);
    glVertex3f(-18.0, -90.0, -35.0);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -90.0, -10.0);
    glVertex3f(-43.0 , -100.0, -10.0);
    glVertex3f(-43.0, -100.0, -35.0);
    glVertex3f(-43.0, -90.0, -35.0);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3f(0.8, 0.4, 0.2);
    glVertex3f(-43.0, -90.0, -10.0);
    glVertex3f(-18.0 , -90.0, -10.0);
    glVertex3f(-18.0, -90.0, -35.0);
    glVertex3f(-43.0, -90.0, -35.0);
    glEnd();

}

void meja(){
     //meja
     glBegin(GL_QUADS);//depan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-160.0, -90.0, -10.0);
    glVertex3f(-160.0 , -100.0, -10.0);
    glVertex3f(-100.0, -100.0, -10.0);
    glVertex3f(-100.0, -90.0, -10.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkanankanan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100.0, -140.0, -10.0);
    glVertex3f(-100.0 , -100.0, -10.0);
    glVertex3f(-100.0, -100.0, -15.0);
    glVertex3f(-100.0, -140.0, -15.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkanandepan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100.0, -140.0, -55.0);
    glVertex3f(-100.0 , -100.0, -55.0);
    glVertex3f(-100.0, -100.0, -60);
    glVertex3f(-100.0, -140.0, -60);
    glEnd();
    glBegin(GL_QUADS);//tiangkanankanan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-160.0, -140.0, -10.0);
    glVertex3f(-160.0 , -100.0, -10.0);
    glVertex3f(-160.0, -100.0, -15.0);
    glVertex3f(-160.0, -140.0, -15.0);
    glEnd();
     glBegin(GL_QUADS);//tiangkanandepan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-160.0, -140.0, -55.0);
    glVertex3f(-160.0 , -100.0, -55.0);
    glVertex3f(-160.0, -100.0, -60);
    glVertex3f(-160.0, -140.0, -60);
    glEnd();
     glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100.0, -140.0, -10.0);
    glVertex3f(-100.0 , -100.0, -10.0);
    glVertex3f(-105.0, -100.0, -10.0);
    glVertex3f(-105.0, -140.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-155.0, -140.0, -10.0);
    glVertex3f(-155.0 , -100.0, -10.0);
    glVertex3f(-160.0, -100.0, -10.0);
    glVertex3f(-160.0, -140.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100.0, -140.0, -60.0);
    glVertex3f(-100.0 , -100.0, -60.0);
    glVertex3f(-105.0, -100.0, -60.0);
    glVertex3f(-105.0, -140.0, -60.0);
    glEnd();
    glBegin(GL_QUADS);//tiangkiiri depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-155.0, -140.0, -60.0);
    glVertex3f(-155.0 , -100.0, -60.0);
    glVertex3f(-160.0, -100.0, -60.0);
    glVertex3f(-160.0, -140.0, -60.0);
    glEnd();


     glBegin(GL_QUADS);//belakang
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-160.0, -90.0, -60.0);
    glVertex3f(-160.0 , -100.0, -60.0);
    glVertex3f(-100.0, -100.0, -60.0);
    glVertex3f(-100.0, -90.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-100.0, -90.0, -10.0);
    glVertex3f(-100.0 , -100.0, -10.0);
    glVertex3f(-100.0, -100.0, -60.0);
    glVertex3f(-100.0, -90.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-160.0, -90.0, -10.0);
    glVertex3f(-160.0 , -100.0, -10.0);
    glVertex3f(-160.0, -100.0, -60.0);
    glVertex3f(-160.0, -90.0, -60.0);
    glEnd();


    glBegin(GL_QUADS);//atas
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-160.0, -90.0, -10.0);
    glVertex3f(-100.0 , -90.0, -10.0);
    glVertex3f(-100.0, -90.0, -60.0);
    glVertex3f(-160.0, -90.0, -60.0);
    glEnd();

    /*glBegin(GL_QUADS);//bawah
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-10.0, -10.0, 10.0);
    glVertex3f(10.0 , -10.0, 10.0);
    glVertex3f(10.0, -10.0, -10.0);
    glVertex3f(-10.0, -10.0, -10.0);
    glEnd();*/

}

void kasur(){
     //kasur
     glBegin(GL_QUADS);//depanatas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-380.0, -70.0, 30.0);
    glVertex3f(-380.0 , -90.0, 30.0);
    glVertex3f(-200.0, -90.0, 30.0);
    glVertex3f(-200.0, -70.0, 30.0);
    glEnd();
     glBegin(GL_QUADS);//depantengah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-380.0, -90.0, 30.0);
    glVertex3f(-380.0 , -110.0, 30.0);
    glVertex3f(-200.0, -110.0, 30.0);
    glVertex3f(-200.0, -90.0, 30.0);
    glEnd();
    glBegin(GL_QUADS);//depanbawah
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-382.0, -110.0, 32.0);
    glVertex3f(-382.0 , -130.0, 32.0);
    glVertex3f(-198.0, -130.0, 32.0);
    glVertex3f(-198.0, -110.0, 32.0);
    glEnd();

      glBegin(GL_QUADS);//blkgatas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-380.0, -70.0, -30.0);
    glVertex3f(-380.0 , -90.0, -30.0);
    glVertex3f(-200.0, -90.0, -30.0);
    glVertex3f(-200.0, -70.0, -30.0);
    glEnd();
     glBegin(GL_QUADS);//blkgtengah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-380.0, -90.0, -30.0);
    glVertex3f(-380.0 , -110.0, -30.0);
    glVertex3f(-200.0, -110.0, -30.0);
    glVertex3f(-200.0, -90.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//blkgbawah
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-382.0, -110.0, -32.0);
    glVertex3f(-382.0 , -130.0, -32.0);
    glVertex3f(-198.0, -130.0, -32.0);
    glVertex3f(-198.0, -110.0, -32.0);
    glEnd();

    glBegin(GL_QUADS);//kananatas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-200.0, -70.0, 30.0);
    glVertex3f(-200.0 , -90.0, 30.0);
    glVertex3f(-200.0, -90.0, -30.0);
    glVertex3f(-200.0, -70.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//kanantengah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-200.0, -90.0, 30.0);
    glVertex3f(-200.0 , -110.0, 30.0);
    glVertex3f(-200.0, -110.0, -30.0);
    glVertex3f(-200.0, -90.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//kananbawah
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-198.0, -110.0, 32.0);
    glVertex3f(-198.0 , -130.0, 32.0);
    glVertex3f(-198.0, -130.0, -32.0);
    glVertex3f(-198.0, -110.0, -32.0);
    glEnd();

    glBegin(GL_QUADS);//kiriatas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-380.0, -70.0, 30.0);
    glVertex3f(-380.0 , -90.0, 30.0);
    glVertex3f(-380.0, -90.0, -30.0);
    glVertex3f(-380.0, -70.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//kiritengah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-380.0, -90.0, 30.0);
    glVertex3f(-380.0 , -110.0, 30.0);
    glVertex3f(-380.0, -110.0, -30.0);
    glVertex3f(-380.0, -90.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//kiribawah
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-382.0, -110.0, 32.0);
    glVertex3f(-382.0 , -130.0, 32.0);
    glVertex3f(-382.0, -130.0, -32.0);
    glVertex3f(-382.0, -110.0, -32.0);
    glEnd();


    glBegin(GL_QUADS);//atas atas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-380.0, -70.0, 30.0);
    glVertex3f(-200.0 , -70.0, 30.0);
    glVertex3f(-200.0, -70.0, -30.0);
    glVertex3f(-380.0, -70.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);//atas bawah
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-382.0, -110.0, 32.0);
    glVertex3f(-198.0 , -110.0, 32.0);
    glVertex3f(-198.0, -110.0, -32.0);
    glVertex3f(-382.0, -110.0, -32.0);
    glEnd();
    
    //lemari
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0); // belakang
    glVertex3f(-460, -110, -50);
    glVertex3f(-420, -110, -50);
    glVertex3f(-420, -50, -50);
    glVertex3f(-460, -50, -50);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-420, -110, 10);
    glVertex3f(-460, -110, 10);
    glVertex3f(-460, -50, 10);
    glVertex3f(-420, -50, 10);
    glEnd();

    glBegin(GL_QUADS);  //bawah
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-420, -110, 10);
    glVertex3f(-460, -110, 10);
    glVertex3f(-460, -110, -50);
    glVertex3f(-420, -110, -50);

    glBegin(GL_QUADS);  //atas
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-420, -50, 10);
    glVertex3f(-460, -50, 10);
    glVertex3f(-460, -50, -50);
    glVertex3f(-420, -50, -50);
    glEnd();

    glBegin(GL_QUADS);  //kiri
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-460, -50, -50);
    glVertex3f(-460, -110, -50);
    glVertex3f(-460, -110, 10);
    glVertex3f(-460, -50, 10);

    glBegin(GL_QUADS);  //kanan
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-420, -50, -50);
    glVertex3f(-420, -50, 10);
    glVertex3f(-420, -110, 10);
    glVertex3f(-420, -110, -50);
    glEnd();

    glBegin(GL_QUADS);  //kanan
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-460.2, -50, 10);
    glVertex3f(-460.2, -50, -50);
    glVertex3f(-460.2, -80, -50);
    glVertex3f(-460.2, -80, 10);
    glEnd();

    glBegin(GL_POINTS);  //kanan
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-460.9, -55, -20);
    glEnd();


    /*glBegin(GL_QUADS);//bawah
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-10.0, -10.0, 10.0);
    glVertex3f(10.0 , -10.0, 10.0);
    glVertex3f(10.0, -10.0, -10.0);
    glVertex3f(-10.0, -10.0, -10.0);
    glEnd();*/

}


void tampil(void)
{
    if(is_depth){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }else{
        glClear(GL_COLOR_BUFFER_BIT);
    }
	
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xtrans,ytrans,ztrans);
    glPushMatrix();
    glBegin(GL_LINE_LOOP);

    bangunankanan();
    gariskaca();
    bagian_tengah(); 
    jendelakotak3();
    
	jendelagaris_kiritengah();  
    jendelagaris_kanantengah();
    jendelahitam_tengah();
    pembatas_jendela();
    bagianatas_pembatasjendela();
    bagian_serong();
    knopi();
    
    bangunankiri();
    pitatasbangunankiri();
    jendela_kiri();
    kanopikiri();
    
    bagian_belakang();
    buletan();

	atap();
    diatas_atap();
    kaca_atap();
	
	kursi();
	meja();
	kasur();
	parkiran();
	
	glPushMatrix();
	glScalef(0.8,0.8,0.8);
	glTranslatef(-120,-15,19);
	tv();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(1,0.8,1);
	glTranslatef(0,-30,0);
	lemari();
	glPopMatrix();
	
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
		case 'W':
			ztrans += 3;
		break;
		case 'd':
		case 'D':
			xtrans += 3;
		break;
		case 's':
		case 'S':
			ztrans -= 3;
		break;
		case 'a':
		case 'A':
			xtrans -= 3;
		break;
		case 'l':
		case 'L':
			ytrans += 3;
		break;
		case 'h':
		case 'H':
			ytrans -= 3;
		break;
		case '5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			} else {
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			
	}
		tampil();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff= x - yrot;
        ydiff= -y +xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(150.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
