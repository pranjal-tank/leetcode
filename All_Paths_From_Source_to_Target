class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &graph,int n,vector<int> &path,vector<vector<int>> &ans){
        path.push_back(node);
        if(node==n-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto child: graph[node]){
            dfs(child,graph,n,path,ans);
        }
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0,graph,n,path,ans);
        return ans;
    }
};
