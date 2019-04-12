#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;
class Book {
private:
    string title;
    int num_of_books;
    
public:


    //Book (string tit, int num);
    string get_title ();
    
    int get_num ();
    void set_num(int num);
    void set_title(string tit);
    //reduce its count by 1
    void Reduce_Quan() ;
    //increase its count by 1
    void Increase_Quan();

};
#endif
