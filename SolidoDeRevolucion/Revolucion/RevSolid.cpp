#include "RevSolid.h"

#include <iostream>

RevSolid::RevSolid (): Solid(){}
RevSolid::RevSolid (int steps): Solid(steps){}
RevSolid::~RevSolid (){}
void RevSolid::generate(){
  this->gen_vertices.push_back(this->vertices);
  std::cout << this->vertices.size() << std::endl;
  for ( auto vertex : this->vertices ){
    std::cout << vertex.toString() << std::endl;
  }
}
