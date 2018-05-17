#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "./Revolucion/RevSolid.h"

typedef RevSolid Solid;

Solid* solid = new Solid();
std::string fileName = "curvaAbierta.in";

float timeout = 1000/60;

void Timer( int i ){
  glutPostRedisplay();
  glutTimerFunc( timeout , Timer, 0);
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_LIGHTING );
  solid->read("./res/");
  solid->generate();
  glutTimerFunc(0, Timer, 0);
}

void draw(){
  solid->draw();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  draw();
  glutSwapBuffers();
}

void reshape( int width , int height ){
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 6000.0f);
  glMatrixMode(GL_MODELVIEW);
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
