#ifndef __REV__H__
#define __REV__H__ v

#include "../../lib/Solid/Solid.h"

class RevSolid : public Solid {

public:
  RevSolid () ;
  RevSolid (int steps);
  virtual ~RevSolid ();
  void generate() override;
};

#endif
