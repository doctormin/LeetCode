// https://leetcode.com/problems/find-all-anagrams-in-a-string/
/*
 * 算法思路
 * 我们要在s里面寻找p的anagrams
 * 首先用一个长度为26的hash table储存p的字母频率（用以匹配anagrams)
 * 然后用slide window的方法遍历s，来寻找所有可能的匹配
 * 首先初始化start = end = 0
 * 当end < s.size();
 *   1. 递增end如果s[end]在hash table中对应的元素大于0，将该元素递减
 *      check()
 *   3. 如果start == end, 两者一起递增
 *      否则，递增start，将hash table[start]++
 **/
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.empty())
            return result;
        //set up the hash table
        vector<int> table(26, 0);
        for(const auto &r : p){
            ++table[r - 'a'];
        }
        int start = 0;
        int end = 0;
        //对于每一轮循环，有三种case, 1.end++ 2.start++ 3.start++ & end++
        //首先检查是否是case1, 如果不是再检查是否是case3, 如果不是便只能是case2
        while(end < s.size()){
            if(table[s[end] - 'a'] > 0){
                --table[s[end++] - 'a'];
                if(end - start == p.size()){
                    result.push_back(start);
                }
                continue;
            }
            if(start == end){
                ++start;
                ++end;
            }else{
                ++table[s[start++] - 'a'];
            }
        }
        return result;     
    }
};