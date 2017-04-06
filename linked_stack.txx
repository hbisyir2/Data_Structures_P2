// implement linked_stack methods here

#include "linked_stack.h"
#include <utility>
#include <stdexcept>

template <typename T>
LinkedStack<T>::LinkedStack(): start(nullptr), size(0) {}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
  while(start != nullptr){
    Node<T> * temp = start;
    start = start->next;
    delete temp;
  }
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& x): start(nullptr), size(0)
{
  Node<T> * x_curr = x.start;
  Node<T> * this_prev =  nullptr;

  while(x_curr != nullptr){
    Node<T> * this_curr =  new Node<T>(x_curr->body);
    this_curr->prev = this_prev;
    if(this_prev != nullptr) this_prev->next = this_curr;
    else start = this_curr;
    this_prev = this_curr;
    x_curr = x_curr->next;
    size++;
  }

}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> x)
{
	// Combine copy constructor and destructor
	// Destruct one LinkedStack and create another using the code
	// from the copy constructor

  swap(*this, x);
  return *this;
}

template <typename T>
void LinkedStack<T>::push(const T& item)
{
	Node<T> * current = start;
	Node<T> * newItem = new Node<T>(item);
	newItem->next = nullptr;
	if (current == nullptr) {
		newItem->prev = nullptr;
		start = newItem;
	}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		newItem->prev = current;
		current->next = newItem;
	}
	size++;
	// delete item?????
}

template <typename T>
void LinkedStack<T>::pop()
{
	Node<T> * toDelete = start;
	
	if (start == nullptr) throw std::range_error("Linked Stack is Empty");

	if (size == 1) {
		toDelete = toDelete->next;
		start = nullptr;
		delete toDelete;
	}
	else {
		while (toDelete->next != nullptr) {
			toDelete = toDelete->next;
		}
		Node<T> * newEnd = toDelete->prev;
		newEnd->next = nullptr;
		if (toDelete != nullptr) delete toDelete;
	}
	size--;
}

template <typename T>
const T& LinkedStack<T>::top()
{
	Node<T> * current = start;
	
	if (current == nullptr) throw std::range_error("Linked Stack is Empty");
	
	while(current->next != nullptr){
		current = current->next;
	}
	return current->body;
}

template <typename T>
bool LinkedStack<T>::isempty()
{
	if (start == nullptr) return true;
	return false;
}

template <typename T>
void LinkedStack<T>::swap(LinkedStack<T>& x, LinkedStack<T>& y)
{
	std::swap(x.start, y.start);
	std::swap(x.size, y.size);
}