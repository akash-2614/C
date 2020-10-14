
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}nodetype;

nodetype* push(nodetype* tp, int ele)
{
    nodetype *p;
    p = (nodetype*)malloc(sizeof(nodetype*));
    if(p == NULL)
       printf("Not enough memory\n");
    else
    {
        p->data = ele;
        p->next = tp;
        tp = p;
    }
    return tp;
}

nodetype* pop(nodetype*tp)
{
    nodetype *p;
    p = tp;
    printf("Element popped is %d \n",tp->data);
    tp = tp->next;
    free(p);
    return tp;
}

void display(nodetype* tp)
{
    while(tp != NULL)
    {
        printf("%d ",tp->data);
        tp = tp->next;
    }
    printf("\n");
}

int main()
{
    nodetype* top = NULL;
    int ele, op=0;
    while(op != 4)
    {
        printf("1- Push an element in stack\n2- Pop an element from stack\n3- Display stack\n4- exit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);

        if(op == 1)
        {
            printf("\nPushing an element\nEnter the element: ");
            scanf("%d",&ele);
            top = push(top, ele);    
        }
        else if(op == 2)
        {
            if(top != NULL)
            {
                printf("\nPoping an element\n");
                top = pop(top);
            }
            else
                printf("Stack is empty\n");    
        }
        else if(op == 3)
        {
            if(top != NULL)
            {
                printf("\nDisplaying stack\n");
                display(top);
            }
            else
                printf("Stack is empty");    
        }
        else if(op == 4)
        printf("EXIT\n");
        else
        {
            printf("Invalid choice\n");
        }
        
    }
    
   return 0; 
}