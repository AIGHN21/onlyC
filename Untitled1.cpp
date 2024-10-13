#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const int maxn = 1e3+7;
const int maxm = 1e3+7;
char graph[maxn][maxm];
int mark[maxn][maxm];
int m,n;
vector<char> ans;
int ans2 = 0;
int ans3 = 0;
int flag = 0;
bool validate(int a, int b){
    return (a >= 1 && a <= n && b >= 1 && b <= m);
}
void check(int current , int Columncurrent){
//    cout<<current<<" "<<Columncurrent<<ln;
    if (graph[current][Columncurrent] == 'B') {
        ans3 = ans2;
        flag = 1;
        cout<<"YES"<<ln;
        for (char s : ans) {
            cout << s;
        }
        cout << ln;
        return;
    }
    if(!mark[current][Columncurrent-1] && validate(current,Columncurrent-1) && graph[current][Columncurrent-1]!='#'){
        mark[current][Columncurrent-1] = 1;
        ans2++;
        ans.push_back('L');
        check(current,Columncurrent-1);
        ans2--;
        ans.pop_back();
    }
    if(!mark[current-1][Columncurrent] && validate(current-1,Columncurrent) && graph[current-1][Columncurrent]!='#'){
        mark[current-1][Columncurrent] = 1;
        ans2++;
        ans.push_back('U');
        check(current-1,Columncurrent);
        ans2--;
         ans.pop_back();
    }
    if(!mark[current][Columncurrent+1] && validate(current,Columncurrent+1) && graph[current][Columncurrent+1]!='#'){
        mark[current][Columncurrent+1] = 1;
        ans2++;
        ans.push_back('R');
         check(current,Columncurrent+1);
        ans2--;
         ans.pop_back();
    }
    if(!mark[current+1][Columncurrent] && validate(current+1,Columncurrent) && graph[current+1][Columncurrent]!='#'){
        mark[current+1][Columncurrent] = 1;
        ans2++;
        ans.push_back('D');
        check(current+1,Columncurrent);
        ans2--;
        ans.pop_back();
    }
}
int main(){
    IO
    cin>>n>>m;
    int xstart,ystart;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<=m ; j++){
            cin>>graph[i][j];
            if(graph[i][j]=='A'){
                xstart = i;
                ystart = j;
            }
        }
    }
    mark[xstart][ystart]=1;
    check(xstart,ystart);
    if(flag==0){
        cout<<"NO"<<ln;
    }
    cout<<ans3;


}
