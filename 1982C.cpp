#include <bits/stdc++.h>
using namespace std;
void Solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    vector<int> marked(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int rs = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= r && arr[i] >= l) {
            marked[i] = 1;
            rs += 1;
        }
    }

    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (marked[i] != 1) {
            tong += arr[i];
            if (tong <= r && tong >= l) {
                tong = 0;
                rs += 1;
            } else if (tong > r) { // Fix: should be "tong > r" instead of "tong >= r"
                tong = 0;
            }
        } else {
            if (tong <= r && tong >= l) {
                rs += 1;
            }
            tong = 0;
        }
    }
    cout << rs << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}