#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++){ 
        cin>>arr[i];
        }
        int maxV = 0;
        int maxValue = 0;
    vector<int> arr2(n,1);
    for(int i = 1 ; i < n ; i++){
        int flag = 0;
        maxV = 0;
        for(int j = i-1 ; j >= 0 ; j--){
            if(arr[j]>arr[i] && arr2[j]>maxV){
                maxV = arr2[j];
                flag = 1;
            }
        }
        if(flag){
            arr2[i]=arr2[i]+maxV;
            flag = 0;
        }
        
        maxValue = max(arr2[i],maxValue);
    }
        cout<<maxValue;
}