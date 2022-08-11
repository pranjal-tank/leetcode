class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<vector<int>> g(n);
        vector<vector<int>> rg(n);
        
        for(auto i: connections){
            g[i[0]].push_back(i[1]);
            rg[i[1]].push_back(i[0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=true;
            for(auto i: rg[node]){
                if(!vis[i])
                    q.push(i);
            }
            
            for(auto i: g[node]){
                if(!vis[i]){
                    q.push(i);
                    ans++;
                }
            }
        }
        return ans;
    }
};
