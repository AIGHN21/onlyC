#include<iostream>
using namespace std;
void result(int a1,int b1,int a2,int b2){
    if(a1==b1 || a2==b2){
        cout<<"NO";
    }
    if(a1>b1){
       cout<< ((b2<=a2) ? "YES":"NO");
    }
    else if(a1<b1){
        cout<< ((b2>=a2) ?"YES":"NO");
        }
    }

int main(){
  result(1,2,1,2);
}