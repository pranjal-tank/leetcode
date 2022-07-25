class Solution {
public:
    
    int solve(int i,vector<int> &dp){
      if(i==0 || i==1)
          return i;
      if(dp[i]!=-1) return dp[i];
      dp[i]=solve(i-1,dp) + solve(i-2,dp);
      return dp[i];
    }
    
    int fib(int n) {
        if(n==0 || n==1) return n;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
