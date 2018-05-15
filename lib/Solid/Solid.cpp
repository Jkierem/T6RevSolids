#include "Solid.h"

Solid (){
  this->steps = 10;
}

Solid ( int steps ){
  this->steps = steps;
}

virtual ~Solid (){}

void read( std::string fileName ){

}

void draw(){
  for (int i = 1; i < gen_vertices.size() ; i++) {
    std::vector<Vector> current_line = gen_vertices[i];
    std::vector<Vector> previous_line = gen_vertices[i-1];
    for (int v = 0; v < previous_line.size() ; v++) {
      Vector c1 = current_line[v].vectorSub(previous_line[v]);
      Vector c2 = previous_line[v+1].vectorSub(previous_line[v]);
      Vector n = c1.cross(c2);
      n.normalize();
      Utils::setNormal(n);
      glBegin(GL_TRIANGLES);
        Utils::vertex( current_line[v] );
        Utils::vertex( previous_line[v] );
        Utils::vertex( previous_line[v+1] );
      glEnd();
    }
    for (int v = 0; v < previous_line.size() ; v++) {
      Vector c1 = current_line[v].vectorSub( current_line[v+1] );
      Vector c2 = previous_line[v+1].vectorSub( current_line[v+1] );;
      Vector n = c1.cross(c2);
      n.normalize();
      Utils::setNormal(n);
      glBegin(GL_TRIANGLES);
        Utils::vertex( current_line[v] );
        Utils::vertex( current_line[v+1] );
        Utils::vertex( previous_line[v+1] );
      glEnd();
    }
  }
}
