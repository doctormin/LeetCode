#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    size_t s1, s2;
    int bit = 0;
    int sum = 0;
    string res;
    if(num1.size() > num2.size()) swap(num1, num2);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    //cout << num1 << endl << num2 << endl;
    for(int i = 0; i < num1.size(); i++){
        int l = num1[i] - '0';
        int r = num2[i] - '0';
        sum = l + r + bit;
        if(sum >= 10){
            bit = 1;
            sum -= 10;
        } else {
            bit = 0;
        }
        res += char(sum + '0');
    }
    for(int i = num1.size(); i < num2.size(); i++){
        int l = num2[i] - '0';
        sum = l + bit;
        if(sum >= 10){
            bit = 1;
            sum -= 10;
        } else {
            bit = 0;
        }
        res += char(sum + '0');
    }
    if(bit == 1) res += char(bit + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2);
}