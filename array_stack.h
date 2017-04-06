// define your class here

#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include "abstract_stack.h"
#include <iostream>

template <typename T>
class ArrayStack: public AbstractStack<T>
{
public:
	
	// Constructor
	ArrayStack();

	// Destructor
	~ArrayStack();

	// copy constructor
	ArrayStack(const ArrayStack & oldList);

	// copy assignment
	ArrayStack& operator=(ArrayStack oldList);

	// push an item of type T into the stack
	// Throws std::bad_alloc on memory allocation failure
	void push(const T& item);

	// pop (remove) the top item from the stack
	// Throws error if stack is empty
	void pop();

	// return item at the top of the stack
	// Throws error if stack is empty
	const T& top();

	// returns true if the stack is empty
	bool isempty();

	//for copy-swap idiom used in copy operator
	void swap(ArrayStack<T>& x, ArrayStack<T>& y);

private:
	T* body;
	long int bodyCount;
	long int max;
};

#include "array_stack.txx"

#endif // _ARRAY_STACK_H_