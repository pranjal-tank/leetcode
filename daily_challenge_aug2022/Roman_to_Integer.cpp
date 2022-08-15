class Solution {
public:
    int romanToInt(string s){
        int n=s.length();
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        if(n==1)
            return mp[s[0]];
        
        int i=0,j=1,ans=0;
        while(i<n){
            if(i<n && j<n){
              if(mp[s[i]] >= mp[s[j]]){
                  ans+=mp[s[i]];
                  i++;
                  j++;
              }
              else{
                  ans+=(mp[s[j]]-mp[s[i]]);
                  i+=2;
                  j+=2;
              }
            }
            else{
                ans+=mp[s[i]];
                i++;
            }
        }
        return ans;
    }
};
