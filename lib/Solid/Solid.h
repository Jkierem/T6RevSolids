#ifndef __SOLID__H__
#define __SOLID__H__

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "../Utils/Utils.h"
#include "../Vector3D/Vector3D.h"

typedef std::vector<Vector> Line;

class Solid {
protected:
  Line vertices;
  std::vector<Line> gen_vertices;
  int steps;
  Vector color;

public:
  Solid ();
  Solid ( int steps );
  Solid ( int steps , Vector color );
  virtual ~Solid ();
  void read( std::string fileName );
  virtual void generate() =0;
  void draw(bool closed=true);
  void drawInitialPoints();
  void drawGeneratedPoints();
  void createTriangles( Line previous_line , Line current_line );
  Vector getVector(int pos);
  void setColor( Vector color );
};

#endif
