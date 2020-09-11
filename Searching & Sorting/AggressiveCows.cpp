#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
bool IsValidPos(ll *a,ll n,ll actual_distance,ll c){
	//a ->1 2 4 8 9    n = 5    mid = 4    c=3
	ll current_cows_pos=a[0];
	ll Number_of_cows_placed=1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i]-current_cows_pos>=actual_distance)
		{
			current_cows_pos=a[i];
			Number_of_cows_placed++;
			if (Number_of_cows_placed==c)
			{
				return true;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		ll n,c;
		cin>>n>>c;
		ll *a=new ll[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);//1 2 4 8 9
		ll start=a[0]; //1
		ll end=a[n-1]-a[0]; //8
		ll ans=0;
		while(start<=end){
			ll mid=(start+end)/2;//4
			if (IsValidPos(a,n,mid,c))// 5 , 4 , 3
			{
				ans=mid;
				start=mid+1;
			}
			else{
				end=mid-1;
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}