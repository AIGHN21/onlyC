#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#include<vector>
#include<unordered_map>
#include<string>
#define fori for(int i = 0 ; i < n ; i++)
vector<int> parent;

int find_from_where(int current,int pos,vector<int> camefrom){
    int k;
        return (pos==camefrom[current])? 1: k = find_from_where(camefrom[current],pos,camefrom)+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int t;
    cin>>t;
    vector<int> arr,result,parent;
    while(t--){
        int n;
        cin>>n;
        arr.resize(n);
        int k;
        fori{
            cin>>k;
            arr[i]=k-1;
        }
        fori{
            cout<<find_from_where(i,i,arr)<<" ";
        }
        
    }

}
