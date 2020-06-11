// https://leetcode.com/problems/remove-k-digits/
/*
算法思路：
使用贪婪法，确保每次删除都是局部最优，可以证明全局最优（此处略）
使用一个string result当成单调栈使用
从左往右扫描：
    如果扫到的值比栈顶小 and 栈不空 and k!=0:
            出栈;
            k--;
    入栈
若 k!=0, 当栈不空时
    弹栈
    k--
格式化字符串（删去首位0）
return 字符串
*/
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for(int i = 0; i < num.size(); i++){
            while(result.size() and num[i] < result.back() and k){
                result.pop_back();
                --k;
            }
            if (result.empty() and num[i] == '0')
			    continue;
            result.push_back(num[i]);
        }
        while(k > 0 and !result.empty()){
            result.pop_back();
            --k;
        }
        return result == "" ? "0" : result;
    }
};


int main()
{
    Solution s;
    s.removeKdigits("1432219", 3);
}