#include<iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>
typedef long long ll;
void Solve() {
    string s;
    cin >> s;
    set<char> availableChars;
    for (char c = 'a'; c <= 'z'; ++c) {
        availableChars.insert(c);
    }
    for (char c : s) {
        availableChars.erase(c);
    }

    // Lấy ký tự đầu tiên từ tập hợp availableChars
    char toInsert = *availableChars.begin();
    if(s.length()==0){
        s.insert(0, 1, toInsert);
    }
    else if(s.length()==1 ){
        s.insert(1, 1, toInsert);
    }
    else{
    // Thêm ký tự vào vị trí thích hợp
    for (int i = 1; i < s.length(); ++i) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            s.insert(i + 1, 1, toInsert);
            ++i; 
            break;
        }
    }}

    cout << s << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}