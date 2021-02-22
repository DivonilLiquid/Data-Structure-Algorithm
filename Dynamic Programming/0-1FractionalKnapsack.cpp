#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool sortByRatio(pair<int,int> &a,pair<int,int> &b)
{
    double ratio1 = (double)a.first/a.second;
    double ratio2 = (double)b.first/b.second;
    return ratio1>ratio2;
}

double fun(vector<pair<int,int>> a,int n,int w)
{

    sort(a.begin(),a.end(),sortByRatio);

    double Currweight = 0;
    double valAns = 0;

    for(int i = 0;i<n;i++)
    {

        if(Currweight + a[i].second<=w)
        {

            Currweight += a[i].second;
            valAns += a[i].first;
        }
        else{
            double temp = w-a[i].second;
            valAns += a[i].first*(temp/double(a[i].second));
            break;
        }
    }

    return valAns;

}

int main()
{
    int n;
    cout<<"Enter Number items :";
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++)
    {
        cout<<"For item : "<<i+1<<endl;
        cout<<"Value , Weight : ";
        cin>>a[i].first>>a[i].second;


    }
    int w;
    cout<<"Enter Weight : ";
    cin>>w;
    cout<<"Ans :" <<fun(a,n,w)<<endl;
    return 0;
}
