#ifndef __INPUT__H__
#define __INPUT__H__

#include <string>
#include <iostream>
#include <stdlib.h>

/*
This class is almost useless. Just used to remove logic
from the main function as to clean up code.
*/
class InputHandler {
private:

public:
  InputHandler ( );
  virtual ~InputHandler ();

  bool onKeyPress( unsigned char key , int x , int y );
};

typedef InputHandler Input;

#endif
