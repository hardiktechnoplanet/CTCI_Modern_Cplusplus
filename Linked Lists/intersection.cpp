/**
 * @brief Intersection of 2 Linked Lists 
 *Given two (singly) linked lists, determine if the two lists intersect. Return the
  intersecting node. Note that the intersection is defined based on reference, not value. That is, if the
  kth node of the first linked list is the exact same node (by reference) as the jth node of the second
  linked list, then they are intersecting. 
 *
 * @file palindrome.cpp
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

/**
 * @brief Intersection of 2 linked lists
 * Notes:
 * 1. Add the list1 nodesto the unordered_set and find the matching node 
      in list2.
 * @return return the matching node
 */

int intersection(struct Node* list1_head, struct Node* list2_head)
{
	unordered_set <struct Node*> list_1_nodes;
	
	while(list1_head!=NULL)
	{
		list_1_nodes.insert(list1_head);
		list1_head=list1_head->next;
	}
	
	while(list2_head!=NULL)
	{
		if(list_1_nodes.find(list2_head)!=list_1_nodes.end())
		{
			return list2_head->data;
		}
		list2_head=list2_head->next;
	}
	return 0;
}

int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;
 
  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          intersection(head1, head2));
 
  getchar();
}

