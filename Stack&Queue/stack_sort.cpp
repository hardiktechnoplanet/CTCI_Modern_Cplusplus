
#include <stack>
#include <iostream>

using namespace std;

stack <int> data;
stack <int> data_helper;
	
void print()
{
	while(!data.empty())
	{
		cout<<data.top()<<"\t";
		data.pop();
	}
}
void push(int x)
{
	if(data.empty())
	data.push(x);
	
	else
	{
	if(x<=data.top())
	data.push(x);
	
	else
	{
		while(x>data.top())// && data.size()>1)
		{
			cout<<"1"<<endl;
			int temp=data.top();
			cout<<"temp: "<<temp<<endl;
			data_helper.push(temp);
			data.pop();
			cout<<"size: "<<data.size()<<endl;
		}
		cout<<" second 2"<<endl;
		data.push(x);
		while(!data_helper.empty())
		{
			int temp1=data_helper.top();
			data.push(temp1);
			data_helper.pop();
		}
	}
	}
}

int main(int argc, char** argv) {

	push(5);
	push(4);
	push(2);
	push(9);
	
	print();

	return 0;
}
