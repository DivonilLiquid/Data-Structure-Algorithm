#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> primes;
const int N = 1005;
ll p[N]={};
//have made sieve
void seive(){
	for(ll i=2;i<=N;i++){
		if(p[i]==0){
			primes.push_back(i);
			for(ll j=i*i;j<=N;j+=i){
				p[j]=1;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	seive();
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
        ll q=n;
		ll pow;
		vector<pair<ll,int>> prime_comb;
		for (ll i = 0; (primes[i]*primes[i]) < n; ++i)
		{
			if(n%primes[i]==0){
			    int power=0;
				while(n%primes[i]==0){
					power++;
					n=n/primes[i];
				}
				prime_comb.push_back(make_pair(primes[i],power));
			}
		}
        if(n>1){
			prime_comb.push_back(make_pair(n,1));
		}
		//cout<<"Divisors of number "<<q<<" are: ";
		/*for (auto i:prime_comb)
		{
			cout<<i.first<<"^"<<i.second<<", ";
		}
		cout<<endl;*/
        if(prime_comb.size()>=3){
            int cnt =0;
            cout<<"YES"<<endl;
            for(auto i: prime_comb){
                if(cnt==3){
                    break;
                }
                cnt++;
                cout<<i.first<<" ";
            }
            cout<<endl;
        }
        if(prime_comb.size()==2){
            cout<<"YES"<<endl;
            int cnt =0;
            ll prod=1;
            for(auto i: prime_comb){
                if(cnt==2){
                    break;
                }
                cnt++;
                prod*=i.first;
                cout<<i.first<<" ";
            }
            cout<<(q/prod)<<endl;
        }
        if(prime_comb.size()==1){
            auto it = prime_comb[0];
            int x = it.second;
            
            if(x<=5){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
                ll a,b,c;
                a=(it.first);
                b=(it.first)*(it.first);
                c=(it.first)*(it.first)*(it.first);
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
        if(prime_comb.size()<1){
            cout<<"NO"<<endl;
        }
	}
	return 0;
}