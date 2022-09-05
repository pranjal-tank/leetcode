class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &g,vector<bool> &vis,unordered_set<int> &s){
       vis[node]=true;
       for(auto child: g[node]){
           if(!vis[child] && s.find(child)==s.end())
               dfs(child,g,vis,s);
       }
       return;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> s;
        for(auto i: restricted){
            s.insert(i);   
        }
        vector<vector<int>> g(n);
        for(auto i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        dfs(0,g,vis,s);
        int ans=0;
        for(auto i: vis){
            if(i==true)
                ans++;
        }
        return ans;
    }
};
