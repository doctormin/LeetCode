#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int qSort(vector<int>& v, int l, int r, int k){
    int pivot = v[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(v[j] <= pivot)
            swap(v[++i], v[j]);
    }
    swap(v[r], v[i + 1]);
    int index = i + 1;
    if(index == k) 
        return v[index];
    else if(index > k) 
        return qSort(v, l, index - 1, k);
    else 
        return qSort(v, index + 1, r, k);
}

int findKthLargest(vector<int>& nums, int k) {
    size_t s = nums.size();
    return qSort(nums, 0, s - 1, s - k);
}

int main(){
    int k;
    cin >> k;
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, k);
}