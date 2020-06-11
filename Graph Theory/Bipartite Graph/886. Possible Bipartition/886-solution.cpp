//https://leetcode.com/problems/possible-bipartition/

/*
 *算法思路：
 * 首先根据提供的边得到邻接矩阵
 * 然后进行BFS (实际上是对很多联通分支进行BFS)
 * 对于每一个联通分支进行如下操作：（实际上矛盾只发生在一个连通分支内部，不同连通分支之间并不打搅）
 * 1. 进行交替染色
 * 2. 如果交替染色进行不下去了就return false
 * 
 * 如果成功的完成了BFS和交替染色return true
 */
#include<vector>
#include<queue>
using namespace std;
#define WHITE 0
#define BLUE  1
#define RED   2

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N + 1); // adjacency list for undirected graph
        vector<int> color(N + 1, WHITE); // color of each vertex in graph, initially WHITE
        vector<bool> explored(N + 1, false); // to check if each vertex has been explored exactly once
        for(const auto & edge : dislikes){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(not explored[i]){
                /* 
                 * 拿到的都是连通分支中的第一个被处理的,
                 * 因为同一个联通分支中的其他点会在while子循环中处理完全
                 */
                color[i] = RED;
                q.push(i);
                //处理一个完整的连通分支
                while(not q.empty()){
                    auto u = q.front();
                    q.pop();
                    for(const auto & p : adj[u]){
                        //要检查一个点和所有已染色的是否存在染色冲突
                        if(explored[p]){
                            if(color[p] == color[u])
                                return false;
                            continue;
                        } 
                        //将所有尚未被染色的邻居染色并放入检查队列
                        color[p] = (color[u] == RED) ? BLUE : RED;
                        explored[p] = true;
                        q.push(p);
                    }
                }
            }
        }
        return true;
    }
};