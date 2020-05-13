// https://leetcode.com/problems/trapping-rain-water/
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
/*
使用单调栈的思想
Runtime: 4 ms, faster than 96.64% of C++ online submissions for Trapping Rain Water.
遍历height数组
1. 如果栈为空或者栈st.top() > height[i], 那么就入栈
2. 否则：（此时栈顶一定不空且栈顶元素的高度 < height[i])
   2.1 那么先将栈顶出栈，
        2.1.1 如果出栈后栈空了那么意味着无法形成水坑
        2.1.2 如果出栈后栈不空，那么新的栈顶一定比刚刚出栈得元素得高度要高，和height[i]就构成了水坑的两堵墙
              此时result += (i - st.top()) * min{height[st.top()], height[i]},回到2.1 直到栈空或者栈顶元素比height[i]高
*/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            if(st.empty() or height[st.top()] > height[i]){
                st.push(i);
                continue;
            }
            while(true){
                auto p = st.top();
                st.pop();
                if(st.empty()){
                    st.push(i);
                    break;
                }
                else{
                    result += (min(height[i], height[st.top()]) - height[p]) * (i - st.top() - 1);                
                    if(height[st.top()] > height[i]){
                        st.push(i);
                        break;
                    }
                }
            }
        }
        return result;
    }
};