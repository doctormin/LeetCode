#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int maxn;
        int maxRet = 1;
        for(int i = 1; i < nums.size(); i++){
            maxn = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    maxn = max(maxn, 1 + dp[j]);
                }
            }
            dp[i] = maxn;
            maxRet = max(maxRet, dp[i]);
        }
        return maxRet;
    }
};