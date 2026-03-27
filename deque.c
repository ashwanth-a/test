#include <stdio.h>
#define MAX 10
int de[10], front = -1, rear = -1;
void enq_fr(int data) {
  if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
    printf("Deque Overflow\n");
    return;
  }
  if (front == -1) {
    front = rear = 0;
  } else if (front == 0) {
    front = MAX - 1;
  } else {
    front = front - 1;
  }
  de[front] = data;
  printf("Inserted %d at front\n", data);
}

void enq_re(int data) {
  if (front == 0 && rear == MAX - 1) {
    printf("Deque Overflow\n");
    return;
  }
  if (front == -1) {
    front = rear = 0;
  } else if (rear == MAX - 1) {
    rear = 0;
  } else {
    rear = rear + 1;
  }
  de[rear] = data;
  printf("Inserted %d at rear\n", data);
}

void deq_fr(int data) {
  if (front == -1) {
    printf("Deque Underflow\n");
    return;
  }
  de[front] = data;
  printf("deleted %d at front\n", data);
  if (front == rear) {
    front = rear = -1;
  } else if (front == MAX - 1) {
    front = 0;
  } else {
    front = front + 1;
  }
}

void deq_re(int data) {
  if (front == -1) {
    printf("Deque Underflow\n");
    return;
  }
  de[rear] = data;
  printf("deleted %d at rear\n", data);
  if (front == rear) {
    front = rear = -1;
  } else if (rear == 0) {
    rear = MAX - 1;
  } else {
    rear = rear - 1;
  }
}

void peek() {
  if (front == -1) {
    printf("Deque is empty\n");
    return;
  }
  printf("Front element is %d\n", de[front]);
  printf("Rear element is %d\n", de[rear]);
}

void display() {
  if (front == -1) {
    printf("Deque is empty\n");
    return;
  }
  printf("The elements in deque are:\n");
  int i = front;
  while (1) {
    printf("%d ", de[i]);
    if (i == rear) {
      break;
    }
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main() {
  int ch;
  printf("1.Enque at front\n2.Enque at rear\n3.Deque at front\n4.Deque at "
         "rear\n5.Peek\n6.Display\n7.Exit\n");
  while (1) {
    printf("Enter your choice\n");
    scanf("%d", &ch);
    int data;
    switch (ch) {
    case 1:
      printf("Enter the value to insert at front\n");
      scanf("%d", &data);
      enq_fr(data);
      break;
    case 2:
      printf("Enter the value to insert at rear\n");
      scanf("%d", &data);
      enq_re(data);
      break;
    case 3:
      deq_fr(data);
      break;
    case 4:
      deq_re(data);
      break;
    case 5:
      peek();
      break;
    case 6:
      display();
      break;
    case 7:
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
