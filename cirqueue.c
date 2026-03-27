#include <stdio.h>

// ...existing code...
int cq[10];
int front = -1, rear = -1;
int len = 10;

void enq()
{
    int val;
    if ((front == (rear + 1) % len) && front != -1) {
        printf("Circular Queue is full\n");
        return;
    }

    printf("Enter the value to be enqueued\n");
    if (scanf("%d", &val) != 1) {
        printf("Invalid input\n");
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % len;
    }
    cq[rear] = val;
}

void deq()
{
    if (front == -1) {
        printf("Circular queue is empty\n");
        return;
    }

    printf("The dequeued element is %d\n", cq[front]);
    if (front == rear) { // now becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % len;
    }
}

void peek()
{
    if (front == -1) {
        printf("Circular queue is empty\n");
    } else {
        printf("The front element is %d\n", cq[front]);
    }
}

void display()
{
    if (front == -1) {
        printf("Circular queue is empty\n");
        return;
    }

    printf("The elements in circular queue are:\n");
    int i = front;
    while (1) {
        printf("%d\n", cq[i]);
        if (i == rear) break;
        i = (i + 1) % len;
    }
}

int main()
{
    int flag = 1, ch;
    printf("1. enqueue\n2. dequeue\n3. peek\n4. display\n5. exit\n");
    do {
        printf("Enter the choice: ");
        if (scanf("%d", &ch) != 1) { // guard invalid input
            printf("Invalid input\n");
            // clear stdin
            int c; while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        switch (ch) {
            case 1: enq(); break;
            case 2: deq(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("exit\n"); flag = 0; break;
            default: printf("invalid choice\n");
        }
    } while (flag);
    return 0;
}
// ...existing code...