#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TO_DO_LIST.h"

using namespace std;

void addTask(vector<ToDoList>& tasks, const string& description)
{
    ToDoList newTask = {description, false};
    tasks.push_back(newTask);
    cout <<"Task Basariyla Eklendi " << endl;
}

void listTask(const vector<ToDoList>& tasks)
{
    if(tasks.empty())
    {
        cout << "TO DO LIST Boş " << endl;
        return;
    }
    cout << "TO DO LIST " << endl;
    for(size_t i = 0; i < tasks.size(); ++i)
    {
        tasks[i].printTask(i);
    }
}

void deleteTask(vector<ToDoList>& tasks, int deletednumber)
{
    if(deletednumber > 0 && deletednumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + deletednumber - 1);
        cout << "Görev başarıyla silindi!" << endl;
    }
    else 
    {
        cout << "Geçersiz görev numarası!" << endl;
    }
}

void loadTasks(vector<ToDoList>& tasks) {
    ifstream file("tasks.txt");
    if (!file) {
        cout << "Görev dosyası bulunamadı. Yeni bir liste oluşturulacak." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t delimiterPos = line.find('|');
        string description = line.substr(0, delimiterPos);
        bool isCompleted = stoi(line.substr(delimiterPos + 1));

        ToDoList newTask = {description, isCompleted}; 
        tasks.push_back(newTask);
    }

    file.close();
    cout << "Görevler başarıyla yüklendi!" << endl;
}

void saveTasks(const vector<ToDoList>& tasks) {
    ofstream file("tasks.txt");
    for (const ToDoList& task : tasks) {
        file << task.description << "|" << task.isCompleted << endl;
    }
    file.close();
    cout << "Görevler başarıyla kaydedildi!" << endl;
}

void completeTasks(vector<ToDoList>& tasks, int completednumber)
{
    if(completednumber > 0 && completednumber <= tasks.size())
    {
        tasks[completednumber - 1].isCompleted = true;
        cout << "Gorev Basariyla Tamamlandi" << endl;
    }
    else {
        cout << "Gecersiz Gorev Numarasi " << endl;
    }
}

int main()
{
    int choice;
    vector<ToDoList> tasks;
    loadTasks(tasks);
    while(true)
    {
        system("clear");
        cout << "******* TO DO LIST ******* \n1-Görev Ekle \n2-Görevleri Listele \n3-Görev Sil \n4-Görevi Tamamla \n5-EXIT \n";
        cout << "Seçim : ";
        cin >> choice;

        if(choice == 1)
        {
            string description;
            cout << "Görevi Giriniz : ";
            cin.ignore(); 
            getline(cin, description);
            addTask(tasks, description);
        }
        
        else if(choice == 2)
        {
            listTask(tasks);
            cout << "\nDevam etmek için bir tuşa basın...";
            cin.ignore();
            cin.get();
        }

        else if(choice == 3)
        {
            listTask(tasks);
            cout << "Silmek Istediginiz Gorevi Secin : ";
            int taskNum;
            cin >> taskNum;
            deleteTask(tasks, taskNum);
            cout << "\nDevam etmek için bir tuşa basın...";
            cin.ignore();
            cin.get();
        }

        else if(choice == 4)
        {
            listTask(tasks);
            cout << "Tamamlamak Istediginiz Gorevi Secin : ";
            int taskNum;
            cin >> taskNum;
            completeTasks(tasks, taskNum);
            cout << "\nDevam etmek için bir tuşa basın...";
            cin.ignore();
            cin.get();
        }

        else if (choice == 5)
        {
            saveTasks(tasks);  
            cout << "Programdan Cıkıs Yapiliyor " << endl;
            break;
        }

        else 
        {
            cout << "Gecersiz Secim " << endl;
        }
    }
}