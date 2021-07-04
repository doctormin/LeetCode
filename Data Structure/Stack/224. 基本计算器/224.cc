//https://leetcode-cn.com/problems/basic-calculator/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int calculate(string s) {
    stack<int> stk;
    int sign = 1;
    int ans = 0;
    int num;
    stk.push(1);
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == ' ') continue;
        if(c == '(')
            stk.push(sign);
        else if(c == ')')
            stk.pop();
        else if(c == '+')
            sign = stk.top();
        else if(c == '-')
            sign = -1 * stk.top();
        else if(isdigit(c)){
            int j = i;
            while(j != s.size() && isdigit(s[j])) j++;
            num = atoi(s.substr(i, j-i).c_str());
            ans += sign * num;
            i = j - 1;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << calculate(s);
}