/*
Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in computing palindromes.
You are given a string S containing alphanumeric characters. Find out whether the string is a palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.

Input:
The first line of the input contains T, the number of test cases. T testcases follow.  Each line of the test case contains string 'S'.

Output:
Each new line of the output contains "YES" if the string is palindrome and "NO" if the string is not a palindrome.

Constraints:
1<=T<=100
1<=|S|<=100000
Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

Example:
Input:
2
I am :IronnorI Ma, i
Ab?/Ba

Output:
YES
YES
*/
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
bool checkpalindrome(string s,int e){
	vector<char> v;
	for (int i = 0; i < e; ++i)
	{
		/* code */
		int a=s[i]-'0'+48;
		if(a<=122 && a>=97 ){
			//small
			v.push_back(s[i]);
		}
		else if(a>=48 && a<=57){
			v.push_back(s[i]);
		}
		else if(a<=90 && a>=65){
			//big
			char b=tolower(s[i]);
			v.push_back(b);
		}
	}
	int l=v.size();
	bool flag=true;
	for(int i=0;i<l;i++){
		if(v[i]!=v[l-i-1]){
			flag=false;
			break;
		}
	}
	return flag;
}

//a=97;z=122
//A=65;Z=90
//a-A=32
//0=48 ;9=57
int main(int argc, char const *argv[])
{
	string s;
	int t;
	cin>>t;
	while(t--){
		getline(cin,s);
		while ((int) s.size() == 0) 
			getline(cin, s);
		if(checkpalindrome(s,s.length()))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
