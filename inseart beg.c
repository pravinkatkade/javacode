#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;	
};
struct Node *head=NULL;
  void inseartbeg()
  {
  	if(head==NULL)
	  {
	  	head=(struct Node*)malloc(sizeof(Node));
	  	printf("enter a data\n");
	  	scanf("%d",&head->data);
	  	head->next=NULL;
	  }
	  else
	  {
	  	struct Node *temp;
	  	temp=(struct Node*)malloc(sizeof(Node));
	  	printf("enter a dara\n");
	  	scanf("%d",temp->data);
	  	temp->next=head;
	  	head=temp;
	  }
  }
