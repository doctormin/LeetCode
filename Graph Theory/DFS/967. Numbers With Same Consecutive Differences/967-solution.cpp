//https://leetcode.com/problems/numbers-with-same-consecutive-differences/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N == 1) ans.push_back(0);
        for(int i = 1; i <= 9; i++)
            DFS(N-1, K ,i, ans);
        return ans;
    }
private:
    void DFS(int N, int K, int i, vector<int>& ans){
        if(N == 0){
            ans.push_back(i);
            return;
        }
        int j = i % 10;
        if(j + K <= 9)
            DFS(N-1, K, 10 * i + j + K, ans);
        if(j - K >= 0)
            DFS(N-1, K, 10 * i + j - K, ans);
    }
};