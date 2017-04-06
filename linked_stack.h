// define your class here

#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "abstract_stack.h"
#include <iostream>

template <typename T>
class LinkedStack: public AbstractStack<T>
{
public:
	
	// Constructor
	LinkedStack();
	
	// Destructor
	~LinkedStack();
	
	// copy constructor
	LinkedStack(const LinkedStack & oldList);

	// copy assignment
	LinkedStack& operator=(LinkedStack oldList);
	
	// Push an item to top of the stack
	void push(const T& item);
	
	// Pop (remove) item from top of the stack
	// Throws error if stack is empty
	void pop();
	
	// Returns top element of stack
	// Throws error if stack is empty
	const T& top();
	
	// Returns true if stack is empty
	bool isempty();
	
	//for copy-swap idiom used in copy operator
	void swap(LinkedStack<T>& x, LinkedStack<T>& y);

private:
	
	template<typename U>
	struct Node{
		U body;
		Node<U> * next;
		Node<U> * prev;

		Node(): next(nullptr), prev(nullptr){};
		Node(const U& d): body(d), next(nullptr), prev(nullptr){};
	};

	Node<T> * start;
	std::size_t size;
};

#include "linked_stack.txx"

#endif // _LINKED_STACK_H_