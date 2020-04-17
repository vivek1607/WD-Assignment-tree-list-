#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;

}*first=NULL;

void create(int n)
{

	printf("Enter the data of nodes\n");
	struct node *t,*last;
	first=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&first->data);
	first->next=NULL;
	first->prev=NULL;
	last=first;


	for (int i = 1; i < n; ++i)
	{
		t=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&t->data);
		t->next=NULL;
		last->next=t;
		t->prev=last;
		last=t;

	}
}
int count(struct node *p)
{
		int i=0;
	for (; p!=NULL; ++i)
	{
		p=p->next;

	}
	return i;
}


void delnode(struct node *p,int pos)
{
	if(pos<=0||pos>count(first))
		return;

	struct node *q;
	if(pos==1)
	{
		q=first;
		first=first->next;
		free(q);
	}
	else
	{
		q=first;
		p=p->next;
		for(int i=2;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		free(p);
	}
}
void display(struct node *p)
{
	printf("The linked list is\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}

}
int main()
{
	int n,pos;
	printf("Enter the no. of nodes to be inserted\n");
	scanf("%d",&n);
	create(n);
	display(first);
	printf("\nEnter the position of node to be deleted\n");
	scanf("%d",&pos);
	delnode(first,pos);
	display(first);
	return 0;
}
