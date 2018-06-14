#include "Stacks.hpp"
#include <iostream>
using namespace std;

int main() {
  srand(time(NULL));

  Stacks newStack("My Stack");
  newStack.populateStack(5);
  newStack.printStack();


  newStack.removeData();
  newStack.printStack();



}
