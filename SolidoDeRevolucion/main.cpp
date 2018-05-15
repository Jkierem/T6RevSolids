#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "./Revolucion/RevSolid.h"

Solid* solid = new RevSolid();
std::string fileName = "../res/curvaAbierta.in";

float timeout = 1000/60;

void Timer( int i ){
  glutPostRedisplay();
  glutTimerFunc( timeout , Timer, 0);
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
  glViewport(0, 0, 600, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 600, 0, 600);
  glMatrixMode(GL_MODELVIEW);

  solid->read(fileName);
  solid->generate();
  glutTimerFunc(0, Timer, 0);
}

void draw(){
  glColor3f(1,1,1);
  solid->drawInitialPoints();

  glColor3f(1,0,0);
  glTranslatef(0,0,-10);
  glutWireSphere( 5 , 20 ,20);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  draw();
  glutSwapBuffers();
}

void reshape( int w , int h ){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
}

int main(int argc, char *argv[]) {

  //Initial display and window config
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600,600);
  glutCreateWindow("!");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
