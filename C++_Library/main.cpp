#include "Library.h"

void addBook(vector<Library>&library, const string& title, const string& author, const string& ISBN)
{
    Library newBook = {title, author, ISBN, false};
    library.push_back(newBook);
    cout << "Book Added Successfully: "<< title <<endl;
    cout << "\nPress any key to continue....";
    cin.get();

}

void listallBooks(const vector<Library>& library)
{
    if(library.empty())
    {
        cout << "There are no books in the library." << endl;
        return;
    }
    cout << "Books in the Library : " << endl;
    for (const auto& librarys :library )
    {
        cout << "Title  : " << librarys.title << endl;
        cout << "Author : " << librarys.author << endl;
        cout << "ISBN   : " << librarys.ISBN << endl;
        cout << "Status : " << (librarys.isLoaned ? "Ödünç Verildi" : "Müsait")  << endl;
        cout <<"-------------------------" <<endl;
    }

}

void loadBooks(vector<Library>& library)
{
    ifstream file("books.txt");
    if (!file) {
        cout << "Book file not found. A new list will be created." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        size_t firstDelimiterPos = line.find('--');
        size_t secondDelimiterPos = line.find('--', firstDelimiterPos + 2);
        size_t thirdDelimiterPos = line.find("--", secondDelimiterPos + 2);

        string title = line.substr(0, firstDelimiterPos);
        string author = line.substr(firstDelimiterPos + 2, secondDelimiterPos - firstDelimiterPos - 2);
        string ISBN = line.substr(secondDelimiterPos + 2, line.find('--', secondDelimiterPos + 2) - secondDelimiterPos - 2);
        bool isLoaned = stoi(line.substr(thirdDelimiterPos + 2)) == 1;
        
        Library newBook = {title, author, ISBN, isLoaned};
        library.push_back(newBook);
    }

    file.close();
    cout << "Book List loaded successfully!" << endl;
}

void saveBooks(const vector<Library>& library)
{
    ofstream file("books.txt");
    for(const Library& librarys : library )
    {
        file << librarys.title << "--" << librarys.author << "--" << librarys.ISBN << "--" << librarys.isLoaned << endl;
    }
    file.close();
    cout << "Book List saved successfully!" << endl;
}

void LendBook(vector< Library>& library, const string& ISBN)
{
    for(auto& librarys: library)
    {
        if(librarys.ISBN == ISBN)
        {
            if(librarys.isLoaned)
            {
                cout <<"This book has already been loaned." <<endl;
            }
            else{
                librarys.isLoaned = true;
                cout << "The book was loaned successfully: " << librarys.title<< endl;
            }
            return;
        }
    }
    cout << "No books matching ISBN found." << endl;
}

void returnBook(vector<Library>& library, const string& ISBN)
{
    for(auto& librarys : library)
    {
        if(librarys.ISBN == ISBN)
        {
            if(!librarys.isLoaned)
            {
                cout << "This book is already in the library" << endl;
            }
            else
            {
                librarys.isLoaned = false;
                cout << "Book Returned Successfully --> " << librarys.title <<endl;
            }
            return;
        }
    }
    cout << "Invalid ISBN number."<< endl;
}

void searchBook(const vector<Library>& library, const string& title)
{
    for(const auto& librarys: library)
    {
        if(librarys.title == title)
        {
            cout << "Title  : " << librarys.title << endl;
            cout << "Author : " << librarys.author << endl;
            cout << "ISBN   : " << librarys.ISBN << endl;
            cout << "Status : " << (librarys.isLoaned ? "Ödünç Verildi" : "Müsait")  << endl;
            cout <<"-------------------------" <<endl; 
            return;
        }

    }
    cout << "Invalid title" << endl;
}

int main()
{
    int choice; 
    vector<Library>library;
    loadBooks(library);

    while (true)
    {
        system("clear");

        cout << "\n Library Management System \n" << endl;
        cout << "1. Add Book (kitap Ekle) \n" <<endl;
        cout << "2. List of Books (Kitapları Listele)\n" <<endl;
        cout << "3. Lend a Book (Ödünç Al) \n" <<endl;
        cout << "4. Return Book (Iade Et) \n" <<endl;
        cout << "5. Search a Book (Kitap Ara) \n" <<endl;
        cout << "6. EXIT (CIKIS) \n" <<endl;
        cout << "Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            string title, author, ISBN;
            cout << "Title of the Book : ";
            cin.ignore();
            getline(cin, title);
            cout << "Author of the Book : ";
            getline(cin, author);
            cout << "ISBN of the Book : ";
            getline(cin, ISBN);
            addBook(library, title, author, ISBN);

        }
        else if (choice == 2)
        {
            listallBooks(library);
            cout << "\nPress any key to continue....";
            cin.ignore();
            cin.get();
        }
        else if (choice == 3)
        {
            string ISBN;
            cout << "Enter the ISBN Number of the Book You Want to Lend : ";
            cin.ignore();
            getline(cin,ISBN);
            LendBook(library, ISBN);
            cout << "\nPress any key to continue....";
            cin.get();


        }
        else if (choice == 4)
        {
            string ISBN;
            cout << "Enter the ISBN Number of the Book You Want to Return : ";
            cin.ignore();
            getline(cin,ISBN);
            returnBook(library, ISBN);
            cout << "\nPress any key to continue....";
            cin.get();
        }
        else if(choice == 5)
        {
            string title;
            cout << "Enter the name of the book you want to search : " ;
            cin.ignore();
            getline(cin, title);
            searchBook(library, title);
            cout << "\nPress any key to continue....";
            cin.get();
        }
        else if (choice == 6)
        {
            saveBooks(library);
            break;
        }
       

    }

}

