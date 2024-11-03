#ifndef DOGUM_H
#define DOGUM_H

class Dogum
{
private:
    int day, month, year;
public:
    Dogum(/* args */);
    Dogum(int, int, int);
    ~Dogum();

    void setDay(int );
    void setMonth(int );
    void setYear(int );

    int getDay();
    int getMonth();
    int getYear();

    void add(int, int, int);
    void show();

};


#endif