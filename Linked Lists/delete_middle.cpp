/**
 * @brief delete the middle node
 * Implement an algorithm to delete a node in the middle (i.e., any node but
 * the first and last node, not necessarily the exact middle) of a singly linked list, given only
 * access to that node. EXAMPLE: Input: the node c from the linked list a -> b -> c -> d -> e -> f
 * Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f
 *
 * @file delete_middle.cpp
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
 * @brief delete the middle node with access to that node only
 * Notes:
 * 1. Running time O(N), Memory complexity O(1)
 * 2. Copy the next node data to the middle node
 */

void delete_middle(struct Node* middle)
{
	if(middle==NULL)
	return;
	if(middle->next==NULL)
	return;
	
	middle->data=middle->next->data;
	middle->next=middle->next->next;
}

/**
 * @brief delete the middle node with access to the head node
 * Notes:
 * 1. Running time O(N), Memory complexity O(1)
 * 2. Find the size of the linked list, go to the middle
      and adjust the link.
 */

/*
void delete_middle()
{
	auto node=head;
	size_t count=0;
	
	//get the linked list length to find the middle
	while(node!=NULL)
	{
		++count;
		node=node->next;
	}
	
	node= head;
	for(size_t i=0;i<count/2-1;++i)
	{
		node=node->next;
	}
	node->next=node->next->next;
}
*/

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
	
	/*delete the middle node if we can access that node only(note the head node)*/
	
	//point the node at the middle of the linked list
	auto node=head;
	
	size_t count=0;
	
	//get the linked list length to find the middle
	while(node!=NULL)
	{
		++count;
		node=node->next;
	}
	
	node= head;
	for(size_t i=0;i<count/2;++i)
	{
		node=node->next;
	}
	cout<<"node: "<<node->data<<endl;

	cout<<"the linked list after deleting the middle node: "<<"\t";
	delete_middle(node);
	
	Print();
	
   	return 0;
}
