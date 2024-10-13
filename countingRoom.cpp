#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const int maxn = 1e3+7;
int m,n;
int mark[maxn][maxn];
char graph[maxn][maxn];
bool validate(int a,int b){
    if(a>=1 && b>=1){
        return true;
    }
    return false;
}
void check(int current , int Columncurrent){
    if(!mark[current][Columncurrent-1] && validate(current,Columncurrent-1) && graph[current][Columncurrent-1]=='.'){
        mark[current][Columncurrent-1] = 1;
        check(current,Columncurrent-1);
    }
    if(!mark[current-1][Columncurrent] && validate(current-1,Columncurrent) && graph[current-1][Columncurrent]=='.'){
        mark[current-1][Columncurrent] = 1;
        check(current-1,Columncurrent);
    }
    if(!mark[current][Columncurrent+1] && validate(current,Columncurrent+1) && graph[current][Columncurrent+1]=='.'){
        mark[current][Columncurrent+1] = 1;
        check(current,Columncurrent+1);
    }
    if(!mark[current+1][Columncurrent] && validate(current+1,Columncurrent) && graph[current+1][Columncurrent]=='.'){
        mark[current+1][Columncurrent] = 1;
        check(current+1,Columncurrent);
    }
    return ;


}
int main(){
    int m,n;
    cin>>m>>n;
    int ans = 0 ;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1; j <= n ; j++){
            cin>>graph[i][j];
        }
    }
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1; j<=n ; j++){
            if(graph[i][j]=='.' && !mark[i][j]){
                mark[i][j]=1;
                check(i,j);
                ans++;
            }
        }
    }
    cout<<ans;

}
