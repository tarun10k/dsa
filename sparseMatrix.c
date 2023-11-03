#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};
struct node *create(int row, int col, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(1);
    }
    newnode->row = row;
    newnode->col = col;
    newnode->value = value;
    newnode->next = NULL;

    return newnode;
}
void display(struct node *p)
{
    printf("ROW\tCOLUMN\tVALUE\n");
    while (p)
    {
        printf("%d\t%d\t%d\n", p->row, p->col, p->value);
        p = p->next;
    }
}
int main()
{
    int nr, nc, val, flag = 0;
    struct node *head, *last;
    printf("Enter the no of rows:");
    scanf("%d", &nr);
    printf("Enter the no of columns:");
    scanf("%d", &nc);

    printf("Enter elements of sparse matrix:");
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            scanf("%d", &val);

            if (val && flag == 1)
            {
                struct node *newnode = create(i, j, val);
                last->next = newnode;
                last = newnode;
            }

            if (val && flag == 0)
            {
                last = head = create(i, j, val);
                flag = 1;
            }
        }
    }
    display(head);
    return 0;
}