class Solution {
public:
    
    void dfs(int node,int n,vector<vector<int>> &g,vector<bool> &vis){
        if(vis[node]) return;  
        vis[node]=true;
        for(int i=0;i<n;i++){
            if(g[node][i]==1)
                dfs(i,n,g,vis);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,n,isConnected,vis);
            }
        }
        return ans;
    }
};
