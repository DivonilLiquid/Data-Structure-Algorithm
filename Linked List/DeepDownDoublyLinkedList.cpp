#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node* random;
	node(int d){
		data=d;
		next=NULL;
		random=NULL;
	}
};
void PointRandom(node* head)
void InsertAtTail(node* &head,int data){
	if(head==NULL){
		head = new node(data);
	}
	else{
		node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new node(data);
	}
}
void InsertAtMiddle(node* &head,int Position,int data){
	node* iterator = head;
	Position--;
	while(Position--){
		iterator=iterator->next;
	}
	node* n = new node(data);
	n->next = iterator->next;
	iterator->next=n;
}
void Print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	node* head=NULL;
	InsertAtTail(head,1);
	InsertAtTail(head,9);
	InsertAtTail(head,8);
	InsertAtTail(head,4);
	InsertAtTail(head,3);
	InsertAtTail(head,6);
	InsertAtTail(head,4);
	InsertAtTail(head,6);
	InsertAtTail(head,8);
	Print(head);
	InsertAtMiddle(head,1,2);
	Print(head);
	return 0;
}