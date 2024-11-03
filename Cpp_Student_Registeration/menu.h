#ifndef MENU_H
#define MENU_H


class menu
{
private:

public:
    menu();
    ~menu();

    void getInput(char* );
    int mainmenu();
    void login();
    void newregister();
    void list();
    void deletereg();
    void findreg();
    void findaverage();

};

#endif