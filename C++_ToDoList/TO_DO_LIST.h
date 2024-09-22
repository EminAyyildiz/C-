#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <iostream>
#include <string>

#include <vector>
#include <string>

using namespace std;

typedef struct Task {
    string description;
    bool isCompleted;

   void printTask(int index) const {
    cout << index + 1 << ". ";
    
    if (isCompleted) {
        cout << "[Tamamlandı] ";
    } else {
        cout << "[ ] ";
    }

    cout << description << endl;
}

} ToDoList;




#endif