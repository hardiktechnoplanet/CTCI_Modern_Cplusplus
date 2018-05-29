/**
 * @brief Palindrome
 * A function to check if a linked list is a palindrome
 *
 * @file palindrome.cpp
 * @author Hardik Garg
 */
 
#include <iostream>
#include <stack>

using namespace std;

//structure of the node
struct Node{
	int data;
	struct Node* next;
};

//declare head node globally
struct Node* head;

//function to print the linked list
void Print(struct Node* head)
{
	struct Node* node=head;
	
	while(node!=NULL)
	{
		cout<<node->data<<"\t";
		node=node->next;
	}
	cout<<endl;
}

/**
 * @brief Palindrome
 * Notes:
 * 1. At each step in the loop, we push the data from the slow runner onto a stack. When the fast runner hits the 
      end of the list, the slow runner will have reached the middle of the linked list. By this point, the stack 
	  will have all the elements from the front of the linked list, but in reverse order. Now, we simply iterate 
	  through the rest of the linked list. At each iteration, we compare the node to the top of the stack. If we 
	  complete the iteration without finding a difference, then the linked list is a palindrome.
 * 
 * @return return ture or false
 */
 
bool palindrome()
{
	stack <int> first_half {};
	
	auto fast_itr=head;
	auto slow_itr=head;
	
	while(fast_itr!=NULL && fast_itr->next!=NULL)
	{
		first_half.push(slow_itr->data);
		slow_itr=slow_itr->next;
		fast_itr=fast_itr->next->next;
	}
	
	/*In case of odd number of elements,skip the middle element*/
	if(fast_itr!=NULL)
	slow_itr=slow_itr->next;
	
	while(slow_itr!=NULL)
	{
		if(first_half.top()!=slow_itr->data)
		{
			return false;
		}
		
		first_half.pop();
		slow_itr=slow_itr->next;
	}
	return true;
}	
	
//function to insert nodes in the linked list
void Insert(size_t x)
{
	struct Node* node=(Node*)malloc(sizeof (struct Node));
	node->data=x;
	node->next=NULL;
	
	//if list is empty
	if(head!=NULL)
	{
		node->next=head;
	}
	head=node;
}

int main(int argc, char** argv) {
	head=NULL;
	printf("how many numbers you want to insert?\n");
	size_t n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		printf("enter the numbers\n");
		scanf("%d",&x);
		Insert(x);
	}
	
	cout<<"the entered linked list is: "<<"\t";
	Print(head);
	
	if(palindrome()==true)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
		
   	return 0;
}
