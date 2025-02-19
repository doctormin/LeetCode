#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // events,   x,   h,   id,  type (1=entering, -1=leaving)
        vector<Event> events;
        
        int id = 0;
        for (const auto& b : buildings) {
            events.push_back(Event{id, b[0], b[2], 1});
            events.push_back(Event{id, b[1], b[2], -1});
            ++id;
        }
        
        // Sort events by x
        sort(events.begin(), events.end());
        
        // Init the heap
        MaxHeap heap(buildings.size());
        
        vector<pair<int, int>> ans;
        // Process all the events
        for (const auto& event: events) {            
            int x = event.x;
            int h = event.h;
            int id = event.id;
            int type = event.type;            
            
            if (type == 1) { //进入事件
                if (h > heap.Max()) 
                    ans.emplace_back(x, h);
                heap.Add(h, id);
            } else { //离开事件
                heap.Remove(id);
                if (h > heap.Max()) //假如取走了一个max
                    ans.emplace_back(x, heap.Max()); //那么记录次大的点
            }            
        }
        
        return ans;
    }
private:
    struct Event {
        int id;
        int x;       
        int h;
        int type;
        
        // sort by x+, type-, h, 
        bool operator<(const Event& e) const {
            if (x == e.x)                
                // Entering event h from large to small
                // Leaving event h from small to large
                return type * h > e.type * e.h;
            
            return x < e.x;
        }
    };
    
    class MaxHeap {
    public:
        MaxHeap(int max_items): 
            idx_(max_items, -1), vals_(max_items), size_(0) {}
        
        // Add an item into the heap. O(log(n))
        void Add(int key, int id) {
            idx_[id] = size_;
            vals_[size_] = {key, id};
            ++size_;
            HeapifyUp(idx_[id]);
        }
        
        // Remove an item. O(log(n))
        void Remove(int id) {
            int idx_to_evict = idx_[id];
            // swap with the last element
            SwapNode(idx_to_evict, size_ - 1);
            --size_;
            HeapifyDown(idx_to_evict);
            HeapifyDown(idx_to_evict);
        }
        
        bool Empty() const {
            return size_ == 0;
        }
        
        // Return the max of heap
        int Max() const {
            return Empty() ? 0 : vals_.front().first;
        }
    private:
        void SwapNode(int i, int j) {
            if (i == j) return;
            std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
            std::swap(vals_[i], vals_[j]);
        }
        
        void HeapifyUp(int i) {
            while (i != 0)  {            
                int p = (i - 1) / 2;
                if (vals_[i].first <= vals_[p].first) 
                    return;
 
                SwapNode(i, p);                
                i = p;
            }
        }
        
        // Make the heap valid again. O(log(n))
        void HeapifyDown(int i) {
            while (true) {
                int c1 = i*2 + 1;
                int c2 = i*2 + 2;
 
                // No child
                if (c1 >= size_) return;
 
                // Get the index of the max child
                int c = (c2 < size_ 
                      && vals_[c2].first > vals_[c1].first ) ? c2 : c1;
 
                // If key[c] is greater than key[i], swap them and
                // continue to HeapifyDown(c)
                if (vals_[c].first <= vals_[i].first) 
                    return;
                
                SwapNode(c, i);
                i = c;
            }
        }
        
        // {key, id}
        vector<pair<int,int>> vals_;
        
        // Index of the i-th item in vals_ 
        vector<int> idx_;
        
        int size_;
    };
};