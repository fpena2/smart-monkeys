#pragma once
#include <iostream>
#include <numeric>  /* accumulate */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <vector>

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

    int * getTaskList() { return &task[0]; }

    void assignWorker(int workerID) { jobOwnerID = workerID; }

    void print() {
        cout << "\nJob ID: " << jobID << endl;
        cout << "Length: " << duration << endl;
        cout << "Data: ";
        for (int element : task) {
            cout << element << " ";
        }
        cout << endl;
    }
};
