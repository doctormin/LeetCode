//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//ZYM-solution : https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/680657/C%2B%2B-faster-than-90-HashMap-%2B-sliding-window
/*
 * 找到最长的没有重复字母的子串
 * 算法思路：
 *      准备一个HashMap(即一个含26个位置的数组)来验证是否出现了重复字母
 *      使用两个指针分别指向子串的头和尾
 *      一旦出现了冲突，首先更新max, 然后头指针移动到冲突位的下一位，尾指针位置不变
 */
#include <vector>
#include <string>
#define index(h) (int)s[h]
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(126, -1);
        int h   = 0; //head pointer 
        int t   = 1; //tail pointet
        int Max = 1; //Max >= 1
        int l   = s.size();
        if(l <= 1)
            return l;
        v[index(h)] = 0;
        while(t < l){
            if(v[index(t)] == -1){
                v[index(t)] = t;
                ++t;
                //cout << "t = " << t << endl;
            }
            else{
                Max = max(Max, t - h);   
                auto confilct_index =v[index(t)];
                for(int i = h; i <= confilct_index; i++)
                    v[index(i)] = -1;
                h = confilct_index + 1;
                //cout << "h = " << h << endl;
            }
        }
        return Max;
    }
};

