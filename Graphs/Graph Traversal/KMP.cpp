#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void calculateLPS(string p,int m,int *lps)
{
    int left = 0;
    int right = 1;
    lps[left] = 0;

    while(right<m)
    {
        if(p[left] == p[right])
        {
            left++;
            lps[right] = left;
            right++;
        }
        else{

            if(left != 0)
            {
                left = lps[left-1];
            }
            else{
                lps[right] = 0;
                right++;
            }
        }
    }
}
void KMP(string t,string p,int n,int m)
{
    int *lps = new int[m];
    calculateLPS(p,m,lps);

    int i = 0;
    int j = 0;

    while(i<n)
    {
        if(p[j] == t[i])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout<<"Pattern Found at : "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<n && p[j] != t[i])
        {
            if(j != 0)
            j = lps[j-1];
            else
                i++;
        }
    }

}
int main()
{
    string t,p;
    cout<<"Enter T :";
    cin>>t;
    cout<<"Enter P :";
    cin>>p;

    int n = t.length();
    int m = p.length();

    KMP(t,p,n,m);
    return 0;
}
