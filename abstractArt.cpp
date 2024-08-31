#include <iostream>
#include <vector>

using namespace std;

void nhapmang(vector<vector<int>>& ds, int m, int n) {
    ds.resize(m, vector<int>(n)); // Khởi tạo kích thước mảng 2D
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Phan tu hang thu " << i + 1 << ", cot thu " << j + 1 << ": ";
            cin >> ds[i][j];
        }
    }
}

int problem(vector<vector<int>> ds) {
    vector<vector<int>> dss;
    dss.resize(4, vector<int>(4, 1));
    for (size_t i = 1; i < ds.size() - 1; i++) {
        size_t k = 0;
        for (size_t j = 1; j < ds[i].size()-1; j++) {
            if (ds[i][j] <= ds[i][k] && dss[i][j]!=2) {
                dss[i][j] = 0;
            } else if(ds[i][j]>ds[i][k]){
                k = j;
                dss[i][j] = 2;
            }
        }
    }
    for (size_t i = 1; i < ds[0].size() - 1; i++) {
        size_t k = 0;
        for (size_t j = 1; j < ds.size()-1; j++) {
            if (ds[j][i] <= ds[k][i] && dss[j][i]!=2) {
                dss[j][i] = 0;
            } else if(ds[j][i]>ds[k][i]){
                k = j;
                dss[j][i] = 2;
            }
        }
    }
    for (size_t i = 1; i < ds.size() - 1; i++) {
        size_t k = ds[i].size() - 1;    
        for (int j = ds[i].size() - 2; j > 0; j--) { // Sử dụng kiểu int cho j để tránh lỗi chỉ số âm
            if (ds[i][j] <= ds[i][k] && dss[i][j]!=2) {
                dss[i][j] = 0;
            } else if(ds[i][j]>ds[i][k]) {
                k = j;
                dss[i][j] = 2;
            }
        }
    }
    for (size_t i = 1; i < ds[0].size() - 1; i++) {
        size_t k = ds.size() - 1;
        for (int j = ds.size() - 2; j > 0; j--) { // Sử dụng kiểu int cho j để tránh lỗi chỉ số âm
            if (ds[j][i] <= ds[k][i] && ds[j][i]!=2) {
                dss[j][i] = 0;
            } else if(ds[j][i]>ds[k][i]) {
                k = j;  
                dss[j][i]=2;
            }
        }
    }
    for (size_t i = 0; i < ds.size(); i++) {
        for (size_t j = 0; j < ds[i].size(); j++) {
            cout << dss[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}

int main() {
    vector<vector<int>> ds;
    nhapmang(ds, 4, 4);
    cout << "Ket qua: " << problem(ds) << endl;
    return 0;
}
