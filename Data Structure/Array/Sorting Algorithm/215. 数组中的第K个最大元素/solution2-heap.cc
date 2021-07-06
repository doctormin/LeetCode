//这个反而实测性能更好，理论分析复杂度是O(nlogk)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    size_t s = nums.size();
    multiset<int> heap;
    for(int i = 0; i < k; i++){
        heap.insert(nums[i]);
    }
    for(int i = k; i < s; i++){
        if(*heap.begin() < nums[i]){
            heap.erase(heap.begin());
            heap.insert(nums[i]);
        }
    }
    return *heap.begin();
}

int main(){
    int k;
    cin >> k;
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, k);
}