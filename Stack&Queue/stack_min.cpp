/**
 * @brief Stack Min
 * How would you design a stack which, in addition to push and pop, has a function min which returns
 * the minimum element? Push, pop and min should all operate in 0(1) time
 *
 * @file stack_min.cpp
 * @author Hardik Garg
 */
 
#include <stack>
#include <iostream>

using namespace std;


/**
 * @brief Stack Min
 * One stack is used to keep the track of min values
 */

stack <int> data_base;
stack <int> minimum;
	
int min()
{
	size_t max_val=INT_MAX;
	if(minimum.empty())
	return max_val;
	
	return minimum.top();
}

void push_data(int data)
{
	if(data<min())
	minimum.push(data);
	
	data_base.push(data);
}

void pop_data()
{
	if(data_base.top()==min())
	minimum.pop();
	
	data_base.pop();
}

int main(int argc, char** argv) {

	push_data(5);
	push_data(7);
	push_data(2);
	push_data(9);
	
	cout<<"the min value is: "<<min()<<endl;
	
	pop_data();
	cout<<"the min value is: "<<min()<<endl;
	
	pop_data();
	cout<<"the min value is: "<<min()<<endl;

	return 0;
}
