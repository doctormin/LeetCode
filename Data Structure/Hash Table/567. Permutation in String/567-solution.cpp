// https://leetcode.com/problems/permutation-in-string/
/*
 * 问题： 检验s2是否含有s1的permutation substring
 * 和438解法一样
 * 使用hash table + sliding window
 * 首先统计s1的字频率，放进hash table
 * 然后遍历s2
 * 伪代码
 * start = end = 0
 * while end < s2.size():
 *     if table[s2[end] - 'a'] > 0
 *          --table[s2[end] - 'a']
 *          end++
 *          checkFinished()
 *          continue
 *     if start == end:
 *          start++
 *          end++
 *     else: table[s2[start++] - 'a']++
 */
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.empty())
            return false;
        //set up the hash table
        vector<int> table(26, 0);
        for(const auto &r : s1){
            ++table[r - 'a'];
        }
        int start = 0;
        int end = 0;
        //对于每一轮循环，有三种case, 1.end++ 2.start++ 3.start++ & end++
        //首先检查是否是case1, 如果不是再检查是否是case3, 如果不是便只能是case2
        while(end < s2.size()){
            if(table[s2[end] - 'a'] > 0){
                --table[s2[end++] - 'a'];
                if(end - start == s1.size()){
                    return true;
                }
                continue;
            }
            if(start == end){
                ++start;
                ++end;
            }else{
                ++table[s2[start++] - 'a'];
            }
        }
        return false;
    }
};