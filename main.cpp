//Hanh Phan - HW8 - CS 210
#include <iostream>
#include <cstdlib>
#include "book.h"
#include "List.h"
#include "node.h"
#include <string>
#include <vector>

using namespace std;


int main()
{
    List<Book> Library;
    cout << "How many books do the library have? ";
    int num;
    cin >> num;
    for (int i=0;i < num;i++ ) {
        
        cout << "Enter the book name: " << endl ;
        string name;
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter the quantity: ";
        int num_of_book;
        cin >> num_of_book;
        Book mybook;
        mybook.set_title(name);
        mybook.set_num(num_of_book);
        Library.Insert(mybook);
        
    }

    string more_user = "y";
    
    while (more_user == "y" ){
    cout << "Enter your ID" << endl;
    string ID;
    cin >> ID;
    
    string again = "y";
    int answer;
    string title;
    bool check;
    while (again == "y") {
        cout << "Menu of choices:" << endl;
        cout << "1 for Check Out, 2 for Return, 3 for List of checked out " << 
        "books, 4 for the Library." << endl;
        cin >> answer;
        if (answer==1) {
            cout << "What is the title of the book?";
            cin >> title;
            check = Library.Check_Out(title);
            if (!check) {
                cout << "The book is not available." << endl;
            }
            else {
                cout << "You have successfully checked out the " << title << " book.";
            }
            
        }
        if (answer ==2) {
            cout << "What is the title of the book?";
            cin >> title;
            check = Library.Check_In(title);
            if (!check) {
                cout << "The book has not been checked out yet. " << endl;
            }
            else {
                cout << "You have successfully returned the " << title <<
                        " book." << endl;
            }
        }
        if (answer == 3) {
            cout << "List of books that you checked out: " << endl;
            Library.Print_Checked();
        }
        if (answer ==4) {
            cout << "Here's the books and quantity." << endl;
            Library.Print_Library();
        }
        cout << "Continue? (y for yes)" << endl;
        cin >> again;
        
        
        
    }
    cout << "Another user? (y for yes)" ;
    cin >> more_user;
    }
    
    
    return 0;
    
    }
