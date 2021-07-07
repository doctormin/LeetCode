#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> >dp(n, vector<int>(n, 0));
        int maxLen = 0;
        int maxLeft = 0; 
        int maxRight = 0;
        for(int length = 0; length < n; length++){
            for(int left = 0; length + left <= n - 1; left++){
                int right = left + length;
                if(right == left) 
                    dp[left][right] = 1;
                else if(length == 1) 
                    dp[left][right] = (s[left] == s[right]);
                else{
                    dp[left][right] = dp[left + 1][right - 1] && (s[left] == s[right]); 
                }
                if(dp[left][right] && right - left + 1 > maxLen){
                    maxLeft = left;
                    maxRight = right;
                }
            }  
        }
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
};