#include <bits/stdc++.h>
using namespace std;
void Solve(vector<int> arr){
    long begin,end;
    cin>>begin>>end;
    int result=0;
    if(begin<end){
        for(int i = begin-1;i<end-1;i++){
            result+=(arr[i]>arr[i+1])?arr[i]-arr[i+1]:0;
        }
    }
    else if(begin>end){
        for(int i = begin-1;i>end-1;i--){
            result+=(arr[i]>arr[i-1])?arr[i]-arr[i-1]:0;
        }
    }
    cout<<result<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> myArr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>myArr[i];
    }
    while(m--){
        Solve(myArr);
    }
}