#include <iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll>v;
bitset<3005> b;
int sieve(int N){
    b.set();      //11111111111111....N
    int pr[N+1]={};
    for(ll i=2;i<=N;i++){
        if(b[i]){
            v.push_back(i);
            for(ll j=i;j<=N;j+=i){
                b[j]=0;
                pr[j]++;
            }
        }
    }
    int ans =0;
    for(int i=2;i<=N;i++){
        cout<<i<<"th index has value"<<pr[i]<<endl;
        if(pr[i]==2){
            ans++;
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int x=sieve(n);
    cout<<x;
    
}













