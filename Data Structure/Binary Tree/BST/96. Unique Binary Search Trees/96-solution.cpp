//https://leetcode.com/problems/unique-binary-search-trees/
/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 * 算法：就是卡特兰数， C(2n, n) / (n+1)
 *      可以使用long long, 或者使用杨辉三角dp 即C(i, j) = C(i-1, j-1) + C(i - 1, j)
 */
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        //使用杨辉三角
        vector<vector<unsigned long>> C(2*n + 1, vector<unsigned long>(2*n + 1, 0));
        for(int i = 0; i <= 2*n; i++){
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j = 1; j < i; j++)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        return C[2*n][n] / (n+1);
    }
};