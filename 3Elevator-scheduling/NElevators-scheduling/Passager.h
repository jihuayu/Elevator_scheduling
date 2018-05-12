#pragma once
#include<iostream>
using namespace std;
class passager
{
public:
  int id;
  int isok;
  int ischange;
  int floor;
  int direction;
  int time;

  friend istream & operator >>(istream &, passager &);
};
