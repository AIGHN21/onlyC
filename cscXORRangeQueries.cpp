#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
void Solve(){

}
pair<ll,ll> findXY(vector<pair<char,ll>> qr , int dr,ll M,ll N){
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        ll x1 = 1 , y1 = 1;
            int drt = dr;
            cout<<"huong "<<dr<<ln;
            for(ll i = 1 ;i<= M ; i++){
                cout<<"lan thu "<<i<<"huong "<<x1<<y1<<ln;
                if (qr[i].first == 'A') {
                x1 = x1 + (dx[drt] * qr[i].second )% N ;
                y1 = y1 + (dy[drt] * qr[i].second )% N;
                }
                else if(qr[i].first=='R'){
                    drt+=(drt + qr[i].second) % 4;
                }
                else {
                    ll new_x = qr[i].second / N;
                    ll new_y = qr[i].second % N;
                    x1 = new_x;
                    y1 = new_y;
                }
                }
            return {x1,y1};
    }
int main(){
    IO
    ll n,p,m;
    ll N, P, M;
    cin >> N >> P >> M;
    vector<ll> x(P+1), y(P+1), direction(P+1);
    for (ll i = 1; i <= P; ++i) {
        cin >> x[i] >> y[i] >> direction[i];
    }
    vector<pair<char,ll>> qr(M+1);
    for(ll i = 1 ;i<= M ; i++){
        char s;
        ll k;
        cin>>s>>k;
        qr[i].first=s;
        qr[i].second=k;
    }
    vector<pair<ll,ll>> initial(5);
    for(ll i = 1 ; i<=4;i++){
        initial[i]=findXY(qr,i,M,N);
    }
    for(ll i = 1 ; i<=P;i++){
        x[i]+=initial[direction[i]].first-1;
        y[i]+=initial[direction[i]].second-1;
        cout<<x[i]<<" "<<y[i]<<ln;
    }
}


