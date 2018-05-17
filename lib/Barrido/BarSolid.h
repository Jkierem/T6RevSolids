#ifndef __BARSOLID__H__
#define __BARSOLID__H__

#include "../../lib/Solid/Solid.h"

class BarSolid : public Solid {
private:
  Line path;

public:
  BarSolid();
  BarSolid( Vector color );
  virtual ~BarSolid();
  void read(std::string solidFile, std::string pathFile);
  void generate() override;
  void draw();
  void drawPath();
};

#endif
