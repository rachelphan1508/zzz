
//HW8

#ifndef NODE_H
#define NODE_H

#include "book.h"

template <typename T> //T is gonna be Book in this case 
class Node{
	public:
		//default constructor, which will get called when
		// we create a node
                Node(T default_item = T());
		//destructor which will get called when we delete a node
		~Node();
		
		//accessor and mutator for the "item"- the data the
		// node holds
		T get_item() const;
		void set_item(const T& new_item);
		
		//accessor and mutator for the "next"- the pointer to
		// the next node in the list
		Node<T>* get_next() const;
		void set_next(Node<T>* next_item);

		
	private:
	
		Node* Next;
		Book item;
                
};

// constructor- sets the item to a value given by a parameter (or a default)
// , and the next to NULL
template <typename T>
Node<T>::Node(T default_item){
	item = default_item;
	Next = NULL; // note that the compiler knows what NULL is,
				 // as long as we include cstdlib
				 
}

template <typename T>
Node<T>::~Node(){
	Next = NULL; // because I'm really paranoid, and I want to
	             // make sure it's done, in case someone forgets
	
	// there's no need to set item to anything..
}

template <typename T>
T  Node<T>::get_item() const{
  return item;
 }
 
// Mutator function for the item
template <typename T>
void Node<T>::set_item(const T& new_item){
	item = new_item;
}


template <typename T>
Node<T>* Node<T>::get_next() const{
	return Next;
}

template <typename T>
void Node<T>::set_next(Node<T>* next_item){
	Next= next_item;   
}



#endif

