#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int n;
    cin>>n;
    vector<int> tree(n);
    for(int i=0;i<n;i++){
       cin>>tree[i];
    }
    int index = 0;
    int count = 0;
    int maxTree = tree[0];
    for(int i = 1 ; i < n ; i++){
        if(tree[i]>maxTree && i - index > 1){
            count+=maxTree;
            maxTree = tree[i];
            index = i;
        }
        else if(tree[i]==tree[i-1] && tree[i]==maxTree){
            count=count+1;
        }
    }
    if(tree[n-1]=maxTree || count==0){
        count+=maxTree;
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}