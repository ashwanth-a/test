#include<stdio.h>
#define MAX 10
int q[10], front=-1, rear=-1;
void enq()
{
    if(rear == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    
    if(front == -1) // First element
    {
        front = 0;
    }
    
    rear++; // Increment rear for all insertions
    printf("enter the value to insert \n");
    scanf("%d",&q[rear]);
    
}
void deq()
{
    if(front == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    
        printf("the removed element is  %d \n",q[front]);
        front+=1;
        
        if(front > rear)
        {
            front = rear = -1; // Reset the queue when it becomes empty
        }
    
}

void peek()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("the front element is %d \n",q[front]);
    }
}


void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }

    else{
        printf("The element in the queue are \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
}


int main()
{
    int ch;
    printf("1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enq();
                    break;
            case 2: deq();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}