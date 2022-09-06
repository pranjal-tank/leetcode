class Solution {
public:
    
    void dijkstra(int src,vector<vector<pair<int,int>>> &g,vector<int> &ans){
        ans[src] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, src});
        while (!q.empty()){
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v <= ans[v]){
                for (auto edge : g[v]) {
                    int to = edge.first;
                    int len = edge.second;

                    if (ans[v] + len < ans[to]){
                        ans[to] = ans[v] + len;
                        q.push({ans[to], to});
                    }
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pair<int,int>>> g(n);
        for(auto i: edges){
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
             dijkstra(i,g,dist[i]);
        }
        int ans;
        int prev_count=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=dt){
                    count++;
                }
            }
            if(count<=prev_count){
                prev_count=count;
                ans=i;
            }
        }
        return ans;
    }
};
