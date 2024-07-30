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

 
