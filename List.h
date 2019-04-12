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
        Node<T>* orig_list_pos = BookList; // holds the position of
	                                 // the thing we're copying
	                                 // in L
	if(orig_list_pos == NULL) // then L is empty..
	  BookList = NULL; //...and so are we
	else{
	  BookList = new Node<T>;
	  BookList->set_item(orig_list_pos->get_item());
	  Node<T>* new_list_end= BookList; // points to the last item in the
	                      // list we're creating
	  orig_list_pos = orig_list_pos->get_next();
	  
	  // this loop will continually copy items from the original
	  // list (pointed at by "orig_list_pos") to the new list
	  // (whose last item is pointed at by "new_list_end"), until
	  // the original list runs out of elements
	  while(orig_list_pos != NULL) {
	  	// the loop has 2 parts.  First, we create the new node,
	  	// and set it's value
	  	
	  	Node<T>* n = new Node<T>;
	  	n->set_item(orig_list_pos->get_item());
	  	n->set_next(NULL);
	  	orig_list_pos->set_next(n); // links n into the list
//	  	
	  	// now, we set up the next iteration
	  	new_list_end = n; //so it points to the last element in
	  	                   // the new list again
	  	orig_list_pos =new_list_end->get_next();
	  }
	  
	  // when we leave the loop, we have a whole new copy, 
	  // pointed at by theList.  The only thing we have to do
	  // is set the last element to point to NULL.
	  new_list_end->set_next(NULL);
	}
    //Node<T>* p = BookList;
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
                
                //Checked_Out->set_item(p->get_item());
                return true;
            }
                
        }
        orig_list_pos = orig_list_pos->get_next();
    }

}
//check if the book has been checked out or not
template <typename T>
bool List<T>:: Is_Book_Checked(Book thebook) {
    Node<T>* p = Checked_Out;
    while(p!= NULL ) {
        if (p->get_item().get_title() == thebook.get_title()) {
            return true;
        }
        p = p->get_next();
        
    }
    return false;
}
//return a book
template <typename T>
bool List<T> ::Check_In(const string& title) {
    Node<T>* p = BookList;
    Book thebook = Get_Book(title);
    if (!Is_Book_Checked(thebook)) {
        
        return false;
        
    }
    else {
        thebook.Increase_Quan();        
        cout << "You have successfully checked in the " << title << " book."
                << endl;
        return true;
    }
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
void List<T>:: DeepCopy(Node<T>* p, Node<T>* &copy){
	while (p != NULL)
	{
		{
			Node<T>* copy = new Node<T>;
			copy->set_item(p->get_item());
			copy->set_next(p->get_next());
			p = p->get_next();
		}
	}
}


#endif
