#include <stdio.h>
#include <stdlib.h>

struct node{
    float coef;
    int exp;
    struct node *next;
}typedef Node;
Node *create(Node *head)
{
    int n,exp,coef;
    printf("Enter no of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {

        head = insert(head,coef,exp);
    }
}
int main()
{

}