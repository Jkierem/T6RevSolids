#ifndef __SOLID__H__
#define __SOLID__H__

#include <vector>
#include <string>

#include "../Utils/Utils.h"
#include "../Vector3D/Vector3D.h"

typedef std::vector<Vector> Line;

class Solid {
protected:
  Line vertices;
  std::vector<Line> gen_vertices;
  int steps;

public:
  Solid ();
  Solid ( int steps );
  virtual ~Solid ();
  virtual void read( std::string fileName );
  virtual generate() =0;
  void draw();
  void createTriangles( Line previous_line , Line current_line );
};

#endif
