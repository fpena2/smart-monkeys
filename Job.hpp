#pragma once
#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <vector>
#include <numeric> /* accumulate */

using namespace std;

class Job {
private:
  int jobID;
  int jobOwnerID;
  vector<int> task;
  int duration;

public:
  Job(int ID) : jobID(ID) {
    for (int x = 0; x < 5; x++) {
      task.push_back(rand() % 10 + 1);
    }
    duration = accumulate(task.begin(), task.end(), 0);
  }

  void assignWorker(int workerID) { jobOwnerID = workerID; }

  void print() {
    cout << "Job ID: " << jobID << endl;
    cout << "Length: " << duration << endl;
    cout << "Data: " << endl;
    for (int element : task) {
      cout << element << " ";
    }
    cout << endl;
  }
};
