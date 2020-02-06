#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	} node;
	
void generate_rand_list(node *head,int length)
{
	int i=0;
	node *current=head;
	srand(time(NULL));
	while (i<length)
	{
    current->data=rand()%100+1; 
	current->next=(node *)malloc(sizeof(node));
	current=current->next;
	i++;
	}
    current=NULL;
}

node *get_even(node *head)
{ 
	node *new_head, *new_current;
	node *current=head;
	new_head=(node *)malloc(sizeof(node));
    new_current=new_head;
	while (current->next!=NULL)
	{
		if (current->data%2==0)
		{
	     new_current->data=current->data;
	     current=current->next;
	     new_current->next=(node *)malloc(sizeof(node));
	     new_current=new_current->next;
	     }
	    else
	     current=current->next; 
	 }
	 new_current=NULL;
	 return new_head;
}

node *get_odd(node *head)
{ 
	node *new_head, *new_current;
	node *current=head;
	new_head=(node *)malloc(sizeof(node));
    new_current=new_head;
	while (current->next!=NULL)
	{
		if (current->data%2!=0)
		{
	     new_current->data=current->data;
	     current=current->next;
	     new_current->next=(node *)malloc(sizeof(node));
	     new_current=new_current->next;
	     }
	    else
	     current=current->next; 
	 }
	 new_current=NULL;
	 return new_head;
}

void display_list(node *head)
{
	node *current=head;
	printf("[ ");
	while (current->next!=NULL)
	{
	 printf("%d ",current->data);
	 current=current->next;
	}
	printf("]\n");
}

int get_length(node *head)
{
	node *current=head;
	int count=0;
	while (current->next!=NULL)
	{
	 current=current->next;
	 count++;
	}
	return count;
}

int main()
{
	int length;
	printf("Enter the length of the list: ");
	scanf("%d",&length);
	node *head;
	
	head=(node *)malloc(sizeof(node));
	generate_rand_list(head,length);
	
	printf("Initial number list (contains %d elements):\n",get_length(head));
	display_list(head);
	
	printf("Even number list (contains %d elements):\n",get_length(get_even(head)));
	display_list(get_even(head));

    printf("Odd number list (contains %d elements):\n",get_length(get_odd(head)));
	display_list(get_odd(head));
	
	return 0;
}