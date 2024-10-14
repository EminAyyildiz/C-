

#ifndef NAME_H
#define NAME_H

class name
{
private:
    char Name[30];
    char Surname[30];
public:
    name();
    name(char*, char*);
    ~name();


    void setName(char* );
    void setSurname(char* );
    char* getName();
    char* getSurname();
    void add(char*, char*);
    void show();

};



#endif