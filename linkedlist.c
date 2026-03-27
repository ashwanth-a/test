#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void addstart(struct node **head)
{
    printf("Enter the data to be inserted at start\n");
    int val;
    scanf("%d",&val);
    struct node*new=(struct node*)malloc(sizeof(struct node*));
    new->data=val;
    new->link=*head;
    *head=new;
}


void addend(struct node **head)
{
    printf("Enter the data to be inserted at start\n");
    int val;
    scanf("%d",&val);
    struct node*new=(struct node*)malloc(sizeof(struct node*));
    new->data=val;
    new->link=NULL;
    if(*head==NULL)
    {
        *head==NULL;
        return;
    }
    struct node*curr=*head;
    while(curr->link!=NULL)
    {
        curr=curr->link;
    }
    curr->link=new;
}

void addany(struct node**head)
{
    printf("enter the data to be inserted at any position\n");
    int val,pos,i=0;    
    scanf("%d",&val);
    printf("enter the position\n");
    scanf("%d",&pos);
    struct node*new=(struct node*)malloc(sizeof(struct node*));
    new->data=val;
    new->link=NULL;
    if(pos==0)
    {
        new->link=*head;
        *head=new;
        return;
    }
    struct node*curr=*head;
    while(i<pos-1 && curr!=NULL)
    {
        curr=curr->link;
        i++;
    }
    if(curr==NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    new->link=curr->link;
    curr->link=new;

}

void remstart(struct node**head)
{
    if(*head==NULL)
    {
        printf("list is empty");
        return;
    }
    struct node*curr=*head;
    *head=curr->link;
    free(curr);
}

void remany(struct node**head)
{
    if(*head==NULL)
    {
        printf("list is empty");
        return;
    }
    printf("enter the position to be deleted\n");
    int pos,i=0;
    scanf("%d",&pos);
    struct node*curr=*head;
    if(pos==0)
    {
        *head=curr->link;
        free(curr);
        return;
    }
    struct node*prev=NULL;
    while(i<pos-1 && curr!=NULL)
    {
        curr=curr->link;
        i++;

    }
    if(curr==NULL)
    {
        printf("position out of bounds\n");
        return;
    }
    prev->link=curr->link;
    free(curr);
}

void remend(struct node**head)
{
    if(*head==NULL)
    {
        printf("list is empty");
        return;
    }
    struct node*curr=*head;
    struct node*prev=NULL;
    while(curr->link!=NULL)
    {
        prev=curr;
        curr=curr->link;
    }
    if(prev==NULL)
    {
        *head=NULL;
    }
    else
    {
        prev->link=NULL;
    }
    free(curr);
}

void display(struct node*head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node*curr=head;
    printf("the elements in the linked list are\n");
    while(curr!=NULL)
    {
        printf("%d ->",curr->data);
        curr=curr->link;
    }
    printf("NULL");
    printf("\n");
}

int main()
{
    struct node*head=NULL;
    int choice;
    printf("1.add at start\n2.add at end\n3.add at any position\n4.remove at start\n5.remove at end\n6.remove at any position\n7.display\n8.exit\n");
        
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addstart(&head);
                break;
            case 2:
                addend(&head);
                break;
            case 3:
                addany(&head);
                break;
            case 4:
                remstart(&head);
                break;
            case 5:
                remend(&head);
                break;
            case 6:
                remany(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}