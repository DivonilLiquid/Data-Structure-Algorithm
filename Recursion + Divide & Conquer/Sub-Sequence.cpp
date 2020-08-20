#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool mycompare(string a,string b){
	return a.length()<b.length();
}
void SubSequence(string s,char *a,int i,int k,int e,vector<string> &v){
	if (s[k]=='\0')
	{
		/* code */
		a[i]='\0';
		string m(a);
		v.push_back(m);
		return;
	}
	else{
		a[i]=s[k];
		SubSequence(s,a,i+1,k+1,e,v);
		SubSequence(s,a,i,k+1,e,v);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	string s;
	cin>>s;
	int n=s.length();
	char *a=new char[n];
	vector<string> v;
	SubSequence(s,a,0,0,n,v);
	sort(v.begin(), v.end(),mycompare);
	for (auto i :v)
	{
		cout<<i<<endl;
	}

	return 0;
}