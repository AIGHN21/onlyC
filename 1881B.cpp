#include <bits/stdc++.h>
using namespace std;
void Solve(){
        int a,b,c;
        cin>>a>>b>>c;
        int minValue=a;
        minValue=min(minValue,b);
        minValue=min(minValue,c);
        int count = 0;
        count+=((a%minValue)?4:a/minValue-1);
        count+=((b%minValue)?4:b/minValue-1);
        count+=((c%minValue)?4:c/minValue-1);
        if(count>3){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}