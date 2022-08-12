class Solution {
public:
    
    void bfs(int src,int dest,int n,vector<vector<double>> &g,vector<bool> &vis,vector<double> &ans){
        queue<int> q;
        vector<double> prod(n);
        q.push(src);
        prod[src]=1.00000;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=true;
            if(node==dest){
                ans.push_back(prod[node]);
                return;
            }
            for(int i=0;i<n;i++){
                if(g[node][i]!=0 && !vis[i]){
                    q.push(i);
                    prod[i]=prod[node]*g[node][i];
                }
            }
        }
        ans.push_back(-1.00000);
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        vector<double> ans;
        unordered_map<string,int> mp;
        int it=0;
        for(auto i: equations){
            if(mp.find(i[0])==mp.end()){
                mp[i[0]]=it;
                it++;
            }
            if(mp.find(i[1])==mp.end()){
                mp[i[1]]=it;
                it++;
            }
        }
        int n=mp.size();
        vector<vector<double>> g(n,vector<double>(n,0));
        it=0;
        for(auto i: equations){
            g[mp[i[0]]][mp[i[1]]]=values[it];
            g[mp[i[1]]][mp[i[0]]]=(1/values[it]);
            it++;
        }
        for(int i=0;i<queries.size();i++){
            vector<bool> vis(n,false);
            bool check=false;
            if(mp.find(queries[i][0])!=mp.end() && mp.find(queries[i][1])!=mp.end()){
                bfs(mp[queries[i][0]],mp[queries[i][1]],n,g,vis,ans);
            }
            else{
                ans.push_back(-1.00000);
            }
        }
        return ans;
    }
};
