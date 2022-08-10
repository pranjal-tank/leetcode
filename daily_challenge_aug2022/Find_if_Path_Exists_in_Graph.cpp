class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &g,vector<bool> &vis){
        vis[node]=true;
        for(auto child: g[node]){
            if(!vis[child])
                dfs(child,g,vis);
        }
        return;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(auto i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        dfs(source,g,vis);
        if(vis[destination])
            return true;
        
        return false;
     }
};
