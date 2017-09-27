
#include<stdio.h>
#include<stdlib.h>
#define maxElements 4
 
struct Node
{
    int numElements;
    int array[maxElements];
    struct Node *next;
};

void printUnrolledList(struct Node *n)
{
    while (n != NULL)
    {
        for (int i=0; i<n->numElements; i++)
            printf("%d ", n->array[i]);
 
        n = n->next;
    }
}
 
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
 
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
 
    head->numElements = 3;
    head->array[0] = 1;
    head->array[1] = 2;
    head->array[2] = 3;
 
    head->next = second;
    second->numElements = 3;
    second->array[0] = 4;
    second->array[1] = 5;
    second->array[2] = 6;
 
    second->next = third;
    third->numElements = 3;
    third->array[0] = 7;
    third->array[1] = 8;
    third->array[2] = 9;
    third->next = NULL;
 
    printUnrolledList(head);
 
    return 0;
}
