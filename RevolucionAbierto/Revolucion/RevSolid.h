#ifndef __REV__H__
#define __REV__H__ v

#include "../../lib/Solid/Solid.h"

enum OriginType { OPEN, CLOSED };

class RevSolid : public Solid {
private:
  OriginType type;
public:
  RevSolid () ;
  RevSolid (int steps=10, OriginType type=OPEN );
  virtual ~RevSolid ();
  void generate() override;
};

#endif
