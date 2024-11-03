#ifndef LESSON_H
#define LESSON_H

class lesson
{
private:
    int LesonCode;
    char Lesson[30];

public:
    lesson();
    lesson( int, char*);
    ~lesson();

    void setLessonCode(int);
    void setLesson(char* );
    int getLessonCode();
    char* getlesson();
    void Save(int, char*);
    void Show();
};

#endif
