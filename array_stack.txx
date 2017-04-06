// implement array_stack methods here

#include "array_stack.h"
#include <utility>
#include <stdexcept>

template <typename T>
ArrayStack<T>::ArrayStack(): body(nullptr), bodyCount(0), max(0)
{}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
  if(body != nullptr) delete [] body;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & oldList)
{
  max = oldList.max;
  bodyCount = oldList.bodyCount;
  body = max ? new T[max] : nullptr;
  std::copy(oldList.body, oldList.body+oldList.max, body);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack<T> oldList)
{
  swap(*this,oldList);

  return *this;
}

template <typename T>
void ArrayStack<T>::push(const T& item)
{
	if(bodyCount == max) 		//do we have room to insert?
	{
								//grow the items array
		T * oldBody  = body; 	//get addr of items array

		body = new T[max+10]; 	//doesn't overwrite old array

		for (int i = 0; i < max; i++) {
			body[i] = oldBody[i];
		}

		if(oldBody != nullptr) delete [] oldBody;

		max += 10;
	}
     
	// insert
	body[bodyCount] = item;
	bodyCount++;
}

template <typename T>
void ArrayStack<T>::pop()
{
	T * oldBody = body;

	if (bodyCount == 0) throw std::range_error("Array Stack is Empty");

	bodyCount--;
	body = new T[max];
	for (int i = 0; i < bodyCount; i++) {
		body[i] = oldBody[i];
	}

	if (oldBody != nullptr) delete[] oldBody;
}

template <typename T>
const T& ArrayStack<T>::top()
{
	if(bodyCount == 0) throw std::range_error("Array Stack is Empty");
	return body[bodyCount-1];
}

template <typename T>
bool ArrayStack<T>::isempty()
{
	if (bodyCount) return false;
	return true;
}

template <typename T>
void ArrayStack<T>::swap(ArrayStack<T>& x, ArrayStack<T>& y)
{
	std::swap(x.max, y.max);
	std::swap(x.bodyCount, y.bodyCount);
	std::swap(x.body, y.body);
}