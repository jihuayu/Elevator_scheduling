#pragma once
class Elevator_
{
public:
  Elevator_();
  ~Elevator_();

  void open() {
    isopen = 1;
  }
  void close() {
    isopen = 0;
  }
  void run() {
    liftfloor += direction;
  }
private:
  int liftfloor = 1;
  int direction = 0;
  bool isopen = 0;
};
