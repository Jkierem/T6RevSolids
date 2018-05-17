#include "./Utils.h"

void Utils::translate( Vector t ){
  glTranslatef( t.getX() , t.getY() , t.getZ() );
}

void Utils::rotate( Vector r ){
  rotate( r.getX() , Vector(1,0,0) );
  rotate( r.getY() , Vector(0,1,0) );
  rotate( r.getZ() , Vector(0,0,1) );
}

void Utils::rotate( float angle , Vector axis ){
  glRotatef( angle , axis.getX() , axis.getY() , axis.getZ() );
}

void Utils::scale( Vector s ){
  glScalef( s.getX() , s.getY() , s.getZ() );
}

void Utils::setNormal( Vector n ){
  glNormal3f( n.getX() , n.getY() , n.getZ() );
}

void Utils::vertex( Vector v ){
  glVertex3f( v.getX() , v.getY() , v.getZ() );
}

void Utils::setCamera( Vector eye , Vector center , Vector up ){
  gluLookAt(
    eye.getX() , eye.getY() , eye.getZ(),
    center.getX() , center.getY() , center.getZ(),
    up.getX() , up.getY() , up.getZ()
  );
}

void Utils::printControls(){
  std::cout << "[W , S]: Rotacion en el eje X." << std::endl;
  std::cout << "[A , D]: Rotacion en el eje Y." << std::endl;
  std::cout << "[Q , E]: Rotacion en el eje Z." << std::endl;
  std::cout << "R: Resetear rotacion." << std::endl;
}
