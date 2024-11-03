#ifndef STUDENT_H
#define STUDENT_H

#include "lesson.h"
#include "name.h"
#include "Dogum.h"

class student
{
private:
    int Number;
    double average;
    lesson les;
    Dogum dg;
    name nam;

public:
    student();
    student(Dogum dg, lesson ls, name nm, int nmbr, double avrg);

    ~student();

    void setNumber(int);
    void setAverage(double);
    int getNumara();
    double getAverage();
    void Save(Dogum dg, lesson ls, name nm, int nmbr, double avrg);
    void Show();
};

#endif