/**
 * @brief Return Kth to Last
 * Write a function to find the kth to last element of a singly linked list
 *
 * @file kth_toLast.h
 * @author Hardik Garg
 */
 
#include <iostream>

using namespace std;

//structure of the node
struct Node{
	int data;
	struct Node* next;
};

//declare head node globally
struct Node* head;

//function to print the linked list
void Print()
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
 * @brief returns kth node to the last node
 * Notes:
 * 1. Running time O(N), Memory complexity O(1)
 * 2. Two pointers are used ,ptr1 and ptr2. Place them k nodes apart in the linked list by putting ptr2 
      at the beginning and moving ptr1 k nodes into the list. Then, move them at the same pace, 
	  ptr1 will hit the end of the linked list after LENGTH - k steps. At that point, ptr2 will be 
	  LENGTH - k nodes into the list, or k nodes from the end.
 *
 * @return return the ptr2 data value
 */
 
int list_partition(size_t x)
{
	auto front=head;
	auto back=head;
	
	while(head!=NULL)
	{
		if(head->data<x)
		{
			node->next=front;
			head=front;
		}
		else
		{
			back->next=head;
			back=head;
		}
		head=head->next;
	}
	back->next=NULL;
	return front;
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
	Print();
	
	cout<<"list after partition: "<<list_partition(4)<<endl;
	Print();
	
   	return 0;
}
