//https://leetcode.com/problems/sort-colors/description/
/*
 *题目大意：
 *   说白了就是给了一个仅由0 1 2组成的数组，要求排序
 */

#include <vector>
#include <iostream>
using namespace std;
//Way 1 - counting sort O(n + k)  (k是数据范围，n是数组长度)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = nums.size();
        vector<int> C(3, 0); //Counting Array //O(k) - 初始化
        vector<int> B(l, 0); //Result Array   //O(n) - 初始化
        for(const auto &each : nums)  //O(n) - 计数
            C[each]++;
        for(int i = 1; i < 3; i++) //O(k) - 计数累加
            C[i] += C[i-1];
        for(int i = 0; i < l; i++){ //O(n)
            B[C[nums[i]] - 1] = nums[i];
            C[nums[i]]--;
        }
        nums = B; //O(n)
    }
};

//Way 2 - 这题很特殊，只有三个元素，所以做一次partition就结束了(one pass & in-place)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                    
                case 0:
                    swap(nums[low],nums[mid]);
                    mid++;
                    low++;
                    break;
                
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high]);
                    high--;
                    break;
            }
        }
        
    }
};