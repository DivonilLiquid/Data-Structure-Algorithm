#include <iostream>
using namespace std;
class node
{
public:
	int value;
	node* left;
	node* right;
	node(int x){
		value=x;
		left=NULL;
		right=NULL;
	}
};
node* getnode(int x){
	node*ptr=new node(x);
	return ptr;
}
int main(int argc, char const *argv[])
{
	node* root=NULL,*ptr=NULL;
	int n,x;
	cin>>n>>x;
	root=new node(x);
	while(n--){
		ptr=root;
		string s;
		int a;
		getline(cin,s);
		cin>>a;
		int sl=s.length();
		for(int i=0;i<sl;i++){
			if(s[i]=='L'){
				if(ptr->left==NULL){
					ptr->left=getnode(a);
				}
				else{
					ptr=ptr->left;
				}
			}
			else{
				if(ptr->right==NULL){
					ptr->right=getnode(a);
				}
				else{
					ptr=ptr->left;
				}
			}
		}

	}
	return 0;
}