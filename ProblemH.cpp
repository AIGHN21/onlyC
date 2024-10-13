#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
void Solve(){

}
int main(){
    IO
    double a,b,m;
   cin>>a>>b>>m;
    double v1 = ((a-1)*a*2*(a-1))/ 6;
    double v2 = (b*(b+1)*2*b)/ 6;
    cout<<(v2-v1);
    return 0;
}
