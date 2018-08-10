#pragma once
#include "Job.hpp"
#include <algorithm> // std::sort
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ascendingSort(int a, int b) { return (a < b); }

class Stacks {
  private:
    string name;
    int size;
    vector<Job> insideData;

  public:
    Stacks(string givenName) : name(givenName){};

    string getName() { return name; }
    int getSize() { return insideData.size(); }
    void pushData(Job input) { insideData.push_back(input); }

    // populates the stack with itergers
    void populateStack(int size) {
        for (int x = 0; x < size; x++) {
            pushData(Job(x));
        }
    }

    bool checkEmpty() {
        if (insideData.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    void removeData() {
        if (checkEmpty() == false) {
            insideData.pop_back();
        } else {
            cout << "Stack has not elements" << endl;
        }
    }

    void printStack() {
        cout << "Stack Name: " + name << endl;
        for (Job element : insideData) {
            element.print();
        }
        cout << endl;
    }

    void sortJobData() {
        for (Job &aJob : insideData) {
            sort(aJob.getTaskList(), aJob.getTaskList() + 5, ascendingSort);
        }
    }
};
