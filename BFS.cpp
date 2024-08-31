#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<vector<int>> findVector(int n){
    vector<vector<int>> listKe(n);
    for(int i = 0 ; i < n;i++){
        cout<<"dinh thu "<<i<<endl;
        cout<<"Nhap so canh ke";
        int socanh;
        cin>>socanh;
        for(int j=0;j<socanh;j++){
            cout<<"canh thu "<<j + 1<<" ";
            int tencanh;
            cin>>tencanh;
            listKe[i].push_back(tencanh);
        }
    }

    return listKe;
}
void BFS(vector<vector<int>> dske,int visted[]){
    queue<int> hangdoi;
    hangdoi.push(0);
    while(!hangdoi.empty()){
        int value = hangdoi.front();
        cout<<value<<" ";
        for(int vertix:dske[value]){
            if(!visted[vertix]){
                hangdoi.push(vertix);
                visted[vertix]=1;
            }
        }
        hangdoi.pop();
    }
}
int main(){
    cout<<"nhap so dinh ";
    int vertix;
    cin>>vertix;
    vector<vector<int>> result = findVector(vertix);
    for(int i = 0;i<result.size();i++){
        vector<int> var = result[i];
        cout<<"dinh thu "<<i<<endl;
        for(int j = 0 ;j<var.size();j++){
            cout<<var[j]<<" ";
        }
        cout<<endl;
    }
    
    int visted[vertix]={0};
    BFS(result,visted);
}