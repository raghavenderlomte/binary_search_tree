#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct node{   /*this is the struture of our node it contains a data member and left and right self refferntial pointers which is used to store the 			and right child*/
struct node *left;
struct node *right;
int data;
};

struct node * binary_insert(struct node *,int); /*binary_inset function is used to store the given input into tree*/
struct node * binary_search(struct node *,int); /*binary_search is used to search for a particular entrt wether it is existing or not.*/
void binary_display(struct node *);		/*binary_display is used to display all the available entrys in our tree */
struct node *binary_smallest(struct node *);	/*binary_smallest is used to display the smallest number in the tree*/
void binary_largest(struct node *);  		/*binary_largest is used to display the largest number in the tree*/

