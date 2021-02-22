#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(i%2==0){
                //alice
                if(s[i]>='b' && s[i]<='z'){
                    s[i]='a';
                }
                else{
                    if(s[i]=='a'){
                        s[i]='b';
                    }
                }
            }
            else{
                //bob
                if(s[i]>='a' && s[i]<='y'){
                    s[i]='z';
                }
                else{
                    if(s[i]=='z'){
                        s[i]='y';
                    }
                }
            }
        }
        cout<<s<<endl;
    }
}
