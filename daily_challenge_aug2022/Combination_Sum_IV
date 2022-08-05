class Solution {
public:
    
    int solve(int target,int n,vector<int> &nums,vector<int> &dp){
        if(target==0)
            return 1;
        
        int ans=0;
        if(dp[target]!=-1) return dp[target];
        for(int i=0;i<n;i++){
            if(target-nums[i]>=0){
                ans+=solve(target-nums[i],n,nums,dp);
            }
        }
        dp[target]=ans;
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target){
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return solve(target,n,nums,dp);
    }
};
