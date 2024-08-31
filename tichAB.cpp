#include <bits/stdc++.h>
#include <vector>  // Thư viện để đo thời gian
using namespace std; 
#include<string>
int maximunCollectCoin(string path,int n){
    int value = 0;
    if(path[0]=='*'){
        return 0;
    }
    for(int i = 0 ;i < n ; i++){
        if(path[i]=='@'){
            value++;
        }
        else if(path[i]=='*' && path[i+1]=='*'){
            break;
        }
    }
    return value;
}
int main() {
    int n,t;
    string input;
    cin>>t;
    cin.ignore();
    int arr[t];
    for(int i = 0 ; i < t ; i++){
       cin>>n;
       cin.ignore();
       getline(cin, input); 
       arr[i]=maximunCollectCoin(input,n);  
    }
    for(int i = 0 ; i < t ; i++){
       cout<<arr[i]<<endl;
    }
    
}
