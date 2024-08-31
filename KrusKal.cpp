#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
struct Edge{
    int a,b,c;
};
vector<int> visted(6,0);
vector<int> DSU ={0,1,2,3,4,5};
void print(vector<vector<int>> adjacencyMatrix){
    for (int i = 0; i <adjacencyMatrix.size(); ++i) {
        for (int j = 0; j <adjacencyMatrix.size(); ++j) {
            if (adjacencyMatrix[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << adjacencyMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int MinTree(vector<Edge> dsCanh){
    int tong=0;
    for(Edge edge:dsCanh){
        if(DSU[edge.a] != DSU[edge.b]){
            tong+=edge.c;
            DSU[edge.b]=DSU[edge.a];
            for()
        }
    }
}
vector<Edge> danhsachcanh(vector<vector<int>> adjacencyMatrix){
    vector<Edge> result;
 for (int i = 0; i <adjacencyMatrix.size(); ++i) {
        for (int j = i+1; j <adjacencyMatrix.size(); ++j) {
            if (adjacencyMatrix[i][j] != INF && adjacencyMatrix[i][j] !=0) {
              result.push_back({i,j,adjacencyMatrix[i][j]});
            }
        }
    }
    return result;
}
int main() {
    const int n = 6; // số đỉnh
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, INF));
    adjacencyMatrix[0][1] = 7;
    adjacencyMatrix[1][0] = 7;
    adjacencyMatrix[0][2] = 9;
    adjacencyMatrix[2][0] = 9;
    adjacencyMatrix[0][5] = 14;
    adjacencyMatrix[5][0] = 14;
    adjacencyMatrix[1][2] = 10;
    adjacencyMatrix[2][1] = 10;
    adjacencyMatrix[1][3] = 15;
    adjacencyMatrix[3][1] = 15;
    adjacencyMatrix[2][3] = 11;
    adjacencyMatrix[3][2] = 11;
    adjacencyMatrix[2][5] = 2;
    adjacencyMatrix[5][2] = 2;
    adjacencyMatrix[3][4] = 6;
    adjacencyMatrix[4][3] = 6;
    adjacencyMatrix[4][5] = 9;
    adjacencyMatrix[5][4] = 9;

    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[i][i] = 0;
    }

    // In ma trận kề
    

    return 0;
}