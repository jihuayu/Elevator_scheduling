#include "passager.h"


istream & operator >>(istream & is, passager & c) {
  static int i = 1;
  c.id = i;
  i++;
  c.isok = 0;
  c.ischange = 0;
  is >> c.time >> c.floor >> c.direction;
  return is;
}