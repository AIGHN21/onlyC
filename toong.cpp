#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 int maxSubArray(vector<int>& nums) {
        for(int i = 1 ; i < nums.size() ; i++){
            nums[i] = max(nums[i-1]+nums[i],nums[i]);
        }
        cout<<endl;
        for(int i = 0 ; i < nums.size() ; i++){
            cout<<" "<<nums[i];
        }
        return nums[nums.size()-1];
    }
int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
}
