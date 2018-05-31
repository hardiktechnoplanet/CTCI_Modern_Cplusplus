
#include <stack>
#include <iostream>

using namespace std;
	
void print(stack<int>& data)
{
	while(!data.empty())
	{
		cout<<data.top()<<"\t";
		data.pop();
	}
}
void push(stack<int>& data, int x)
{
	data.push(x);
}

void sort(stack<int>& data)
{
	//helper stack
	stack <int> data_helper;
	
	while(!data.empty())
	{
		// pop out the first element
		int temp=data.top();
		data.pop();
		
		/*while helper stack is not empty and top
         of stack is greater than temp*/
		while(!data_helper.empty() && data_helper.top()>temp)
		{
			/* pop from helper stack and push
             it to the data stack*/
			data.push(data_helper.top());
			data_helper.pop();
		}
		
		// push temp in helper stack
		data_helper.push(temp);
	}
	
	/*copy rest of the elements*/
	while(!data_helper.empty())
	{
		data.push(data_helper.top());
		data_helper.pop();
	}
}

int main(int argc, char** argv) {
	stack <int> data;

	push(data,5);
	push(data,4);
	push(data,2);
	push(data,9);
	push(data,1);
	push(data,13);

	sort(data);
	print(data);

	return 0;
}
