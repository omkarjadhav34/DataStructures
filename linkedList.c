#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    Node * next;
} Node;

static Node* createNode(int data)
{
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

Node * addNode_Front(Node *head, int data)
{
    Node * temp = createNode(data); 
    
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    
    temp->next = head;
    head = temp;

    return head;    
}

Node * addNode_Back(Node * head, int data)
{
    Node *currPtr = head;
    
    if(head == NULL){
        head = createNode(data);
        return head;
    }
    
    while(currPtr->next != NULL) currPtr = currPtr->next;
    
    currPtr->next = createNode(data);
    
    return head;
}

Node * addNode_atIndex(Node * head, int data, int pos)
{
    if((pos < 0) || (head == NULL && pos > 0)) return NULL;
    
    Node * curr = head;
    
    while((pos > 1) && curr->next != NULL){
        curr = curr->next;
        pos--;
    }
    if(pos == 1)
    {
        Node * temp = createNode(data);
        temp->next =curr->next;
        curr->next = temp;
    }
    else return NULL;
    
    return head;
}

int length(Node * head)
{
    int len = 0;
    Node * curr = head;
    
    while(curr && curr->next != NULL)
    {
        curr = curr->next;
        pos++;
    }
    
    return (curr == NULL) ? pos : pos + 1; 
}

void printList(Node * head)
{
    if(head == NULL)
        printf("NULL\n\r");
    else
    {
        Node * curr = head;
        
        while(curr)
        {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n\r");
    }
}
