//https://leetcode.com/problems/the-skyline-problem/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // events,   x,   h,   id,  type (1=entering, -1=leaving)
        vector<Event> events;
        int id = 0;
        for(const auto& b : buildings){
            events.push_back(Event{id, b[0], b[2], 1}); //进入事件
            events.push_back(Event{id++, b[1], b[2], -1}); //离开事件
        }
        sort(events.begin(), events.end());

        vector<vector<int>> ans;

    }
private:
    struct Event{
        int id;
        int x;
        int h;
        int type;

        bool operator < (const Event& e) const{
            if (x == e.x)
                // 如果是进入事件x重合，那么先考虑更高的 (type = 1)
                // 如果是离开事件x重合，那么优先考虑更矮的 (type = -1)
                return type * h > e.type * e.h;
            return x < e.x;
        }
    }
};
