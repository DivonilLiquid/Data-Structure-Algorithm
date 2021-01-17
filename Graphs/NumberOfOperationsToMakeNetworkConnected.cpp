/*
Number of Operations to Make Network Connected
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

Example 4:
Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
 

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.
*/
class Solution {
    void dfs(unordered_map< int,vector<int> > &adj,int Current_Index,vector<bool> &map){
        map[Current_Index]=true;
        for(auto i: adj[Current_Index]){
            if(map[i]==false){
                dfs(adj,i,map);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //if edges are less then n-1, 
        //then answer will be -1 cause Spanning tree has n-1 edges, where n is the number of nodes(vertices).
        
        if(connections.size()<n-1 && connections.size() != n-1){
            return -1;
        }
        
        //now think for general cases
        
        /*It's a concept of redundacy edges - Faltu ki edges ko bolte hai
        Redunancy edges can be calculated by a simple formula of
           Redunancy edges = E - [(n-1) -(c-1)]
                                  |___|  |___|
                                    |      |
                                   (a)    (b)
           (a) to connect n nodes we need n-1 edges
           (b) to connect c components we need c-1 edges
           where E = total edges, given in question
           n = number of nodes, given in question
           c = components , will find it by applying dfs
        */
        
        //make adjanceny list unordered_map of key value int with vector<int> as a pair 
        
        unordered_map< int,vector<int> > adj;
        int Edges =0;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            Edges++;
        }
        vector<bool> map(n,false);
        //calculate components by doing dfs on unordered_map from 0 till n-1 
         int component =0;   
        for(int i=0;i<n;i++){
            if(map[i]==false){
                component++;
                dfs(adj,i,map);
            }
        } 
        if(Edges<n-1){
            return -1;
        }
        int RedundancyEdges = Edges - ((n-1) -(component-1));
        
        if(RedundancyEdges>=component-1){
            return component-1;
        }
        return -1;
              
    }
};
/*
Runtime: 140 ms, faster than 96.59% of C++ online submissions for Number of Operations to Make Network Connected.
Memory Usage: 59.8 MB, less than 12.21% of C++ online submissions for Number of Operations to Make Network Connected.

Youtube Video for better understanding: https://www.youtube.com/watch?v=3JIwIRir2sM&ab_channel=TECHDOSE
*/