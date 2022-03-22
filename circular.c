circular linkedlist
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char ch;
    struct node *link;
}node;

node *head=NULL;
int main()
{
    node *new_node,*temp_node=0;
    int i,len;
    printf("Enter size of list: ");
    scanf("%d",&len);
    for(i=1;i<=len;i++)
    {
        new_node=(node *)malloc(sizeof(node));
        printf("Enter elements in list: ");
        scanf("\n%c",&new_node->ch);
        new_node->link=NULL;
        if(head==0)
        {
            head=temp_node=new_node;
        }
        else
        {
            temp_node->link=new_node;
            temp_node=new_node;
        }
        temp_node->link=head;
    }
    printf("Elements in an linked list: \n");
    for(i=1;i<=len;i++)
    {
        printf("%c",head->ch);
        head=head->link;
        if(i<len)
        {
            printf("-->");
        }
    }
    printf("\n");
    return 0;
}
