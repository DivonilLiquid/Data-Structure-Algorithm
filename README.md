# Data-Structure-Algorithm
# Any contribution to this repository is highly encouraged.

Famous Questions of Data Strucutre and Algorithms on LeetCode & Many other Coding Sites.
Have used dynamic arrays (vector), queues (queue), stacks (stack), heaps (priority_queue), linked lists (list), trees (set), associative arrays (map)...

Many containers have several member functions in common, and share functionalities. The decision of which type of container to use for a specific need does not generally depend only on the functionality offered by the container, but also on the efficiency of some of its members (complexity). This is especially true for sequence containers, which offer different trade-offs in complexity between inserting/removing elements and accessing them.

stack, queue and priority_queue are implemented as container adaptors. Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle the elements. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.


Container class templates
Sequence containers:
array Array class (class template )
vector Vector (class template )
deque Double ended queue (class template )
forward_list Forward list (class template )
list List (class template )

Container adaptors:
stack LIFO stack (class template )
queue FIFO queue (class template )
priority_queue Priority queue (class template )

Associative containers:
set Set (class template )
multiset Multiple-key set (class template )
map Map (class template )
multimap Multiple-key map (class template )

Unordered associative containers:
unordered_set Unordered Set (class template )
unordered_multiset Unordered Multiset (class template )



My C++ Programming Template that i use:
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

 
#define ll long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string p; /*To check if it's working on your system or not*/
	cin>>p;
	cout<<p<<endl;
	return 0;
}
