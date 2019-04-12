//Hanh Phan - HW8 - CS 210
#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>
#include <string>
#include "book.h"
#include <vector>

using namespace std;

template <typename T>
class List{
  public:
	// constructor- creates an empty list
	List();
        ~List();
        List(const List<T>& L);
        bool Check_Out(const string& title);
        bool Check_In(const string& title);
        bool Exist(string title);
        Book Get_Book(string title);
        void Insert_User(string ID);
        bool Is_Book_Checked(Book thebook);
        void DeepCopy(Node<T>* p, Node<T>* &copy);
       
        void Insert(const T& new_item);
        void Print_Library() const;
        void Print_Checked();
        void  Insert_Checked(const T& new_item);

  private:
      
      //vector<string> users;
      Node<T>* Checked_Out;
      Node<T>* BookList;
      
              
            
};
template <typename T>
List<T>::List(const List<T>& L){
	BookList = L.BookList;
}
//Print the library
template <typename T>
void List<T>::Print_Library() const{

	Node<T>* p = BookList;
	while(p != NULL){
	  cout << p->get_item().get_title() << " " << p->get_item().get_num()
                  << endl;
	  p = p->get_next();
	 }
}
//Insert the user ID
//template <typename T>
//void List<T>:: Insert_User(string ID) {
  //  users.push_back(ID);
//}
//set up List
template <typename T>
List<T>::List(){
	BookList = NULL; // so that we have a consistent way to 
	                // check for an empty list
        //users.resize(0);
        Checked_Out = NULL;
        
}
//delete the List
template <typename T>
List<T>::~List(){
	Node<T>* p = BookList;
	Node<T>* kill = BookList;
	while(p!= NULL){
		kill = p;
		p = p->get_next();
		delete kill;
	}
	BookList = NULL; // just in case
}

//check if the book is still available
template <typename T>
bool List<T>:: Exist(string title) {
    Node<T>* p = BookList;
    while (p!=NULL){
        if((p->get_item().get_title() == title) && (p->get_item().get_num()==0)){
            return false;
        }
        p=p->get_next();
    }
    return true;
}


//Insert new item

template <typename T>
void List<T>::Insert(const T& new_item){
    Node<T>* p = BookList;
    Node<T>* n = new Node<T>;
    Node<T>* q;
    n-> set_item(new_item);
    if (p==NULL ){
        BookList = n;
    }
    else {
        q = p->get_next();
        if (p->get_item().get_title() > n->get_item().get_title()) {
            n->set_next(p);
            BookList = n;
        }
        else {
            while (q!= NULL && q->get_item().get_title() < n->get_item().get_title()) {
                //stop the first time q->get_item() > n->get_item()
                p = q;
                q = q->get_next();//get to the next q
            }
            p->set_next(n);
            n->set_next(q);
        }
        
    }    
    
}

//get the book from its title
template <typename T>
Book List<T> :: Get_Book(string title) {
    Node<T>* p = BookList;
    while (p!=NULL){
        if(p->get_item().get_title() == title) {
            return p->get_item();
        }
        p=p->get_next();
    }
    return BookList->get_item();
}
//check out a book
template <typename T>
bool List<T> ::Check_Out(const string& title) {
        
    Node<T>* orig_list_pos = BookList;
    //List<T>* n = new List;
    //n->Insert(p->get_item());
    //n->set_next(NULL);
    while(orig_list_pos!=NULL) {
        if (orig_list_pos->get_item().get_title() == title) {
            if(orig_list_pos->get_item().get_num() ==0) {
                return false;
            }
            else {
                orig_list_pos->get_item().Reduce_Quan();
                Insert_Checked(orig_list_pos->get_item());
                return true;
            }
                
        }
        orig_list_pos = orig_list_pos->get_next();
    }
    return false;

}

//return a book
template <typename T>
bool List<T> ::Check_In(const string& title) {
    Node<T>* p = BookList;
    Node<T>* n = Checked_Out;
    while(n!= NULL ) {
        if (n->get_item().get_title() == n->get_item().get_title()) {
            while(p!=NULL) {
                if (p->get_item().get_title() == n->get_item().get_title()) {
                    p->get_item().Increase_Quan();
                }
                p = p->get_next();
            }
            return true;
        }
        n = n->get_next();
    }
    return false;
}


template <typename T>
void List<T> :: Print_Checked() {
    Node<T>* p = Checked_Out;
    if (p==NULL) {
        cout << "You have not checked any book out." << endl;
    }
	while(p != NULL){
	  cout << p->get_item().get_title() << " " ;
	  p = p->get_next();
	 }
    
} 

template <typename T>
void List<T>:: Insert_Checked(const T& new_item) {
    Node<T>* p = Checked_Out;
    Node<T>* n = new Node<T>;
    Node<T>* q;
    n-> set_item(new_item);
    if (p==NULL ){
        Checked_Out = n;
    }
    else {
        q = p->get_next();
        if (p->get_item().get_title() > n->get_item().get_title()) {
            n->set_next(p);
            Checked_Out = n;
        }
        else {
            while (q!= NULL && q->get_item().get_title() < n->get_item().get_title()) {
                //stop the first time q->get_item() > n->get_item()
                p = q;
                q = q->get_next();//get to the next q
            }
            p->set_next(n);
            n->set_next(q);
        }
        
    }    
}

#endif
