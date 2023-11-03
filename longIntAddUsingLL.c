#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head,int n)
{
    struct node *last,*newnode;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = n%10;
    head->next = NULL;
    last = head;
    n/=10;
    while(n>0){
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = n%10;
        newnode->next = NULL;
        last->next = newnode;
        last = newnode;
        n/=10;
    }
    return head;
}

struct node *push(struct node *head,int n)
{
    struct node *temp;
    struct node*p = head;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return head;
    }
    
    while(p->next)
    p = p->next;

    p->next = temp;
    return head;
}

struct node *addition(struct node *poly1,struct node *poly2)
{
    struct node *result = NULL;
    struct node *p1 = poly1;
    struct node *p2 = poly2;

    if(p1 == NULL)
    return p2;

    if(p2 == NULL)
    return p1;
    int sum = 0,carry = 0;
    while(p1 || p2)
    {
        sum = 0;
        if(p1)
        {
            sum+=p1->data;
            p1=p1->next;
        }
        if(p2)
        {
            sum+=p2->data;
            p2=p2->next;
        }
        sum+=carry;
        carry = sum/10;
        sum = sum%10;
        result = push(result,sum);
    }
    if(carry)
        result = push(result,carry);
    
    return result;
}

void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct node *poly1,*poly2,*result;
    long long int n1,n2;
    printf("Enter two numbers for addition:");
    scanf("%d%d",&n1,&n2);

    poly1 = create(poly1,n1);
    poly2 = create(poly2,n2);

    display(poly1);
    display(poly2);

    result = addition(poly1,poly2);
    display(result);

    return 0;
}