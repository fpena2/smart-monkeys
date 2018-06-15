#pragma once
#include <iostream>
using namespace std;

class Monkey {
private:
  int ID;
  bool monkeyIsDone = false;

public:
  Monkey(){};
  Monkey(int IDnumber) : ID(IDnumber){};
  void performJob() {}
  void printMonkey() { cout << ID << endl; }
};
