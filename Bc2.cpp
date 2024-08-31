#include <iostream>
#include <vector>
#include <map>

using namespace std;
int check(map<int,int> hz, int target){
    return (hz[target]==0)?1:hz[target];
}
// Hàm đếm số lượng good nodes
int countGoodNodes(vector<vector<int>>& edges) {
    map<int, vector<int>> mymap;
    map<int, int> hz;

    // Tạo đồ thị từ danh sách cạnh
    for (const auto& edge : edges) {
        mymap[edge[0]].push_back(edge[1]);
        hz[edge[0]]++;
    }
    for (const auto& edge :mymap) { 
        cout<<edge.first<<": [";
        for(int x:edge.second){
           cout<<x<<" ";
        }
         cout<<"] "<<endl;
    }

for (const auto& edge :hz) { 
       cout<<edge.first<<" :"<<edge.second<<" ";
    }
    int count = 0;

    // Đếm số lượng good nodes
    for (const auto& pair : mymap) {
        int node = pair.first;
        const vector<int>& children = pair.second;

        if (children.size() == 1) {
            count++;
        } else {
            int checkSize = 0;
            for (int i = 1; i < children.size(); i++) {
                if (hz[children[i]] == hz[children[0]]) {
                    checkSize++;
                }
            }
            for (int i = 0; i < children.size(); i++) {
                if(hz[children[i]]==0){
                    count++;
                }
            }
            if (checkSize == children.size() - 1) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{1,4},{0,5},{5,6},{6,7},{7,8},{0,9},{9,10},{9,12},{10,11}};
    cout << countGoodNodes(edges) << endl;
}
