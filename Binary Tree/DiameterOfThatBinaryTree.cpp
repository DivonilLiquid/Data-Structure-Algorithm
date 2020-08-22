/*
Given a binary tree which has T nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:
First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next  lines contain details of nodes.
Each detail of node contains two lines. First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child. ( Look at the sample explanation for more details )

Output:
Print the diameter of the binary tree.

Constraints:


SAMPLE INPUT 
5 1
L
2
R
3
LL
4
LR
5
SAMPLE OUTPUT 
4
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int value, lh, rh;
    node *left;
    node *right;
    node(int x){
    	value=x;
    	left=NULL;
    	right=NULL;
    }
};
node * getNode(int val){
    node *ret = new node(val);
    return ret;
} 
int max=INT_MIN; // our Diameter.
//Assign maximum Depth to each node.
int query(node *ptr){
    if(ptr){
        ptr->lh = query(ptr->left);
        ptr->rh = query(ptr->right);
        if ((ptr->lh + ptr->rh + 1 ) > max)
            max = ptr->lh + ptr->rh + 1;
        return ( ptr->lh > ptr->rh ? ptr->lh : ptr->rh) + 1;
    }
    else
        return 0;
}
int main()
{
    node *root = NULL,*ptr;
    int n, x, i ;
    cin>>n>>x;
    root = getNode(x);
    char str[12345];
    while(--n){
        cin>>str;
        i = 0;
        ptr = root;
        while(str[i] && ptr ){
            if(str[i] == 'L'){
                if(ptr->left == NULL)
                    ptr->left = getNode(0);
                ptr = ptr->left;
            }
            else{
                if(ptr->right == NULL)
                    ptr->right = getNode(0);
                ptr = ptr->right;

            }
            i++;
        }
        cin>>x;
        ptr->value = x;
    }
    query(root);
    cout<< max<<endl;
    return 0;
}