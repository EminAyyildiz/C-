#include <iostream>
#include "lesson.h"
#include <stdlib.h>
#include <string.h>

using namespace std;



lesson::lesson()
{

}


lesson::lesson( int lc, char* les)
{
    LesonCode = lc;
    strcpy(Lesson, les);
}

lesson::~lesson()
{
}


void lesson:: setLessonCode(int lc)
{
    LesonCode = lc;
}
void lesson:: setLesson(char* les )
{
    strcpy(Lesson, les);
}
int  lesson:: getLessonCode()
{
    return LesonCode;
}
char* lesson:: getlesson()
{
    return Lesson;
}
void lesson:: Save(int lc, char* les)
{
    LesonCode = lc;
    strcpy(Lesson, les);
}
void lesson:: Show( )
{
    cout<< "Lesson : "<< LesonCode<<"--"<<Lesson<<endl;
}
