//https://leetcode.com/problems/coin-change-2/
/**
 * You are given coins of different denominations and a total amount of money. 
 * Write a function to compute the number of combinations that make up that amount. 
 * You may assume that you have infinite number of each kind of coin.
 * 
 * 算法思路：使用dp
 * dp[i][j]表示使用前i种面额的coin去组成amount金额的组成数目
 * 初始化：
 *      amount = 0时不管用几种硬币组合数目都是一种
 * 那么有转移方程：
 *      ///!注意：第i种硬币是coin[i-1]
 *      (思路是拿i种面额去凑j = 包含第i种面额凑j + 不包含第i种面额凑j)
 *      dp[i][j] = dp[i - 1][j] + (coin[i-1] > j) ? 0 : dp[i][j - coin[i-1]]
 */
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        int coins_num = coins.size();
        if(coins_num == 0)
            return 0;
        vector<vector<int>> dp(coins_num + 1, vector<int>(amount+1, 0));
        for(int i = 1; i <= coins_num; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= coins_num; i++)
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i - 1][j] + ((coins[i-1] > j) ? 0 : dp[i][j - coins[i-1]]);
            }
        return dp[coins_num][amount];
    }
};
