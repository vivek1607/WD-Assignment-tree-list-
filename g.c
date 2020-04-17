#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
}*root=NULL;


struct node *createTree()
{
	int x;
	scanf("%d",&x);

	if(x==-1)
	return NULL;

	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->lchild=p->rchild=NULL;

	printf("Enter the left child of %d\n",p->data);
	p->lchild=createTree();
	printf("Enter the right child of %d\n",p->data);
	p->rchild=createTree();
	return p;
}

int lnodecount(struct node *p)
{
	if(p)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		return 1;
		else
		return lnodecount(p->lchild)+lnodecount(p->rchild);
	}
	else
		return 0;
}

int nlnodecount(struct node *p)
{
	if(p)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		return 0;
		else
		return 1+nlnodecount(p->lchild)+nlnodecount(p->rchild);
	}
	else
		return 0;
}


int main()
{
	int x;
	printf("Enter the data of nodes of the tree (-1 for no input)\n");

	printf("Enter the root element\n");
	root=createTree(root);
	printf("No. of non-leaf nodes in the binary tree are\n");
	printf("%d\n",nlnodecount(root));
	printf("No. of leaf nodes in the binary tree are\n");
	printf("%d",lnodecount(root));


	return 0;
}
