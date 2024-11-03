#include <iostream>
#include "menu.h"
#include "Dogum.h"
#include "lesson.h"
#include "name.h"
#include "student.h"
#include <fstream>
#include <string>


using namespace std;
Dogum dgm;
student stdn;
lesson lsn;
name names;


menu::menu(/**/)
{
}

menu::~menu()
{
}


void menu:: getInput(char* ptr)
{
    scanf(" %[^\n]s",ptr);
}
int menu :: mainmenu()
{
    int choice;
    cout<<endl;
    cout<<"Student Lesson Registeration Application " <<endl;

    cout <<"[1] New Registeration" <<endl;
    cout <<"[2] List All Student" <<endl;
    cout <<"[3] Delete Student" <<endl;
    cout <<"[4] Find Student" <<endl;
    cout <<"[5] Find Highest GPA " <<endl;
    cout <<"[0] EXIT" <<endl;
    cout <<"Your Choice : "; cin>>choice;
    system("clear");
    return choice;
}

void menu:: login()
{
    int choice = mainmenu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1: newregister();  break;
        case 2: list(); break;
        case 3: deletereg(); break; 
        case 4: findreg(); break;
        case 5: findaverage(); break;

        default:
        cout<< "Invalid Choice...." << endl;
            break;
        }
        choice = mainmenu();
    }
    cout <<"BYE BYE .... :)" << endl;


}

void menu:: newregister()
{
    char inputs[30];
    int number;
    cout<<"REGISTERATION"<<endl;
    cout<<"Name: ";
    getInput(inputs);
    names.setName(inputs);
    cout<<"Surname: ";
    getInput(inputs);
    names.setSurname(inputs);

    cout<<"Date of Birth " << endl;
    cout<<"Day: ";
    getInput(inputs);
    number = atoi(inputs);
    dgm.setDay(number);

    cout<<"Month: ";
    getInput(inputs);
    number = atoi(inputs);
    dgm.setMonth(number);
    
    cout<<"Year: ";
    getInput(inputs);
    number = atoi(inputs);
    dgm.setYear(number);


    cout<<"Lesson Code: ";
    getInput(inputs);
    number = atoi(inputs);
    lsn.setLessonCode(number);

    cout<<"Lesson: ";
    getInput(inputs);
    lsn.setLesson(inputs);

    cout<<"Number: ";
    getInput(inputs);
    number = atoi(inputs);
    stdn.setNumber(number);

    cout<<"GPO: ";
    getInput(inputs);
    double gpo = atof(inputs);
    stdn.setAverage(gpo);

    ofstream file("student.txt",ios::app);

    stdn.Save(dgm, lsn,names,stdn.getNumara(),stdn.getAverage());

    file.write((char*)&stdn, sizeof(student) );
    cout<<"REGISTRATION COMPLETED"<< endl;
    file.close();
    stdn.Show();

}
void menu:: list()
{
    ifstream file("student.txt");
    int count= 0;
    if (!file) {
    cout << "File could not be opened." << endl;
    return; 
    }

    while (file.read((char*)&stdn, sizeof(student) ))
    {
        stdn.Show();
        cout<<"********************"<<endl;
        count ++;
    }
    cout<< endl;
    cout<<"LISTED COMPLETED"<< endl;
    cout<<"Number of Student : "<<count<< endl;
    file.close();
   

}
void menu:: deletereg()
{
    list();
    int numbers;
    char input[30];
    bool result = false;
    cout<<endl;
    cout<< "Student Number : ";
    getInput(input);
    numbers = atoi(input);

    ifstream file("student.txt");
    ofstream file2("newfile.txt", ios::app);

    if (!file) {
    cout << "File could not be opened." << endl;
    return; 
    }

    while (file.read((char*)&stdn, sizeof(student) ))
    {
        if (numbers == stdn.getNumara())
        {
            result = true;
        }
        else
        {
            file2.write((char*)&stdn, sizeof(student));
        }
    }
    file.close();
    file2.close();
    if (!result)
    {   
        system("clear");
        cout <<"Invalid Student Number"<<endl;
        cout<<endl;

    }
    else
    {
        remove("student.txt");
        rename("newfile.txt", "student.txt");
        cout <<"Student Deleted Succesfully"<<endl;

    }
    

}
void menu:: findreg()
{
    list();
    int numbers;
    char input[30];
    bool result = false;
    cout<<endl;
    cout<< "Student Number : ";
    getInput(input);
    numbers = atoi(input);

    ifstream file("student.txt");

    if (!file) {
    cout << "File could not be opened." << endl;
    return; 
    }

    while (file.read((char*)&stdn, sizeof(student) ))
    {
        if (numbers == stdn.getNumara())
        {
            system("clear");
            
            stdn.Show();
            cout<<"********************"<<endl;
            
            result = true;
            break;
        }
    }
    if (!result)
    {   
        system("clear");
        cout <<"Invalid Student Number"<<endl;
        cout<<endl;

    }
    
    file.close();
}
void menu:: findaverage()
{

    double highest;
    student s2;
    cout<<endl;
    s2.setAverage(0);
    ifstream file("student.txt");

    if (!file) {
    cout << "File could not be opened." << endl;
    return; 
    }

    while (file.read((char*)&stdn, sizeof(student) ))
    {
        if (s2.getAverage() < stdn.getAverage())
        {
            s2 = stdn;
        }
    }

    file.close();
    s2.Show();
}