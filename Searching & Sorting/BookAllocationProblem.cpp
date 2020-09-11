#include <iostream>
using namespace std;
typedef long long int ll;
bool isconfig(ll *a,int n,int m,ll mid){
	int students=1;
	ll current_page_reading=0;
	for (int i = 0; i < n; ++i)
	{
		if(current_page_reading+a[i]>mid){//if the targeted value is less then the current page and current element
			current_page_reading=a[i];
			students++;
			if(students>m){//if number of students gets bigger then m
				return false;
			}
		}
		else{//if the current page and current element is less then the targeted value 
			current_page_reading+=a[i];
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll *a=new ll[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i]; //book pages stored
		}
		//10 20 30 40
		ll s=0,e=0;
		ll total_pages=0;
		for (int i = 0; i < n; ++i)
		{
			total_pages+=a[i];
			s=max(s,a[i]); //40
		}
		e=total_pages;//total number of pages in an array (100)
		ll ans=0;
		while(s<=e){
			ll mid=(s+e)/2;  		//60
			if(isconfig(a,n,m,mid)){
				ans=mid;
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}