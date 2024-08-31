#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& vec, int target);
vector<int> TwoSum(vector<int> arr,int target){
    vector<int> result1;
   for(int i = 0 ; i < arr.size() ;i++){
        if(binarySearch(arr,target-arr[i])!=-1){
            result1.push_back(arr[i]);
            result1.push_back(target-arr[i]);
            break;
        }
   }
   return result1;
}
int binarySearch(vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        }
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    map<int,int> myMap;
    vector<int> arr = {2,7,5,1};
    for(int i = 0 ; i<4;i++){
        myMap[arr[i]]=i+1;
    }
    sort(arr.begin(), arr.end());

    vector<int> result = TwoSum(arr,8);
    cout<<myMap[result[1]]<<" "<<myMap[result[0]];

}