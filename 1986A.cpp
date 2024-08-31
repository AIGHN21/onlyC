#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        double x1,x2,x3;
        cin>>x1>>x2>>x3;
        double maxValue = x1;
        maxValue = max(maxValue,x2);
        maxValue = max(maxValue,x3);
        double minValue = x1;
        minValue = min(minValue,x2);
        minValue = min(minValue,x3);
        double avg = x1+x2+x3-minValue-maxValue;
        cout<<abs(x1-avg)+abs(x2-avg)+abs(x3-avg)<<endl;
    }
}