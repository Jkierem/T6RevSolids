#ifndef __SOLID__H__
#define __SOLID__H__

#include <vector>
#include <string>
#include "../Vector3D/Vector3D.h"

class Solid {
protected:
  std::vector<Vector> vertices;
  std::vector<std::vector<Vertices>> gen_vertices;
  int steps;

public:
  Solid ();
  Solid ( int steps );
  virtual ~Solid ();
  void read( std::string fileName );
  virtual generate() =0;
  void draw();
};

#endif
