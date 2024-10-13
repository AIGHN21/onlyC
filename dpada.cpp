#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

void Solve(){
    ll n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<int> dp(n, 0);
    int ix = n;

    if ((s1[n-1] - '0' + s2[n-1] - '0') % 10 != (s3[n-1] - '0')) {
        dp[n-1] = 1;
    } else {
        dp[n-1] = 0;
    }

    for (int i = n-2; i >= 0; i--) {
        if ((s1[i] - '0' + s2[i] - '0') % 10 != (s3[i] - '0')) {
            if ((s3[i] - '0') - (s2[i] - '0') == 1) {
                dp[i] = min(i - ix - 1, dp[i+1]);
                if((s1[i] - '0' + s2[i] - '0'+1)>=10){
                    ix = i;
                    }
            } else {
                dp[i] = dp[i+1] + 1;
            }

        } else {
            dp[i] = dp[i+1];
        }
        if((s1[i] - '0' + s2[i] - '0')>=10){
                ix = i;
        }
    }
    for(ll i = 0 ; i<=n;i++){
        cout << dp[i] << " ";
    }
}

int main() {
    IO
    Solve();
    return 0;
}
