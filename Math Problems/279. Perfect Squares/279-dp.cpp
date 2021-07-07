#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int minSub = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                minSub = min(minSub, dp[i - j * j]);
            }
            dp[i] = minSub + 1;
        }
        return dp[n];
    }
};