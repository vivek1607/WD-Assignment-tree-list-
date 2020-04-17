#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

struct node* newnode1(int data)
{
	struct node* newNode=(struct node*)malloc(sizeof(struct node));;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

struct node* Insert(struct node* root, int data)
{
	if (root == NULL)
		return newnode1(data);

	if (data < root->data)
		root->left  = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);

	return root;
}

int FindHeight(struct node* root)
{
	if(root==NULL)
		return 0;

	else
	{
		int lb=FindHeight(root->left);
		int rb=FindHeight(root->right);
		if(lb>rb)
            return lb+1;
        else
            return rb+1;
   }
}
int main()
{
	struct node* root=NULL;
	root=Insert(root,7);
	Insert(root,9);
	Insert(root,4);
	Insert(root,1);
	Insert(root,5);
	printf("Height of the tree is %d",FindHeight(root));
	return 0;
}
