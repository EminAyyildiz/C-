#include <iostream>
#include "Dogum.h"
using namespace std;

Dogum::Dogum()
{
}

Dogum::Dogum(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

Dogum::~Dogum()
{
}

void Dogum :: setDay(int d )
{
    day = d;
}

void Dogum :: setMonth(int m)
{
    month = m;
}

void Dogum :: setYear(int y )
{
    year = y;
}

int Dogum :: getDay()
{
    return day;
}
int Dogum :: getMonth()
{
    return month;
}
int Dogum :: getYear()
{
    return year;
}

void Dogum :: add(int d, int m, int y)
{
    day = d, month = m, year = y;
}
void Dogum :: show()
{
    cout << "Date of Birth : " << day <<"."<<month<<"."<<year<< endl;
}