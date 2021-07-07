#include<vector>
using namespace std;

#define WHITE 0
#define GRAY   1
#define BLACK  2

class Solution {
public:
    void DFS(int i, vector<vector<int>>&adj, vector<int>& color, bool& flag){
        color[i] = GRAY;
        for(const auto j : adj[i]){
            if(color[j] == WHITE){
                DFS(j , adj, color, flag);
            } else if(color[j] == GRAY){
                flag = true;
                return;
            }
        }
        color[i] = BLACK;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        for(const auto i : prerequisites){
            int src = i[1];
            int tar = i[0];
            adj[src].push_back(tar);
        }
        bool flag = false;
        vector<int> color(numCourses, WHITE);
        for(int i = 0; i < numCourses; i++){
            if(color[i] == WHITE){
                DFS(i, adj, color, flag);
            }
        }
    }
};