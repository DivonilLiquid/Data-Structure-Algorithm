#include<iostream>
using namespace std;
class  node
{
  public:
  int data;
  node*next;
  node(int d)
  {
    data=d;
    next=NULL;
  }
};
void insertatend(node*&head,int d)
{ 
     if(head==NULL)
     {
      head=new node(d);
      return;                               
     }
      node* tail=head;
	  while(tail->next!=NULL)
	  {
		  tail=tail->next;
	  }
      tail->next=new node(d);
      return;
}
int length(node*head)
{
   int count=0;
   node *temp=head;
   while(temp!=NULL)
   {
      temp=temp->next;
      count++;
   }
   return count;
}
node* kreverse(node* head,int K)
{
	node* current = head;  
    node* n = NULL;  
    node* prev = NULL;  
    int count = 0;  
    while (current != NULL && count < K)  
    {  
        n = current->next;  
        current->next = prev;  
        prev = current;  
        current = n;  
        count++;  
    }  
    if (n != NULL)  
    head->next = kreverse(n,K);  
  
    /* prev is new head of the input list */
    return prev;
}
void print(node*&head)
{
   node*temp=head;
   while(temp!=NULL)
   {
	   cout<<temp->data<<" ";
	   temp=temp->next;
   }
   cout<<endl;
}
int main()
 {
	node* head=NULL;
	int N,K;
	cin>>N>>K;
	while(N--)
	{
		int d;
		cin>>d;
		insertatend(head,d);//working fine
	}
	head=kreverse(head,K);//problem in this
	print(head);//working fine
	return 0;
}








