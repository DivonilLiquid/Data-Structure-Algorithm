#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
   int data;
   struct node* nextnode;
}node;
node *temp,*newnode,*head=NULL,*tail=NULL;
void display()
{
    printf("Your Updated Linkedlist is\n");
    temp=head;
    while(temp->nextnode!=head)
    {
        //printf("Hello\n");
        printf("%d ",temp->data);
        temp=temp->nextnode;
        printf("%d\n",temp->data);
    }
    printf("%d\n",temp->data);
    free(temp);
}
void create()
{
    int choice;
    while(1)
    {
        printf("Please Enter 1 for insert new node and 0 for exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
           newnode=(node*)malloc(sizeof(node));
           printf("Please Enter data for newnode\n");
           scanf("%d",&newnode->data);
           if(head==NULL)
           {
               //head=newnode;
               //head->nextnode=newnode;
               head=newnode;
               tail=head;
               tail->nextnode=head;
               //temp=head;

           }
           else 
           {
             newnode->nextnode=tail->nextnode;
              tail->nextnode=newnode;
              tail=newnode;
               //temp=newnode;
               //tail=newnode;
            }

        }
        else if(choice==0)
        {
           break;    
        }
    }
    display();

}

void insertatstart()
{
    newnode=(node*)malloc(sizeof(node));
   printf("Enter Data for inserting first node\n");
   scanf("%d",&newnode->data);
   //temp=(node*)malloc(sizeof(node));
    
    node *current = head;
    newnode->nextnode=head;

        while(current->nextnode != head)
        {
            current = current->nextnode;
        }
        current->nextnode = newnode;

        /*Makes new node as head node*/
        head = newnode;
    //head=newnode;
    //tail=newnode;
    //tail->nextnode=head;

   // head=newnode;
   //cout<<tail->nextnode->data<<endl<<endl;



   display();

}
void insertatend()
{


}
void insertafter()
{


}


int main()
{
    create();
    insertatstart();
    //insertatend();
    //insertafter();
    return 0;
}