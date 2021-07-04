#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool isOp(string s){
    return s == string("+") || s == string("-") || s == string("*") || s == string("/");
}

string calculate(int l, int r, string op){
    if(op == string("+")) return to_string(l + r);
    if(op == string("-")) return to_string(l - r);
    if(op == string("*")) return to_string(l * r);
    if(op == string("/")) return to_string(int(l / r));
}

int evalRPN(vector<string>& tokens) {
    stack<string> sk;
    string s;
    string l, r, res;
    for(int i = 0; i < tokens.size(); i++){
        s = tokens[i];
        if(!isOp(s)){
            sk.push(s);
        } else {
            r = sk.top();
            sk.pop();
            l = sk.top();
            sk.pop();
            res = calculate(atoi(l.c_str()), atoi(r.c_str()), s);
            sk.push(res);
        }
    }
    return atoi(sk.top().c_str());
}

int main(){
    vector<string> tokens;
    evalRPN(tokens);
}