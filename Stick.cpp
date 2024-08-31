#include <bits/stdc++.h>
using namespace std;
#include<math.h>
int a[10000];
int n,c;
bool check(int mid){
    int cc = a[0];
    int p  = c -1;
    for(int i = 1 ; i <= n ;++i ){
            if(a[i]-cc==mid){
                cc = a[i];
                --p;
            }
    }
    return p==0;
}
int main(){
   int l = 1,r=1000000000, Max = 0;
   int mid = l + r;
    while(l < r){
        if(check(mid)){
            Max = max(Max,mid);
        }
        else{
            r = mid;
        }
        mid = l+r;
    }

}
