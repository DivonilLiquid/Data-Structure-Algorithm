#include <iostream>
using namespace std;
#define mod 1000000007
long long int power(long long int a,long long int b)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;   
        b=b/2;
    }
    return (res)%mod;
}
long long int poly_hash_string(string n)
{
    long long int p=31,m=1000000007;
    long long int p_power=1;
    long long int hash=0;
    for(int i=0;i<n.size();i++)
    {   
        hash+=p_power* (n[i]-'a'+1);
        p_power*=p;
        p_power=(p_power)%m;
        hash%=m;
    }
    return hash;
}
int main() 
{
    string a;
    string b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    long long int a_hash=poly_hash_string(a.substr(0,m));
    long long int b_hash=poly_hash_string(b);
    long long int inverse_p=power(31,mod-2);
    long long int p=power(31,m-1);
    if(a_hash==b_hash)
    {
        cout<<"0"<<endl;
    }
    for(int i=1;i+m-1<n;i++)
    {
        //Step 1 Delete The first window
        a_hash=(a_hash-(a[i-1]-'a'+1)+mod)%mod;
        
        //Step 2 Divide by B that is nothing but hash/p that is equal o hash*(p^-1) so we have to calculate p inverse
        a_hash=(a_hash*inverse_p)%mod;
        
        //Step 3
        a_hash+=(p*((a[i+m-1]-'a'+1)));
        a_hash=(a_hash)%mod;
        if(a_hash==b_hash)
        {
            cout<<i<<endl;
        }
    }
}
