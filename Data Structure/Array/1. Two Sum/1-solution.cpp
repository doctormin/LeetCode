#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i){
            auto res = hashtable.find(target - nums[i]);
            if(res != hashtable.end())
                return {res->second, i};
            hashtable[nums[i]] = i; 
        }
        return {};
    }
};

