#include "BarSolid.h"

BarSolid::BarSolid() : Solid(){}
BarSolid::~BarSolid(){}

void BarSolid::read(std::string solidFile, std::string pathFile){
  Solid::read(solidFile);
  std::string line = "";
  std::ifstream file(pathFile);
  while( getline(file,line) && line != "f" ){
    std::stringstream sline(line);
    float y,z;
    sline >> z >> y;
    Vector v(0,y,z);
    this->path.push_back(v);
  }
}

void BarSolid::generate() {
  Line nextLine = this->vertices;
  for( auto& v : nextLine ){
    v = v.add(this->path[0]);
  }
  this->gen_vertices.push_back(nextLine);
}

void BarSolid::drawPath(){
  glBegin(GL_POINTS);
    for( auto& vertex : this->path ){
      Utils::vertex(vertex);
    }
  glEnd();
}
