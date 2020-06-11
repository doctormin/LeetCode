//https://leetcode.com/problems/edit-distance/
/*
    算法思路：
    动态规划，维护矩阵dp[word1.size()][word2.size()]
    dp[i][j]表示word1[:i+1] -> word2[:j+1]付出的最小代价
    有转移函数：
    cost1 = dp[i-1][j  ] + 1;
    cost2 = dp[i  ][j-1] + 1;
    cost3 = dp[i-1][j-1] + (word1[i] == word2[j]) ? 0 : 1;
    dp[i][j] = min{cost1, cost2, cost3};
*/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int cost1 = dp[i-1][j  ] + 1;
                int cost2 = dp[i  ][j-1] + 1;
                int cost3 = dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
                dp[i][j]  = min({cost1, cost2, cost3});
            }
        }
        /*
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        return dp[m][n];
    }
};