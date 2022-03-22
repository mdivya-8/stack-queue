1.stack
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *link;
}s;

int push(s **top_arg, int ndata)
{
	s *new = malloc(sizeof(s));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		new->data = ndata;
		new->link = NULL;
		if(*top_arg == NULL)
		{
			*top_arg = new;
		}
		else
		{
			new->link=*top_arg;
			*top_arg = new;
		}
		printf("Inserted element is : %d\n",new->data);
	}
}

int pop(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		s *temp = *top;
		*top = temp->link;
		printf("Deleted element is : %d\n",temp->data);
		free(temp);
	}
}

void peek(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	s *temp = *top;
	printf("Topmost element is :%d\n",temp->data);

}

int display(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack elements are: ");
		s *temp = *top;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

int main()
{
s *top=NULL;
push(&top,10);
push(&top,20);
push(&top,30);
peek(&top);
display(&top);
pop(&top);
pop(&top);
pop(&top);
display(&top);
return 0;
}

2.queue
#include<stdio.h>
#define s 5
int front=-1;
int rear=-1;
int q[s];
void enque(int ele)//1
{
	if(rear==s-1)          //   front=0  rear=0  rear=1               
	{
		printf("queue is full:\n");
		return;
	}
	else
	{
	    if(front==-1)     
	    front=0;
	    
	   rear++;
	   q[rear]=ele;//q[0]=1   q[1]=2  q[2]=3 ;rear=s-1
	}
}
void deque()
{
	if(front==-1)
	{
		printf("queue is empty\n");
		return;
	}
	else
	{
	    printf("deleted ele is %d\n",q[front]);//q[0]=1
	    front++;//front=1  q[1]=2
	 //   if(front>rear)
	   // front=rear=-1;
	}
}
void display()
{
    if(rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
 	   int i=front;//0  front moved from 0   to rear s-1
	   for(;i<=rear;i++)
	  printf("%d\n",q[i]);//q[0]=1,q[1]=2,3
    }
}
int main()
{
	enque(1);
	enque(2);
	enque(3);
	display();
	deque();
	display();
	deque();
	display();
}
