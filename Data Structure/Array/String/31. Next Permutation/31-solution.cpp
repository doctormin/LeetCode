// https://leetcode.com/problems/next-permutation/
/*
    抖个机灵，直接使用std::bool next_permutation (BidirectionalIterator first,
                         BidirectionalIterator last);
                         
    http://www.cplusplus.com/reference/algorithm/next_permutation/
*/
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};