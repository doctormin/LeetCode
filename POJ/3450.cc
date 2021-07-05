//http://poj.org/problem?id=3450
//此解法为改题简化版 - 输出两个string的 最长公共子串中 字典序排序最小的那个
//先进行O(mn)的遍历，建立dp矩阵，dp[i][j] longest common suffix for text1[:i] and text2[:j]
//然后再进行O(mn)的遍历，对每一个dp max都输出LCS，保存字典序最小的那个
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string LCS(string &x, string &y)
{
    string max_lcs;
    string lcs;
    size_t m = x.size();
    size_t n = y.size();
    int max_l = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        dp[i][0] = (x[i] == y[0]);
    }
    for(int i = 0; i < n; i++){
        dp[0][i] = (x[0] == y[i]);
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << x[i] << y[j] << endl;
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_l = max(max_l, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "max_l = "  << max_l << endl;
    //获取LCS
    if (max_l > 0)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][j] == max_l)
                {
                    lcs = x.substr(i - max_l + 1, max_l);
                    cout << "lcs = " << lcs << endl;
                    if (max_lcs.size() < lcs.size())
                        max_lcs = lcs;
                    else if (max_lcs.size() == lcs.size())
                        max_lcs = min(max_lcs, lcs);
                    cout << "max_lcs = " << max_lcs << endl;
                }
            }
        }
    }
    return max_lcs;
}

int main()
{
    string x, y;
    while (cin >> x >> y)
    {
        cout << LCS(x, y) << endl;
    }
}