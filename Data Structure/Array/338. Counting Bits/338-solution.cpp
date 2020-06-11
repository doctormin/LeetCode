//https://leetcode.com/problems/counting-bits/

/*
算法思路：
    今日不想思考 直接built-in function 
*/

#include<vector>
#include<bitset>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i = 0; i <= num; i++){
            ans.push_back(bitset<32>(i).count());
        }
        return ans;
    }
};