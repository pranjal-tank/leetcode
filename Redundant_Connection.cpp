class Solution {
public:
    
    void dfs(int node,int par,vector<vector<int>> &g,vector<bool> &vis,unordered_set<int> &ce,pair<bool,int> &cd){
             vis[node]=true;
        for(auto child: g[node]){
            
            if(cd.first && ce.find(cd.second)==ce.end()){
                ce.insert(node);
                return;
            }
            
            if(!vis[child])
                dfs(child,node,g,vis,ce,cd);
            else if(child!=par){
                cd.first=true;
                cd.second=child;
                ce.insert(node);
                return;
            }
        }
        if(cd.first && ce.find(cd.second)==ce.end()){
                ce.insert(node);
                return;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans(2);
        vector<bool> vis(n+1,false);
        vector<vector<int>> g(n+1);
        for(auto i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        unordered_set<int> cycle_ele;
        pair<bool,int> cycle_det={false,0};
        dfs(1,-1,g,vis,cycle_ele,cycle_det);
        for(auto i: edges){
            if(cycle_ele.find(i[0])!=cycle_ele.end() && cycle_ele.find(i[1])!=cycle_ele.end()){
                ans[0]=i[0];
                ans[1]=i[1];
            }
        }
        return ans;
    }
};
