/**
 * @brief Partition:
 * Write code to partition a linked list around a value x, such that all nodes less than x come
 * before all nodes greater than or equal to x. If x is contained within the list, the values of x
 * only need to be after the elements less than x (see below). The partition element x can appear
 * anywhere in the "right partition"; it does not need to appear between the left and right
 * partitions.
 *
 * EXAMPLE
 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 *
 * @file partition_list.h
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
 * @brief partition the list
 * Notes:
 * 1. In this approach, we start a "new"list (using the existing nodes). Elements bigger than the pivot element are
 *    put at the back and elements smaller are put at the head. Each time we insert an element, we update either
 *    the head or back.
 * 
 * @return return the modified head
 */
 
struct Node* list_partition(size_t x)
{

	auto back=head;
	auto curr=head;
	
	while(curr!=NULL)
	{
		auto next=curr->next;
		if(curr->data<x)
		{
			curr->next=head;
			head=curr;
		}
		else
		{
			back->next=curr;
			back=curr;
		}
		curr=next;
	}

	back->next=NULL;
	
	return head;
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
	
	cout<<"list after partition: "<<endl;
	head=list_partition(5);
	Print(head);
	
   	return 0;
}
