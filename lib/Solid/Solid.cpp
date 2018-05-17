#include "Solid.h"

Solid::Solid (){
  this->steps = 10;
  this->color = Vector(255,255,255);
}

Solid::Solid ( int steps ){
  this->steps = steps;
  this->color = Vector(255,255,255);
}

Solid::Solid ( int steps , Vector color ){
  this->steps = steps;
  this->color = color;
}

Solid::~Solid (){}

void Solid::read( std::string fileName ){
  std::string line = "";
  std::ifstream file(fileName);
  while( getline(file,line) && line != "f" ){
    std::stringstream sline(line);
    float x,y;
    sline >> x >> y;
    Vector v(x,y,0);
    this->vertices.push_back(v);
  }
}

void Solid::draw(bool closed){
  for (int i = 0; i < gen_vertices.size() ; i++) {
    if( i != gen_vertices.size() - 1 ){
      createTriangles( gen_vertices[i] , gen_vertices[i+1] );
    }else if(closed){
      createTriangles( gen_vertices[i] , gen_vertices[0] );
    }
  }
}

void Solid::drawInitialPoints(){
  glBegin(GL_LINE_STRIP);
    for ( int i = 0; i < this->vertices.size() ; i++ ) {
      Utils::vertex( this->vertices[i] );
    }
  glEnd();
}

void Solid::drawGeneratedPoints(){
  glBegin(GL_POINTS);
  for( auto line : this->gen_vertices ){
    for( auto vertex : line ){
      Utils::vertex(vertex);
    }
  }
  glEnd();
}

void Solid::createTriangles( Line previous_line , Line current_line ){
  //Triangulos que miran hacia abajo
  for (int v = 0; v < previous_line.size()-1 ; v++) {
    Vector c1 = current_line[v].vectorSub(previous_line[v]);
    Vector c2 = previous_line[v+1].vectorSub(previous_line[v]);
    Vector n = c2.cross(c1);
    Utils::setColor(this->color);
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

Vector Solid::getVector(int pos){
  return this->vertices[pos];
}

void Solid::setColor( Vector color ){
  this->color = color;
}
