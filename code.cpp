#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "code.h"
using namespace std;
Book books[100];
int n = 0;
void loadData()
{
    ifstream file("books.txt", ios::in | ios::out | ios::app);
    while (n < 100 && 
           file >> books[n].id 
                >> books[n].quantity 
                >> books[n].issuestatus
                >> books[n].title 
                >> books[n].author) 
    {
        n++;
    }
}
void addbook()
{
    Book mybook;
    cout << "Enter Book ID: ";
    cin>>mybook.id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, mybook.title);
    cout << "Enter Book Author: ";
    getline(cin,mybook.author);
    cout << "Enter Quantity: ";
    cin>>mybook.quantity;
    cout << "Enter Issue Status (0 for available, 1 for issued): ";
    cin>>mybook.issuestatus;
    books[n] = mybook;
     n++;
}
void displaybooks()
{
    cout << "Book List:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "ID: " << books[i].id;
        cout<< " Title: " << books[i].title;
        cout << " Author: " << books[i].author;
        cout << " Quantity: " << books[i].quantity;
        cout << " Issue Status: " << (books[i].issuestatus == 0? "Available": "Issued") << endl;
    }
}
void searchtitle()
{
    string searchtit;
    cout << "Enter title to search: "; 
    cin.ignore();
    getline(cin, searchtit);
    for(int i=0;i<=n;i++)
    {
        if(books[i].title==searchtit)
        {
            cout << "Book Found:\n";
            cout << "ID: " << books[i].id;
            cout<< " Title: " << books[i].title;
            cout << " Author: " << books[i].author;
            cout << " Quantity: " << books[i].quantity;
            cout << " Issue Status: " << (books[i].issuestatus == 0? "Available": "Issued") << endl;
            return;
        }
    }
}
    void searchauthor()
{
    string searchaut;
    cout << "Enter author to search: "; 
    cin.ignore();
    getline(cin, searchaut);
    for(int i=0;i<=n;i++)
    {
        if(books[i].title==searchaut)
        {
            cout << "Book Found:\n";
            cout << "ID: " << books[i].id;
            cout<< " Title: " << books[i].title;
            cout << " Author: " << books[i].author;
            cout << " Quantity: " << books[i].quantity;
            cout << " Issue Status: " << (books[i].issuestatus == 0? "Available": "Issued") << endl;
            return;
        }
    }
}
    void issuebook()
    {
        int bookid;
        cout << "Enter Book ID to issue: ";
        cin >> bookid;
        for (int i = 0; i < n; i++)
        {
            if (books[i].id == bookid)
            {
                if (books[i].quantity>0 && books[i].issuestatus == 0)
                {
                    books[i].issuestatus = 1;
                    books[i].quantity--;
                    cout << "Book issued successfully.\n";
                }
                else
                {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }

    }
void returnbook()
{
    int bookid;
    cout << "Enter Book ID to return: ";
    cin >> bookid;
    for(int i=0;i<n;i++)
    {
        if(bookid==books[i].id)
        {
            if(books[i].issuestatus==1)
            {
                books[i].issuestatus=0;
                books[i].quantity++;
                cout<<"Book returned successfully.\n";
            }
            else
            {
                cout<<"This book was not issued.\n";
            }
            return;
        }
    }
}
void saveData()
{
    ofstream file("books.txt");
    for (int i = 0; i < n; i++) {
        file << books[i].id << " "
             << books[i].quantity << " "
             << books[i].issuestatus << " "
             << books[i].title << " "
             << books[i].author << endl;
    }
    file.close();
}
#include <iostream>
#include <limits> // Required for cin.ignore and streamsize
// Assuming #include "code.h" or similar is present at the top of your full file

// Function prototypes (assuming these are in your header or defined earlier)
void loadData();
void saveData();
void addbook();
void displaybooks();
void searchtitle();
void searchauthor();
void issuebook();
void returnbook();

using namespace std;

// Helper function to display the menu for cleaner code
void showMenu() {
    cout << "\n=========================================" << endl;
    cout << "     📚 Library Management System 📚" << endl;
    cout << "=========================================" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Search by Title" << endl;
    cout << "4. Search by Author" << endl;
    cout << "5. Issue Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "7. Exit and Save" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    loadData();

    int choice = 0;

    do {
        showMenu();
        
        // 3. Input validation check
        if (!(cin >> choice)) {
            cout << "\n Invalid input type! Please enter a number (1-7)." << endl;
            // Clear the error flags on the stream
            cin.clear(); 
            // Discard the bad input up to the newline character
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and show the menu again
        }

        switch(choice)
        {
            case 1:
                addbook();
                break;
            case 2:
                displaybooks();
                break;
            case 3:
                searchtitle();
                break;
            case 4:
                searchauthor();
                break;
            case 5:
                issuebook();
                break;
            case 6:
                returnbook();
                break;
            case 7:
                cout << "\n✅ Saving data and exiting the program. Goodbye!" << endl;
                saveData(); // Save the final state of the array
                break;
            default:
                cout << "\n Invalid choice (" << choice << "). Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}