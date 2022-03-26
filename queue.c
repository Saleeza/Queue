#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
typedef struct  queue_node
{
   int arr[MAX] ;
   int front;
   int rear;
}node;
void insert(int item,node *q)
{
    if(( q->front==0 && q->rear==MAX-1 ) || (q->front==q->rear+1))
    {printf("\n\t-----------q is full---------\n");
    return;}
     if (q->front==-1  && q->rear==-1)
    q->front=q->rear=0;
    else if(q->rear==MAX-1)
    q->rear=0;
    else
    q->rear=q->rear+1;
    q->arr[q->rear]=item;

}
void dequeue(node *q)
{
    int item;
    if(q->front==-1)
    {
        printf("\n\t-----q is empty-----\n");
        return;
    }
    item=q->arr[q->front];
    if(q->front==q->rear)
    q->front=q->rear=0;
    else if (q->front==MAX-1)
    q->front==0;
    else
    q->front=q->front+1;
    printf("item is %d",item);
    return ;
}
void get_count(node *q)
{
    int i,count=0;
  for(i=MAX-1;i>=0;i--)
  {
      if ((q->arr[i]%3==0) && (q->arr[i]%5!=0))
      count++;
  }
  printf("\nthe no of elements divisible by 3 but not by five are %d",count);  
    return;
}
int main()
{
    int count;
    int item,choice;
    node q;
    q.front=q.rear=-1;
    while(1)
    {
     printf("\n\t-----------main menu-------\n");
     printf("\t 1) push an element\n");
     printf("\t 2) pop an element\n");
     printf("\t 3) the no of count\n");
     printf("\t 4) exit\n");

     printf("\tenter the choice  ");

     scanf("%d",&choice);

        switch(choice)
      {
         case 1:

           printf("enter the element to be pushed   ");
           scanf("%d",&item);
           insert(item,&q);
           break;

        case 2:

           dequeue(&q);
           break;
        case 3:
           get_count(&q);
           break;
       
        case 4:

          exit(0);
      }
    }
    printf("the no of elements divisible by three but not by five are %d",count);
return 0;

}


