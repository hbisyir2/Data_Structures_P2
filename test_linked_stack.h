#include <string>
#include <cxxtest/TestSuite.h>

#include "linked_stack.h"

#include <cstdlib>
#include <stack>

template class LinkedStack<int>;

class LinkedStackTests : public CxxTest::TestSuite
{
public:
   void testTODO( void )
   {
		LinkedStack<int> lst;
		// Test isepmty
		TS_ASSERT(lst.isempty() == true);
		lst.push(1);
		TS_ASSERT(lst.top() == 1);
		// Test pop with 1 element
		lst.pop();
		// Test isempty again
		TS_ASSERT(lst.isempty() == true);
		lst.push(2);
		TS_ASSERT(lst.top() == 2);
		lst.push(14);
		TS_ASSERT(lst.top() == 14);
		lst.pop();
		// Test top after a pop
		TS_ASSERT(lst.top() == 2);
		TS_ASSERT(lst.isempty() == false);
		// Test copy constructor
		LinkedStack<int> lst2(lst);
		TS_ASSERT(lst2.top() == 2);
		TS_ASSERT(lst2.isempty() == false);
		// Test copy operator
		LinkedStack<int> lst3;
		LinkedStack<int> lst4;
		lst3.push(5);
		lst4 = lst3;
		TS_ASSERT(lst3.top() == 5);
		TS_ASSERT(lst4.top() == 5);
		lst4.pop();
		TS_ASSERT(lst4.isempty() == true);
		LinkedStack<int> lst5;
		lst3 = lst5;
		TS_ASSERT(lst3.isempty() == true);
		LinkedStack<int> lst6(lst5);
		TS_ASSERT(lst6.isempty() == true);
		TS_ASSERT_THROWS(lst5.top(), std::range_error);
		TS_ASSERT_THROWS(lst5.pop(), std::range_error);
   }
};
