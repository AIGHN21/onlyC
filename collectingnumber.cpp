#include<iostream>
using namespace std;
#include<vector>
#include<map>
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> arr2(n);
    map<int,int> maps;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int ans=n;
    for(int i = 0 ; i < n ; i++){
        if(maps[arr[i]-1]==1){
            ans--;
        }
            maps[arr[i]]++;
    }
    cout<<ans;
}
