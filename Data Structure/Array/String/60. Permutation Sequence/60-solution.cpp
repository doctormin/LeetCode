//https://leetcode.com/problems/permutation-sequence/
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        string ans;
        for(int i = 1; i <= n; i++){
            s.append(to_string(i));
        }
        ans = s;
        for(int i = 0; i < k-1; i++){
            next_permutation(ans.begin(), ans.end());
            //cout << ans << endl;
        }
        return ans;
    }
};

//TODO: Use a faster way