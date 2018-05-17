#include "RevSolid.h"

#include <iostream>

RevSolid::RevSolid (): Solid(){
  this->type = OPEN;
}
RevSolid::RevSolid (int steps, OriginType type): Solid(steps){
  this->type = type;
}
RevSolid::~RevSolid (){}
void RevSolid::generate(){
  float angleOfRotation = 360.0/this->steps;
  if( this->type == OPEN){
    Line nextLine = this->vertices;
    this->gen_vertices.push_back(nextLine);
    for( int i = 0 ; i < steps ; i++ ){
      for( auto& v : nextLine ){
        Vector ts = v.add(Vector(0,v.getY() * -1,0));
        ts = ts.rotateY(angleOfRotation);
        ts = ts.add(Vector(0,v.getY(),0));
        v = ts;
      }
      this->gen_vertices.push_back(nextLine);
    }
  }else{
    Vector *translation;
    Line nextLine = this->vertices;
    for( auto& vertex : this->vertices ){
      if( !translation || translation->getX() > vertex.getX() ){
        translation = &vertex;
      }
    }
    Vector t( translation->getX() * -1,0,0);
    for( auto& vertex : nextLine ){
      vertex = vertex.add(t);
    }
    this->gen_vertices.push_back(nextLine);
    for( int i = 0 ; i < steps ; i++ ){
      for( auto& v : nextLine ){
        v = v.rotateY(angleOfRotation);
      }
      this->gen_vertices.push_back(nextLine);
    }
  }
}
