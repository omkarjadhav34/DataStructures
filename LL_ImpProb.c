#include "linkedlist.h"
#include <stdlib.h>


/**
 * Print/Return middle of a given linkedlist
 */
 
int middle(Node * head)
{
	Node *slwPtr = head, *fstPtr = head;
	
	while(fstPtr)
	{
		fstPtr = fstPtr->next;
			
		if(fastPtr != NULL){
		  slwPtr = slwPtr->next;
		  fstPtr = fstPtr->next;
		}
	}
	
	return slwPtr->data;
}


/**
 * Frequency of a given number in a given linkedlist
 */

int freq(Node * head, int data)
{
  Node * curr = head;
  int freq = 0;
  
  while(curr)
  {
    if(curr->data == data)
      freq++;
      
    curr= curr->next;
  }
  
  return freq;
}

/**
 * Detect circular loop
 */
Node* detectLoop(Node * head)
{
 	Node *slwPtr = head, *fstPtr = head;
	
	while(fstPtr)
	{
		fstPtr = fstPtr->next;
			
		if(fstPtr != NULL){
		  slwPtr = slwPtr->next;
		  fstPtr = fstPtr->next;
		  
		  if(fstPtr == slwPtr)
		    return slwPtr;
		}
	}

	return NULL;
}

/**
 * Count nodes in circular loop
 */
int countNodes(Node * head)
{
  int totalNodes = 0;
  Node * temp = detectLoop(head);
  Node * curr  = head; 
  
  if( temp == NULL)
  {
    
    while(curr)
    {
      totalNodes++;
      curr = curr->next;
    }  
  }
  else
  {
    temp = temp->next;
    
    while(temp->next != curr)
    {
      totalNodes++;
      temp = temp->next;
      curr = curr->next;
    }
    
    while(curr != temp)
    {
      totalNodes++;
      curr = curr->next;
    }
  }
  
  return totalNodes+1;
}

/**
 * Swap first and last nodes
 */
Node* swapNodes(Node * head)
{
  Node * temp = detectLoop(head);  // check if there is loop
  Node * curr  = head; 
  
  if( temp == NULL)
  {
    
    while(curr && curr-next!= NULL)
    {
      curr = curr->next;
    }
    
    curr->data = curr->data ^ head->data;
    head->data = curr->data ^ head->data;
    curr->data = curr->data ^ head->data;  
  }
  else
  {
    temp = temp->next;
    
    while(temp->next != curr)
    {
      temp = temp->next;
      curr = curr->next;
    }
    
    curr->data = curr->data ^ head->data;
    head->data = curr->data ^ head->data;
    curr->data = curr->data ^ head->data;
  }
  
  return head;
}

/**
 * Intersection of two Sorted Linked Lists
 * Source: https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
 *
 * Given the head of two sorted linked lists, the task is to create a new linked list that
 * represents the intersection of the two original lists. The new linked list should be 
 * created without modifying the original lists.
 * Note: The elements in the linked lists are not necessarily distinct.
 * Example: 
 * Input: head1 = 1->2->3->4->6, head2 = 2->4->6->8
 * Output: 2 4 6
 * Explanation: For the given two linked list, 2, 4 and 6 are the elements in the intersection. 
 */

Node* linkedListIntersection(Node * head1, Node *head2)
{
  Node *currPtr1 = head1, *currPtr2 = head2;
  Node *result = NULL, resCurrPtr;
  
  if(currPtr1  == NULL || currPtr2 == NULL)
  {
    return NULL;
  }
  
  while(currPtr1 && currPtr2)
  {
    if(currPtr1->data < currPtr2->data)
    {
      currPtr1 = currPtr1->next;
    }
    else if(currPtr1->data == currPtr2->data)
    {
      if(result == NULL){
        
        result = (Node*)addNode(currPtr1->data);
        resCurrPtr = result;
      }
      else
      {
        resCurrPtr->next = (Node*)addNode(currPtr1->data);
        resCurrPtr = resCurrPtr->next;
      }
      currPtr1 = currPtr1->next;
      currPtr2 = currPtr2->next; 
    }
    else
    {
      currPtr2 = currPtr2->next;
    }
  }
  
  return result;
}

/**
 * Intersection point of two Linked Lists
 * Source: https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
 *
 * There are two singly linked lists in a system. By some programming error, the end node of
 * one of the linked lists got linked to the second list, forming an inverted Y-shaped list.
 * Write a program to get the point where two linked lists merge. 
 */
 
// Multiple approaches to this problem
// Approach 1 - Bring longer list closer to the intersection point - O(max(m,n))
// Approach 2 - Redirect list pointer after iterating till nULL to other head pointers
// and iterate till intersection not reached
// Approach 3 - create a loop within in one list
Node* findIntersectionPoint(Node * head1, Node * head2)
{
  Node * curr1 = head1, curr2 = head2;
  int len1 = length(curr1);
  int len2 = length(curr2);
  
  while(len1 <len2)
    curr1 = curr1->next;
  
  while(len2 < len1)
    curr2 = curr2->next;
  
  while(curr1 != curr2)
  {
    curr1 = curr1->next;
    curr2 = curr2->next;
  } 
  return curr1; 
}

/**
 * Sublist Search (Search a linked list in another list)
 * Source: https://www.geeksforgeeks.org/sublist-search-search-a-linked-list-in-another-list/
 * 
 * Given two linked lists, the task is to check whether the first list is present in 2nd list or not.
 */
 
int searchSublist(Node * head1, Node * head2)
{
  Node *sublist = head1, *list = head2;
  
  if(sublist == NULL && list == NULL)
    return 1;
   
  if(sublist != NULL && list == NULL) return false;
  
  while(list)
  {
    while(list && sublist->data == list->data)
    {
      sublist=sublist->next;
      list->next = list->next;
      
      if(sublist == NULL)
        return true;
    }
    
    if(list)
      list = list->next;
    
    sublist = head1;
  }
  
  return false;
} 
  
