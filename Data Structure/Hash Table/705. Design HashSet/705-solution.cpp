//https://leetcode.com/problems/design-hashset/
#include <list>
#include <vector>
using namespace std;
class MyHashSet {
private:
    int prime;
    vector<list<int>> table;

    int get_key(int value){
        return value % prime;
    }

    list<int>::iterator search(int value) {
		int h = get_key(value);
		return find(table[h].begin(), table[h].end(), value);
	}

public:
    /** Initialize your data structure here. */
    MyHashSet() : prime(10007), table(prime) {}
    
    void add(int value) {
        int key = get_key(value);
        if(!contains(value))
            table[key].push_back(value);
    }
    
    void remove(int value) {
        int key = get_key(value);
        auto i = search(value);
        if(i != table[key].end())
            table[key].erase(i);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int value) {
        int key = get_key(value);
        return search(value) != table[key].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


