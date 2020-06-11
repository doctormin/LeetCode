//https://leetcode.com/problems/course-schedule/

/*  
    题目：
        本质是一个dependence graph,必须是有向无环图
        所以检测是否有环存在即可
    算法思路：
        首先根据依赖关系得到邻接表
        然后进行DFS->检测DFS的过程中有没有产生后向边
        - 如果检测到了环的存在（当且仅当存在后向边），那么就return false
        - 否则return true

        后向边存在当且仅当指向了GRAY的节点 时间戳(DFS NUMBER)不需要
    时间复杂度:
        O(|V|+|E|)
*/
#include<vector>
using namespace std;

#define WHITE 0
#define GRAY   1
#define BLACK  2
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //得到邻接表
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses, WHITE);
        for(const auto & each : prerequisites){
            auto src = each[1];
            auto tar = each[0];
            adj[src].push_back(tar);
        }
        bool flag = true;
        for(int i = 0; i < numCourses; i++){
            if(color[i] == WHITE)
                DFS(i , adj, color, flag);
        }
        return flag;
    }

    void DFS(
             int node, 
             vector<vector<int>> &adj, 
             vector<int> &color,
             bool &flag
            )
    {
        color[node] = GRAY;
        //cout << node << " color:" << color[node] << " timestamp:" << timestamp << endl;
        for(const auto & each : adj[node]){
            if(color[each] == WHITE){
                DFS(each, adj, color, flag);
            }
            else if(color[each] == GRAY){
                flag = false; //产生了后向边
                return;
            }
        }
        color[node] = BLACK;
    }
};