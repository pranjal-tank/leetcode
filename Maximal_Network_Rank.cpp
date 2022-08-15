class Solution {
public:
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_set<int> s[n];
        for(auto i: roads){
            s[i[0]].insert(i[1]);
            s[i[1]].insert(i[0]);
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({i,s[i].size()});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i].find(j)!=s[i].end()){
                    ans=max(ans,v[i].second+v[j].second-1);
                }
                else{
                    ans=max(ans,v[i].second+v[j].second);
                }
            }
        }
        return ans;
    }
};
