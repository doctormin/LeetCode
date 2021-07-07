#include<vector>
#include<stack>
using namespace std;

#define WHITE 0
#define GRAY   1
#define BLACK  2

class Solution {
public:
    void DFS(int i, vector<vector<int>>&adj, vector<int>& color, bool& flag, stack<int>& stk){
        color[i] = GRAY;
        for(const auto j : adj[i]){
            if(color[j] == WHITE){
                DFS(j , adj, color, flag, stk);
            } else if(color[j] == GRAY){
                flag = true;
                return;
            }
        }
        color[i] = BLACK;
        stk.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        stack<int> stk;
        for(const auto i : prerequisites){
            int src = i[1];
            int tar = i[0];
            adj[src].push_back(tar);
        }
        bool flag = false;
        vector<int> color(numCourses, WHITE);
        for(int i = 0; i < numCourses; i++){
            if(color[i] == WHITE){
                DFS(i, adj, color, flag, stk);
            }
        }
        if(flag) return {};
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};