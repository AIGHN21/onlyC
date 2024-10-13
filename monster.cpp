#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const int maxn = 1e3+7;
int m,n;
char graph[maxn][maxn];
int mark[maxn][maxn];
vector<char> rs;
using namespace std;
bool validate(int a,int b){
    if(a>0 && b>0){
        return 1;
    }
    return 0;
}
void check(int row,int col){
    if((col == 1 || col == n ) || (row == 1 || row == n)){
        for(char s:rs){
            cout<<s;
        }
        cout<<ln;
    }
    if(graph[row][col-1]=='.' && !mark[row][col-1] && validate(row,col-1)){
        rs.push_back(graph[row][col-1]);
        check(row,col-1);
    }
    if(graph[row-1][col]=='.' && !mark[row-1][col] && validate(row-1,col)){
        rs.push_back(graph[row-1][col]);
        check(row-1,col);
    }
    if(graph[row][col+1]=='.' && !mark[row][col+1] && validate(row,col+1)){
        rs.push_back(graph[row][col+1]);
        check(row,col+1);
    }
    if(graph[row+1][col]=='.' && !mark[row+1][col] && validate(row+1,col)){
        rs.push_back(graph[row+1][col]);
        check(row+1,col);
    }
    rs.pop_back();
    return ;
}
int main(){
    IO
    cin>>m>>n;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin>>graph[i][j];
        }
    }
    int x_start , y_start;
    for(int i = 1; i <= m ; i++){
        for(int j = 1 ; j<= n ;j++){
            if(graph[i][j]=='A' && mark[i][j]==1){
                x_start=i;
                y_start=j;
                break;
            }
        }
    }
    check(x_start,y_start);
    return 0;
}
