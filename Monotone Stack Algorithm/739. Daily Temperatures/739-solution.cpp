//https://leetcode.com/problems/daily-temperatures/
/*
问题:本质上是给了一个序列，求每个数的下一个最大数到自己的距离
解法：用栈（不是典型的单调栈），每次和栈顶作比较
    栈中保存index,遍历所有的元素：
    while(元素比栈顶大)
        出栈，记答案
    入栈
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0)
            return vector<int>(0, 0);
        stack<int> st;
        vector<int> ans(T.size(), 0);
        for(int i = 0; i < T.size(); i++){
            while(!st.empty() and T[i] > T[st.top()]){
                int tmp = st.top();
                st.pop();
                ans[tmp] = i - tmp;
            }
            st.push(i);
        }
        return ans;
    }
};