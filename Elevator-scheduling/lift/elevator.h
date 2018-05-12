#pragma once
#include <vector>
#include "passager.h"
using namespace std;
class elevator {
public:
  int liftfloor = 1;
  int goalid = 0;
  int liftgoal = 0;
  void min(vector <passager>& people, int n) {
    int min = 10000;
    int num = 0;
    passager a;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (people[i].time > people[j].time) {
          a = people[i]; people[i] = people[j]; people[j] = a;
          num = people[i].id; people[i].id = people[j].id; people[j].id = num;
        }
      }
    }
  }
  //更新乘客请求状态
  void iscall(vector <passager> & people, int nowtime, int n) {
    for (int i = 0; i < n; i++) {
      people[i].call(nowtime);
    }
  }
  //更新乘客搭乘状态
  bool isopen(vector <passager>& people, int liftfloor, int nowtime, int & sumtime, int n) {
    bool isopen = 0;
    for (int i = 0; i < n; i++) {
      int cost = people[i].in_out(liftfloor, nowtime);
      if (cost == -1) {
        isopen = 1;
      }
      else if (cost > 0) {
        sumtime += cost;
        //cout << sumtime << endl;
        isopen = 1;
      }
    }
    return isopen;
  }
  //选择最优的电梯目的地
  int choice(vector <passager>& people, int liftfloor, int n) {
    int mincost = 10000000;
    int id = -1;
    for (int i = 0; i < n; i++) {
      int liftgoal = people[i].goal;
      if (!liftgoal) {
        continue;
      }
      int cost = 0;
      for (int j = 0; j < n; j++) {
        if (liftgoal <= people[i].goal&&liftfloor >= people[i].goal || liftgoal >= people[i].goal&&liftfloor <= people[i].goal) {
          cost += abs(liftgoal - liftfloor);
        }
        else if (people[i].goal) {
          cost += 2 * abs(liftgoal - liftfloor);
        }
      }
      //cout << cost<<'#'<<liftfloor<<'#'<<liftgoal;

      if (cost < mincost) {
        id = i;
        mincost = cost;
        //cout << "#"<< people[id].goal<<"#"<<mincost;
      }//getchar();
    }
    return id;
  }
  //判断是否所有的乘客请求全部完成
  bool isall(vector <passager>& people, int n) {
    for (int i = 0; i < n; i++) {
      if (people[i].isok != 2) {
        return 0;
      }
    }
    return 1;
  }
};
