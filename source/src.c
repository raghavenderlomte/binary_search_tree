#include "header.h"

static struct node *head=NULL;
int m,op1,op2;
struct node * binary_insert(struct node *tree,int data)/* *tree is the base node addresss of the tree from main program(main.c)*/
{
	static int i;

	
	struct node *prev=NULL;			/*when ever we try to insert the data we start traversing from the base node and we compare the 
						  incoming value with the base node data,if the value is greateror equal then we move towards right 							side of tree,if it is less we move towards left and we insert the node at approprite location.*/
	while(1)
	{
		if(tree==NULL)
		{
			tree=(struct node *)malloc(sizeof(struct node));
			if(tree == NULL)
			{
				perror("malloc error\n");
				exit(1);
			}
			memset(tree,0,sizeof(struct node));	
			tree->data=data;
			if(i!=0)
			{
			if(prev->data >=tree->data)
			{
				prev->left=tree;
			}
			else
			{
				prev->right=tree;
			}
			}
			if(i == 0)
			{
			 	 head =tree;
				  i++;
			}
		
			
			return head;
		}
		else if(tree->data < data)
		{
			prev=tree;
			tree=tree->right;
		}
		else
		{
			prev=tree;
			tree=tree->left;
		}
	}
	

}
struct node * binary_search(struct node *tree,int data) /*here we follow simillar logic as we used in insert,starting from the base we try to									compare the data with the current node,if it less then we move towards left or else
							   towards right and when ever we find match we display it*/
{
	int j=0;
	struct node *temp=NULL;
	temp=tree;
	while(temp!=NULL)
	{
		if(temp->data == data)
		{
			printf("it is available in the tree\n");
			return temp;
		}
		else if(temp->data >= data)
		{
			j++;
			temp=temp->left;
		}
		else if(temp->data <data)
		{
			j++;
			temp=temp->right;
		}
	}
	printf("data not found error\n");
}
void binary_display(struct node *tree)  /*we can do this in three different ways i)preorder ii)inorder iii)post order.
						here we are following inorder*/
{
	if(tree==NULL)
	{
		return;
	}	
	//printf("%d\n",tree->data);
	binary_display(tree->left);
	printf("%d\n",tree->data);
	binary_display(tree->right);	
	//printf("%d\n",tree->data);
	
}

struct node * binary_smallest(struct node *tree) /*however we know that our smallest value will be stored at left extreme node
						   so we do the same thing traverse towards left*/
{
	if((tree->left == NULL) &&(tree->right == NULL))
	{
		return tree;
		
	}
	while(tree->left!=NULL)
	{
		tree=tree->left;

	}
	return tree;
}
void binary_largest(struct node *tree)    /*as like the smallest we do reverse to that*/
{
	if((tree->left == NULL) && (tree ->right == NULL))
	{
		return;
	}
	while(tree->right!=NULL)
	{
		tree= tree->right;
	}
	printf("largest num is %d\n",tree->data);
}


int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;

}
int binary_height(struct node *tree) /*this structure is used to find the height of a particular node so from the given node we traverse through
					left and right child recursively and find the heights of its left and right sub tree and we return the max
					max between them*/
{
	if(tree == NULL)
	{
		return -1;
	}
	op1=binary_height(tree->left);
	op2=binary_height(tree->right);
	m=max(op1,op2);
	return m+1;

}
