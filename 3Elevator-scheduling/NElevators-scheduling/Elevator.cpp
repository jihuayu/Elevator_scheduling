#include "Elevator.h"



elevator::elevator()
{
  static int i=1;
  id = i;
  i++;
  floor = 1;
}


elevator::~elevator()
{
}
