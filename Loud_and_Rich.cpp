class Solution {
public:
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> g(n);
        vector<int> indeg(n,0);
        for(auto i: richer){
            g[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto child: g[node]){
                indeg[child]--;
                if(quiet[node]<quiet[child]){
                    quiet[child]=quiet[node];
                    ans[child]=ans[node];
                }
                if(indeg[child]==0){
                    q.push(child);
                }
            }
        }
        return ans;
    }
};
