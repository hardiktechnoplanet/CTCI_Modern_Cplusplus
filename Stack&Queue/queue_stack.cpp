/**
 * @brief Queue via Stacks
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * @file queue_stack.cpp
 * @author Hardik Garg
 */
#include <stack>
#include <iostream>

using namespace std;

stack <int> s1;
stack <int> s2;
int front;
	
/*A queue is FIFO (first-in-first-out) but a stack is LIFO (last-in-first-out). 
This means the newest element must be pushed to the bottom of the stack. To do 
so we first transfer all s1 elements to auxiliary stack s2. Then the newly arrived element 
is pushed on top of s2 and all its elements are popped and pushed to s1.*/

void add(int x)
{
	if (s1.empty())
	front=x;
	
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	
	s2.push(x);
	
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

/*The algorithm pops an element from the stack s1, because s1 stores always on its top 
the first inserted element in the queue. The front element of the queue is kept as front.*/

void remove()
{
	s1.pop();
	
	if(!s1.empty())
	front=s1.top();
}

/*Stack s1 contains all stack elements, so the algorithm checks s1 size to 
return if the queue is empty*/

bool isEmpty()
{
	return s1.empty();
}

/*The front element is kept in constant memory and is modified when we push or pop an element.*/

int peek()
{
	return front;
}

int main(int argc, char** argv) {

	add(5);
	add(4);
	add(9);
	
	cout<<isEmpty()<<endl;
	
	cout<<peek()<<endl;

	return 0;
}
