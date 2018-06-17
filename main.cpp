#include "Monkey.hpp"
#include "Stacks.hpp"
#include <iostream>
#include <pthread.h>
using namespace std;

static void *MonkeyWork(void *param);

int main() {
  srand(time(NULL));
  int numbMonkeys = 2;
  // List of monkeys
  Monkey monkeyBox[numbMonkeys] = {};
  // Stores ID for each thread
  pthread_t tid[numbMonkeys];

  Stacks newStack("My Stack");
  newStack.populateStack(5);
  //  newStack.printStack();

  // Threads creation
  for (int x = 0; x < numbMonkeys; x++) {
    // A monkey will know the location of the Stack of bananas
    Monkey aMonkey(x, &newStack); // creates a monkey
    monkeyBox[x] = aMonkey;       // store mokey in the box
    // Sets monkeys to work
    pthread_create(&tid[x], NULL, *MonkeyWork, (void *)&monkeyBox[x]);
  }
  // Wait for thread to join
  for (int i = 0; i < numbMonkeys; i++) {
    pthread_join(tid[i], NULL);
  }
}

static void *MonkeyWork(void *param) {
  Monkey *aMonkeyPointer = (Monkey *)param;

  pthread_mutex_lock(&(aMonkeyPointer->protectMonkeyJobs));

  printf("Hey! I am monkey #: %i\n", aMonkeyPointer->getMonkeyID());
  aMonkeyPointer->getStackLocation()->removeData();
  aMonkeyPointer->getStackLocation()->printStack();

  pthread_mutex_unlock(&(aMonkeyPointer->protectMonkeyJobs));

  pthread_exit(NULL);
}
