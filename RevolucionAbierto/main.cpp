#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "../lib/Revolucion/RevSolid.h"
#include "../lib/Utils/Utils.h"

Vector c(255,0,0);
RevSolid* solid = new RevSolid(20,c,OPEN);
std::string fileName = "../res/curvaAbierta.in";

Vector eye(0,10,50);
Vector center(0,0,0);
Vector up(0,1,0);

Vector rot(0,0,0);

float timeout = 1000/60;
static GLfloat light0_position[] = {150.0,40.0,0.0,0.0};

void draw();
void init();
void resize( int w , int h );
void display();
void Timer(int i);
void keyboard( unsigned char key , int x , int y );

int main(int argc, char *argv[]) {
  Utils::printControls();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Revolution Solid");
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}

void draw(){
  Utils::setCamera( eye , center , up);
  Utils::rotate(rot);
  solid->draw();
}

void init(){
  solid->read(fileName);
  solid->generate();
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
  glEnable( GL_DEPTH_TEST );

  glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glShadeModel(GL_FLAT);
  glutTimerFunc(0, Timer, 0);
}

void resize( int width , int height ){
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 3000.0f);
  glMatrixMode(GL_MODELVIEW);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  draw();
  glutSwapBuffers();
}

void Timer(int i){
  glutPostRedisplay();
  glutTimerFunc( timeout , Timer, 0);
}

void keyboard( unsigned char key , int x , int y ){
  switch (key) {
    case 'w': case 'W':
    rot = rot.add(Vector(10,0,0));
    break;
    case 's': case 'S':
    rot = rot.add(Vector(-10,0,0));
    break;
    case 'a': case 'A':
    rot = rot.add(Vector(0,-10,0));
    break;
    case 'd': case 'D':
    rot = rot.add(Vector(0,10,0));
    break;
    case 'q': case 'Q':
    rot = rot.add(Vector(0,0,10));
    break;
    case 'e': case 'E':
    rot = rot.add(Vector(0,0,-10));
    break;
    case 'r': case 'R':
    rot = Vector(0,0,0);
    break;
  }
}
