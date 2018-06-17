#pragma once
#include "Stacks.hpp"
#include <iostream>
using namespace std;

class Monkey {
private:
  int ID;
  bool monkeyIsDone = false;
  Stacks *stackLocation;

public:
  // Muxtex lock utilized to prevent threads from accessing critical data
  pthread_mutex_t protectMonkeyJobs = PTHREAD_MUTEX_INITIALIZER;

  Monkey(){};
  Monkey(int IDnumber, Stacks *location)
      : ID(IDnumber), stackLocation(location){};

  // retrives the stack location from the monkey
  Stacks *getStackLocation() { return stackLocation; }
  int getMonkeyID() { return ID; }
};
