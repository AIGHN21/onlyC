#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="booboooboobooooboobooobooboooo";
    int n = 23;
    int x = s.length();
    int inital = x;
    int i = 0;
    while(x<n){
        i++;
        x=x*2+i+3; 
    }
    while(n>inital){
    int val = n-(x-i-3)/2;
    if(val >= 1 && val <= i + 2 ){
        cout<<"o";
        n = -1;
        break;
    } 
    else if(n - val/2 == 0){
        cout<<"b";
        n = -1;
        break;
    }
    else if(val > i + 2){
        x = (x - i - 3)/2;
        n = n - (i + 3);
        n = n  % x;
        i--;
    }
    }
    if(n<inital && n != -1){
        cout<<s[n];
    }

}