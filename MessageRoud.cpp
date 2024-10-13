    #include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<queue>
#include<stack>
using namespace std;
const ll maxn = 1e5+7;
const ll maxm = 2e5+7;
ll n,m;
vector<ll>adj[maxn],visted(maxn);
vector<ll>comefrom(maxn);
bool flag = 0;
int main(){
    cin>>n>>m;
    stack<ll> stk;
    vector<pair<ll,ll>> edges(m+1);
    for(ll i = 1 ;i <= m ; i++){
        cin>>edges[i].first>>edges[i].second;
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    queue<ll> q;
    q.push(1);
    comefrom[1]=0;
    while(!q.empty()){
        ll val = q.front();
        visted[val] = 1;
        q.pop();
        for(ll v : adj[val]){
            if(!visted[v]){
                q.push(v);
                visted[v] = 1;
                comefrom[v]=val;
                if(v==n){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==1){
            break;
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE";
    }
    else{
        ll x = n;
        ll ans = 1;
        while(n!=1){
        n = comefrom[n];
        ans++;
            stk.push(n);
        }
        cout<<ans<<ln;
        while(!stk.empty()){
                ans++;
            cout<<stk.top()<<" ";
            stk.pop();
        }
        cout<<x;
    }
    return 0;
}
