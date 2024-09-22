#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef struct Library
{
    string title;
    string author;
    string ISBN;
    bool isLoaned;
    
}Library;


#endif