#ifndef __UTILS__H__
#define __UTILS__H__

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "../Vector3D/Vector3D.h"

namespace Utils {
  void translate( Vector t );
  void rotate( Vector r );
  void scale( Vector s );
  void setNormal( Vector n );
  void vertex( Vector v );
} /* Utils */

#endif
