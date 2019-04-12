#include "Book.h"
#include <string>

//Get title and quantity
string Book:: get_title() {
    return title;
}

int Book:: get_num() {
    return num_of_books;
}


void Book:: set_num(int num) {
    
    num_of_books = num;
}
void Book:: set_title(string tit) {
    title = tit;
}

void Book:: Reduce_Quan() {
    num_of_books = num_of_books -1;
    
}

void Book:: Increase_Quan(){
    num_of_books = num_of_books +1;
}

bool operator< (Book &B1, Book &B2) {
    if (B1.get_title() <B2.get_title()){
        return true;
    }
    else return false;
}