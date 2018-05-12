#include <set>
#include <algorithm>
#include "Passager.h"
#include <vector>
using namespace std;
class elevator
{
public:
  elevator();
  ~elevator();
  int find(int goal) {
    return canreach.count(goal);
  }

  void move() {
    floor += direction;
  }

  int getFloor() {
    return floor;
  }
  void setDirection(const int direction){
    this->direction = direction;
  }
  vector <passager> in_peo;
  vector <passager> out_peo;
  set <int> canreach;
  int id;
  int isopen;
private: 
  int floor;
  int direction;
};
