class Solution {
public:
    
    int solve(int i,int j,char v[],vector<vector<int>> &dp){
      
        if(i<0)
            return 1;
        if(j==5)
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        dp[i][j]=solve(i-1,j,v,dp) + solve(i,j+1,v,dp);
        return dp[i][j];
    }
    
    int countVowelStrings(int n){
        char v[5]={'a','e','i','o','u'};
        vector<vector<int>> dp(n,vector<int>(5,-1));
        return solve(n-1,0,v,dp);
    }
};
