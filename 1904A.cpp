#include <bits/stdc++.h>
using namespace std;
void Solve(){
        long a,b,x1,y1,x2,y2;
        cin>>a>>b>>x1>>y1>>x2>>y2;
        int count = 0;
        // x1 left and up , x2 right and down
        if(x1<x2 && y1>y2){
            if(a==b){
                if(x1+a == x2-a && y1-b == y2+b){
                    count++;
                }
            }
            else{
                
            }
        }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}