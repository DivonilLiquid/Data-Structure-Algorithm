#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//TO build a Node we should have atleast 3 things that are key , value and a pointer to next node.
//So our class will contain all these things
template<typename T>
class Node{
public:
    string key;//all values will be sorted in this order
    T value;
    //if you don’t make it genric everything remain same no effect
    Node<T>* next;

    //constructor
    Node(string data, T val){
        this->key = data;
        this->value = val;
        next = NULL;
    }
    
    //destructor
    ~Node(){
        while(next!=NULL){
            delete next ; //recursively calling all the other next elements and deleting them in a linked list
        }
    }
};
template<typename T>
class HashTable{
    //will insert node class type in our hastable so that's why two different classes
public:
    Node<T>** table;//pointer pointing to arrray of linked list
    int table_size;
    int current_size;
    /*modulation property:
    (a+b+c)%m == (a%m+b%m+c%m)
    (a*b*c)%m == (a%m*b%m*c%m)
    */
    int HashFunction(string data){
        int index=0;
        int p=1;
        for(int i=0;i<data.length();i++){
            index += (data[i]*p)%table_size;
            index = index%table_size;
            p=(p*27)%table_size;
            //mod of table size is to remove the overflow concept
        }
        return index;
    }
    HashTable(int ts = 7){//passing by default value
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++){
            table[i]=NULL;//setting all indexes value to null by overriding garbage value
        }
    }

    void insert(string data, T val){
        //.......Insert at head of table[idx] in o(1) time, where idx is given by hasfunction in o(1) time
        Node<T>* n = new Node<T>(data,val);
        int index = HashFunction(data);
        n->next = table[index];
        table[index]= n;
        current_size++;
        //rehash.....
        float LoadFactor = current_size/(1.0*table_size);
        if(LoadFactor>=0.7){
        	rehash();
        }
    }
    void rehash(){
    	Node<T>**OldTable = table;//oldtable is pointing to old table
    	int OldTableSize = table_size;
    	table_size = 2*table_size;
    	//new table with same name
    	table = new Node<T>*[table_size];
    	for (int i = 0; i < table_size; ++i)
    	 {
    	 	table[i]=NULL;
    	 } 
    	 current_size = 0;

    	 //shift elements from old table to new table
    	 for (int i = 0; i < OldTableSize; ++i)
    	 {
    	 	auto itr = OldTable[i];
    	 	while(itr!=NULL){
    	 		insert(itr->key,itr->value);
    	 		itr = itr->next;
    	 	}
    	 	//delete entire itr row if it's not equal to null, though having linked list in it
    	 	if(itr!=NULL)
    	 		delete itr;
    	 }
    	 delete [] OldTable;
    }
    void print(){
        for(int i=0;i<table_size;i++){
            cout<<"Bucket is: "<<i<<"->";
            auto itr = table[i];
            while(itr!=NULL){
                cout<<" [key is equal to "<<itr->key<<", with value "<<itr->value<<"]->";
                itr = itr->next;
            }
            cout<<endl;
        }
    }
    T* search(string data){
        //......
        int index = HashFunction(data);
        Node<T>* temp = table[index];
        while(temp!=NULL){
        	if(temp->key == data){
        		return &temp->value;
        	}
        	temp = temp->next;
        }
        return NULL;
    }/*
    void erase{
        //.........
        return ;
    }*/
};

int main() {
    HashTable<int>Menu;
    Menu.insert("Burger",120);
    Menu.insert("Pepsi",20);
    Menu.insert("BurgerPizza",120);
    Menu.insert("Noodles",120);
    Menu.insert("Coke",120);
    //Menu.insert("Burger",120);
    //Menu.insert("Burger",120);
    Menu.print();
    auto price = Menu.search("noodles");
    if(price == NULL){
    	cout<<"Not found";
    }
    else{
    	cout<<"Price is: "<<*price;
    }
    return 0;

}
