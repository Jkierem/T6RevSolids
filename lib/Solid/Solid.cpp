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
  for (int i = 0; i < gen_vertices.size() ; i++) {
    if( i == gen_vertices.size() - 1){
      createTriangles( gen_vertices[i] , gen_vertices[0] );
    }else{
      createTriangles( gen_vertices[i] , gen_vertices[i+1] );
    }
  }
}

void createTriangles( Line previous_line , Line current_line ){
  //Triangulos que miran hacia abajo
  for (int v = 0; v < previous_line.size()-1 ; v++) {
    Vector c1 = current_line[v].vectorSub(previous_line[v]);
    Vector c2 = previous_line[v+1].vectorSub(previous_line[v]);
    Vector n = c1.cross(c2);
    Utils::setNormal(n.normalize());
    glBegin(GL_TRIANGLES);
      Utils::vertex( current_line[v] );
      Utils::vertex( previous_line[v] );
      Utils::vertex( previous_line[v+1] );
    glEnd();
  }
  //Triangulos que miran hacia arriba
  for (int v = 0; v < previous_line.size()-1 ; v++) {
    Vector c1 = current_line[v].vectorSub( current_line[v+1] );
    Vector c2 = previous_line[v+1].vectorSub( current_line[v+1] );;
    Vector n = c1.cross(c2);
    Utils::setNormal(n.normalize());
    glBegin(GL_TRIANGLES);
      Utils::vertex( current_line[v] );
      Utils::vertex( current_line[v+1] );
      Utils::vertex( previous_line[v+1] );
    glEnd();
  }
}
