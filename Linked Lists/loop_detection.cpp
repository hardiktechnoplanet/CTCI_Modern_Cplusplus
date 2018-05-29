/**
 * @brief Loop detection
 *Given a circular linked list, implement an algorithm that returns the node at the
  beginning of the loop. DEFINITION: Circular linked list: A (corrupt) linked list in 
  which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
  EXAMPLE
  Input: A -> B -> C - > D -> E -> C [the same C as earlier)
  Output: C
 *
 * @file loop_detection.cpp
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
 * @brief Loop Detection
 * Notes:
 * 1.Use slow and fast pointer appraach
 * @return return the node at which the loop starts
 */

int loop_detection(struct Node* head)
{
	auto fast_ptr=head;
	auto slow_ptr=head;
	
	//firstly, find the meeting point
	while(fast_ptr!=NULL && fast_ptr->next!=NULL)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		
		if(slow_ptr==fast_ptr)
		break;
	}
	
	//test case: if there is no meeting point, therefore no loop
	if(fast_ptr==NULL || fast_ptr->next==NULL)
	return 0;
	
	/*Move slow_ptr to Head. Keep the fast_ptr at Meeting Point. Each are k steps from the
     Loop Start. If they move at the same pace, they must meet at Loop Start. */
	slow_ptr=head;
	while(slow_ptr!=fast_ptr)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next;
	}
	return fast_ptr->data;
}

