#include<iostream>
using namespace std;

class node
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

void insertAtTail(node*&head,int d)
{
	if(head==NULL)
	{
		head = new node(d);
		return;
	}

	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node(d);
	return;
}

node* takeinput(int n)
{
	node*head=NULL;
	int d;

	while(n--)
	{
		cin>>d;
		insertAtTail(head,d);
		
	}
	
	return head;
}

void print(node*head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


int main() {

	int n;
	cin>>n;

	node*head=takeinput(n);

	// print(head);

	node*prev=NULL;
	node*curr=head;


	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"Temp is at: "<<temp->data<<endl;
    node*end=temp;

	int cnt=0;
	while(curr!=NULL)
	{
		if((curr->data)%2!=0)
		{
			prev=curr;
            cout<<"Prev is at: "<<prev->data<<endl;
			curr=curr->next;
		}
		else //if((curr->data)%2==0)
		{
			
			prev->next=curr->next;
			end->next=curr;
			curr=curr->next;
			end=end->next;
			end->next=NULL;	
		}
	}
print(head);

	return 0;
}



