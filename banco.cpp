#include<iostream>
using namespace std;
#include<vector>
#include<queue>
// bool isval(int i,int j){
//     if(i>4 || j<4){
//         return false;
//     }
//     return true;
// }
// void backtracking(int arr[4][4],int arr2[4][4],int r,int c){
//     for(int i = c ; i < 4 ;i++){
//         if(arr[r][i]!=arr2[r][i] && arr[r][i]==0){
//             arr[r][i]=1;
//             break;
//             return;
//         }
//     }
//     if(isval(++r)){
//         for(int i = r ; i < 4 ;i++){
//             for(int j = 0 ; j < 4 ;j++){
//                if(arr[i][]!=arr2[r][i] && arr[r][i]==0){
//                     arr[r][i]=1;
//                  break;
//                 return;
//         } 
//         }
//     }
//     }
    

// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> banco1;
    vector<string> banco2;
    for(int i = 0 ; i < 4 ; i++){
        string s;
        cin>>s;
        banco1.push_back(s);
    }
    string end = "";
    for(int i = 0 ; i < 4 ; i++){
        string s;
        cin>>s;
        banco2.push_back(s);
        end+=s;
    }
    
    cout<<end;

}