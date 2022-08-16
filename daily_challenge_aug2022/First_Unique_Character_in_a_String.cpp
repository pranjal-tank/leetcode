class Solution {
public:
    int firstUniqChar(string s) {
        int ans=INT_MAX;
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto i: mp){
           if(i.second==1){
               for(int j=0;j<n;j++){
                   if(s[j]==i.first){
                       ans=min(ans,j);
                   }
               }
           }
        }
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};
