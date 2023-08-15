#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
typedef struct node
{
	u32 Data;
	node* Node next;
}node_t;
node_t* pushFront(Node * head , u32 data);
node_t *insertAt(node_t *head , u32 data , u32 position);
node_t * popBack(node_t *head);
void print(node_t *head);
node_t * getThirdNode(node_t * head);
node_t * getNthNodeFromTheBack(node_t *head , u32 n)
void main(void)
{
	node_t* Head=(node_t*)malloc(sizeof(node_t));
	Head->next=NULL;
}
node_t* pushFront(Node * head , u32 data)
{
	node_t* NewHead=(node_t*)malloc(sizeof(node_t));
	NewHead->next=Head;
	NewHead->Data=data;
	return NewHead;
}
node_t *insertAt(node_t *head , u32 data , u32 position);
{
	node_t* ptr=head;
	if(position==0)
	{
		ptr=pushFront(head,data);
	}
	else
	{
		node_t* New=(node_t*)malloc(sizeof(node_t));
		for(u32 i=0;i<position-1;i++)
		{
			ptr=ptr->next;
		}
		New->next=ptr->next;
		ptr->next=New;
		ptr=head;
	}
	return head;
}
node_t * popBack(node_t *head)
{
	node_t* NextPtr=head;
	node_t* PrevPtr=NULL;
	while(NextPtr->next!=NULL)
	{
		PrevPtr=ptr;
		NextPtr=ptr->next;
	}
	free(NextPtr);
	PrevPtr=NULL;
	return head;
}
Node* removeAt(Node * head , int position)
{
	node_t* ptr=head;
	node_t* DelPtr=NULL;
	for(u32 i=0;i<position-1;i++)
	{
		ptr=ptr->next;
	}
	DelPtr=ptr->next->next;
	free(ptr->next);
	ptr->next=DelPtr;
	return head;
}
void print(node_t *head)
{
	node_t *ptr=head;
	u32 i=0;
	while(prt!=NULL)
	{
		print("value of element No. %d = %d",i,ptr->Data);
		ptr=ptr->next;
		i++;
	}
}
node_t * getThirdNode(node_t * head)
{
	node_t *ptr=head;
	for(u32 i=0;i<3;i++)
	{
		ptr=ptr->next;
	}
	return ptr;
}
node_t * getNthNodeFromTheBack(node_t *head , u32 n)
{
	node_t *ptr=head;
	for(u32 i=0;i<n;i++)
	{
		ptr=ptr->next;
	}
	return ptr;
}