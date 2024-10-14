#include <iostream>
#include "name.h"
#include <stdlib.h>
using namespace std;

name::name()
{
}

name::name(char* nm, char* srnm)
{
    strcpy(Name, nm);
    strcpy(Surname, srnm);

}
name::~name()
{
}

void name:: setName(char* nm)
{
    strcpy(Name, nm);
}
void name:: setSurname(char* snm)
{
    strcpy(Surname, snm);
}

char* name:: getName()
{
    return Name;
}
char* name:: getSurname()
{
    return Surname;
}
void name:: add(char* nm, char* srnm)
{
    strcpy(Name, nm);
    strcpy(Surname, srnm);
}

void name:: show()
{
    cout<<"Name/Surname : "<<Name<<"  "<<Surname<<endl;
}