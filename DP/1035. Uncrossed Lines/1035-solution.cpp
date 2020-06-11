// https://leetcode.com/problems/uncrossed-lines/

/*
题目：
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

+ A[i] == B[j]；
+ The line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

算法思路：
    使用dp, 使用dp[i][j]表示A[i:], B[j:]的线数，有如下转移函数：
    dp[i][j] = max{dp[i+1][j], dp[i][j+1], dp[i+1][j+1] + (if A[i] == B[j])}
*/
#include <vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        if(lenA <= 0 or lenB <= 0)
            return 0;

        int dp[lenA + 1][lenB + 1];

        for(int i = lenA; i >= 0; i--)
            for(int j = lenB; j >= 0; j--){
                dp[i][j] = 0;
            }

        for(int i = lenA - 1; i >= 0; i--)
            for(int j = lenB - 1; j >= 0; j--){
                dp[i][j] = max(dp[i+1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j+1], dp[i][j]);
                dp[i][j] = max(dp[i][j], dp[i+1][j+1] + ((A[i] == B[j])? 1 : 0));
            }
        return dp[0][0];        
    }

};
                