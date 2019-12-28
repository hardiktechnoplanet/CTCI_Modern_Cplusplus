/**
 * @brief Queue via Stacks
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * @file queue_stack.cpp
 * @author Hardik Garg
 */

//Solution 1
//https://www.youtube.com/watch?v=Wg8IiY1LbII
//Time Complexity:O(1) Amortized, Space Complexity: O(n)
class MyQueue {
public:
    
    /** Initialize your data structure here. */
    stack<int> pushStack,popStack;
    int front;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        //push the element to the push stack
        pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        //make sure that we don't have an empty popStack
        /* If the stack we can pop items from is empty then we need
        to populate it. All we do is put all items from the pushStack into the
        popStack.*/
        ensureThereAreItemsInPopStack();
        
        //if the popStack is still empty, it means that queue is empty, return -1
        if(!popStack.empty())
        {
            int frontElement=popStack.top();
            popStack.pop();
            return frontElement;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() 
    {
        //Ensure that the pop stack has an item to peek
        ensureThereAreItemsInPopStack();

        //Peek the item if the queue is not empty
        if (!popStack.empty()) 
        {
            int frontElement=popStack.top();
            return frontElement;
        }

        //If queue is empty
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty()&&popStack.empty();
        
    }
    
    void ensureThereAreItemsInPopStack()
    {
        if(popStack.empty())
        {
            while(!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
    }
};

///////////////////////////////////////////////Solution 2////////////////////////////////
//Solution 2
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
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
