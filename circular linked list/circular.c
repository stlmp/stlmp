#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
};
struct node *header=NULL;
struct node *end=NULL;

void createnode(struct node *ptr,int data,int pos)
{
	struct node *ptr2,*ptr3;
	int cnt=1;
	ptr2=(struct node*)malloc(sizeof(struct node));
	if(header==NULL)
	{
		ptr2->data=data;
		end=ptr2;
		ptr2->next=header;
		header=ptr2;
		end->next=header;
	}
	else if(pos==1)
	{
		ptr2->data=data;
		ptr2->next=header;
		header=ptr2;
		end->next=header;
	}
	else
	{
		while(cnt<=pos-1 && ptr!=end)
		{
			ptr3=ptr;
			ptr=ptr->next;
			cnt++;
		}
		if(ptr==end && cnt==pos-1)
		{
			ptr->next = ptr2;
			ptr2->next=header;
			ptr2->data=data;
			end=ptr2;
		}
		else if(cnt==pos)
		{
			ptr3->next=ptr2;
			ptr2->next=ptr;
			ptr2->data=data;
		}
		else
		{
			printf("Invalid Position Number\n");
		}
	}
}
void display(struct node *ptr)
{
	int cnt=0;
	
	while(cnt<50)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
		cnt++;
	}
}
void loopcheck(struct node *ptr)
{
	struct node *ptr2;
	ptr2=ptr;
	

	while(1)
	{
		ptr=ptr->next;
		if(ptr==ptr2)
		{
			printf("The list contains a loop\n");
			break;
		}
	}
}

void delete(struct node *ptr,int pos)
{
	int cnt=1;
	struct node *ptr3;
	if(pos==1)
	{
		header=ptr->next;
		end->next=header;
		free(ptr);
	}
	
	else
	{
		while(cnt<=pos-1 && ptr!=end)
		{
			ptr3=ptr;
			ptr=ptr->next;
			cnt++;
		}
		if(cnt==pos)
		{
			ptr3->next=ptr->next;
			free(ptr);
		}
		else
		{
			printf("Invalid Position Number\n");
		}
	}
}
int main() 
{
	int option,data,pos;
	while(1){	
	printf("1.Insert\n2.Delete\n3.Display\n4.Check for loop\n5.Exit\n\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1: printf("Enter data and position: ");
		scanf("%d%d",&data,&pos);
		createnode(header,data,pos);
		break;
		case 2: printf("enter position to delete: ");
				scanf("%d",&pos);
				delete(header,pos);
				break;
		case 3: display(header);
		printf("\n");
		break;
		case 4: loopcheck(header);
				break;
		case 5:goto endi;
	}
}
endi:;
}

