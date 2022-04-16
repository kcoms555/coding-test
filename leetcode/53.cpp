#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxnum = 0;
        int bestmax = 0;
        for(auto &num : nums){
            maxnum = max(maxnum + num, 0);
            bestmax = max(maxnum, bestmax);
        //    printf("bestmax : %d, maxnum : %d, num : %d\n", bestmax, maxnum, num);
        }
        return bestmax;
    }
};

int main(void){
    Solution sol = Solution();
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    printf("result : %d\n", sol.maxSubArray(nums));
}