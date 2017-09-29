#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* npx; 
};
struct node *header = NULL;

struct node* XOR(struct node *a, struct node *b) 
{
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void createnode(struct node *ptr, int data) 
{
    struct node *ptr2,*next;
    ptr2= (struct node *) malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->npx = XOR(ptr,NULL);
    if (ptr!= NULL) 
    {
        struct node* next = XOR(ptr->npx, NULL);
        ptr->npx = XOR(ptr2, next);
	}
    header=ptr2;
}
void display(struct node *ptr) 
{
    struct node *curr = ptr;
    struct node *prev = NULL;
    struct node *next;
    while (curr != NULL) 
    {
	    printf("%d ", curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
}


int main() 
{
	int option,data;
	while(1){
	
	printf("1.Insert\n2.Display\n3.Exit\n\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1: printf("Enter data: ");
		scanf("%d",&data);
		createnode(header,data);
		break;
		case 2: display(header);
		printf("\n");
		break;
		case 3: goto endi;
	}
}
endi:;
}

