#include "header.h"


int main()
{
int ip=1,ret=0;
struct node *first=NULL,*min,*het;
//memset(&first,0,sizeof(struct node));
while(ip !=0)
{
	printf("1-> to insert\n2->to search\n3->display\n4->smallest\n5->largest\n6->height\n");
	scanf("%d",&ip);

	switch(ip)
	{
		case 1:  printf("enter the digit\n");
			 scanf("%d",&ip);
			 first=binary_insert(first,ip);
		  	 break;
	
		case 2:  printf("enter the num to search\n");
			 scanf("%d",&ip);
			 het=binary_search(first,ip);
			 break;

		case 3:  printf("the elements avilable in tree are\n");
			 binary_display(first);
			 break;

		case 4:  printf("smallest num is\n");
			 min=binary_smallest(first);
			 printf("%d\n",min->data);
			 break;

		case 5:  printf("biggest num is\n");
			 binary_largest(first);
			 break;
		case 7: printf("enter the existing element num \n");
			scanf("%d",&ip);
			het=binary_search(first,ip);
			ret=binary_height(het);
			printf("data=%d\n",ret);
			break;
			

		default: printf("invalid entry\n please try again.....!!\n");
	}
	
		
}
}
