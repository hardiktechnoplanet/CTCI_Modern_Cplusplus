/**
 * @brief Remove duplicate values from the linked list
 * Write code to remove duplicates from an unsorted linked list
 *
 * @file remove_duplicates.cpp
 * @author Hardik Garg
 */
 
#include <iostream>
#include <unordered_set>

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
 * @brief remove duplicate values 
 * Notes:
 * 1. Running time O(N)
 * 2. This function iterates through the linked list, adding each element to a unordered_set. When
      a duplicate element is discovered, remove the element and continue iterating. Do this all in one
      pass since we are using a linked list.
 *
 */

void remove_duplicate()
{
	struct Node* node=head;
	
	unordered_set <int> seen_elements;
	
	while(node!=NULL && node->next!=NULL)
	{
		seen_elements.insert(node->data);
		if(seen_elements.find(node->next->data)!=seen_elements.end()){
		node->next=node->next->next;
	}
		node=node->next;
	}
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
	
	remove_duplicate();
	
	cout<<"linked list after the removal of duplicate values: "<<"\t";
	Print();
	
   	return 0;
}
