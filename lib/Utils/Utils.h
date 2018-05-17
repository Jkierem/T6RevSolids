#ifndef __UTILS__H__
#define __UTILS__H__

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

#include "../Vector3D/Vector3D.h"

namespace Utils {
  void translate( Vector t );
  void rotate( Vector r );
  void rotate( float angle , Vector axis );
  void scale( Vector s );
  void setNormal( Vector n );
  void vertex( Vector v );
  void setCamera( Vector eye , Vector center , Vector up );
  void printControls();
} /* Utils */

#endif
