#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<stack>
using namespace std;
const ll maxn = 1e5+7;
vector<ll> adj[maxn];
ll mark[maxn];
stack<ll> stk;
bool fl = false;
void dfs(ll cur,ll target){
    mark[cur]=1;
    stk.push(cur);
    if(cur==target && mark[cur]==1){
        fl = true;
        return ;
    }
    for(ll x:adj[cur]){
        if(!mark[x]){
            dfs(x,1);
            if(fl==true){
                return;
            }
        }
    }
    if(fl==0){
        stk.pop();
    }

}
void Solve(){
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    if(fl==true){
        cout<<stk.empty();
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

}

int main(){
    IO
        Solve();
    return 0;
}
