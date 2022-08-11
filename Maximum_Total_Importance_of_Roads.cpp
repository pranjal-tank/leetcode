class Solution {
public:
    
    static bool sortbysec(pair<int,int> &a,pair<int,int> &b){
       return (a.second > b.second);    
    }
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n);
        vector<pair<int,int>> count_child;
        for(auto i: roads){
           g[i[0]].push_back(i[1]);
           g[i[1]].push_back(i[0]); 
        }
        for(int i=0;i<n;i++){
            count_child.push_back({i,g[i].size()});
        }
        sort(count_child.begin(),count_child.end(),sortbysec);
        vector<int> value(n);
        int val=n;
        for(auto i: count_child){
            value[i.first]=val;
            val--;
        }
        long long ans=0;
        for(auto i: roads){
            ans+=value[i[0]]+value[i[1]];
        }
        return ans;
    }
};
