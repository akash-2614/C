#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}nodetype;

void push(nodetype** tp, int ele)
{
    nodetype *p;
    p = (nodetype*)malloc(sizeof(nodetype*));
    if(p == NULL)
        printf("Not enough memory\n");
    else
    {
        p->data = ele;
        p->next = *tp;
        *tp = p;
    }
        
}

void pop(nodetype **tp)
{
    nodetype *p;
    p = *tp;
    if(tp == NULL)
        printf("Stack is empty....\n");
    else
    {
        printf("Element deleted is %d\n",(*tp)->data);
        *tp = (*tp)->next;
        free(p);
        
    }
        
}

void display(nodetype* tp)
{
    if(tp == NULL)
        printf("Stack is empty....\n");
    else
    {
        while(tp != NULL)
        {
            printf("%d ",tp->data);
            tp = tp->next;
        }
    }
    printf("\n");
        
}

int main()
{
    nodetype *top=NULL;
    int ele,op;

    while(op != 4)
    {
        printf("1- Push an element in stack\n2- Pop an element from stack\n3- Display stack\n4- exit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);

        if(op ==1)
        {
            printf("Enter the element: ");
            scanf("%d",&ele);
            push(&top, ele);
        }
        else if(op == 2)
        {
            printf("POping the element: \n");
            pop(&top);
        }
        else if(op == 3)
        {
            printf("Displaying the elements: ");
            display(top);

        }
        else
            printf("Invalid choice!!!!\n");
    }
    return 0;


}