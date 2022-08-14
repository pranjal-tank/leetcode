class Solution {
public:
    
    void dfs(int node,int par,vector<vector<int>> &g,vector<bool> &vis,vector<int> &col,int *cycle){
        col[node]=0;
        vis[node]=true;    
        for(auto child: g[node]){
            if(vis[child] && child!=par && col[child]!=1)
                *cycle=*cycle+1;
            if(!vis[child])
                dfs(child,node,g,vis,col,cycle);
        }
        col[node]=1;
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int comp=0;
        vector<vector<int>> g(n);
        for(auto i: connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            cout<<i<<": ";
            for(auto j: g[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int cycle=0;
        vector<bool> vis(n,false);
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i,-1,g,vis,col,&cycle);
            }
        }
        cout<<cycle<<endl;
        if(cycle>=comp-1)
            return comp-1;
        else
            return -1;
    }
};
