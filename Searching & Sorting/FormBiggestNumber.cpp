#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool mycompare(int a,int b){
	string X= to_string(a);
	string Y= to_string(b);
	return (X+Y)>(Y+X);
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int l;
			cin>>l;
			v.push_back(l);
		}
		sort(v.begin(), v.end(),mycompare);
		for (auto i : v)
		{
			cout<<i;
		}
		cout<<endl;
	}
	return 0;
}