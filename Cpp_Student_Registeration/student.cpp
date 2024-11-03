#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

student::student(/* args */)
{
}

student::student(Dogum dgt, lesson ls, name nm, int nmbr, double avrg)
{
    dg = dgt;
    les = ls;
    nam = nm;
    Number = nmbr;
    average = avrg;
}

student::~student()
{
}

void student:: setNumber(int nmbr)
{
    Number = nmbr;
}

void student:: setAverage(double avrg)
{
    average = avrg;
}

int student:: getNumara()
{
    return Number;
}
double student:: getAverage()
{
    return average;
}

void student:: Save(Dogum dgt, lesson ls, name nm, int nmbr, double avrg)
{
    dg = dgt;
    les = ls;
    nam = nm;
    Number = nmbr;
    average = avrg;
}

void student:: Show()
{
    cout << "Student Information" <<endl;
    nam.show();
    dg.show();
    cout <<"Number : " <<Number<< endl;
    les.Show();
    cout<< "GPO : " << average<< endl;
    
}