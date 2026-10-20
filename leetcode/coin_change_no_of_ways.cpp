class Solution {
  public:
  
  int coin(vector<int>&coins,int sum, int n , vector<vector<int>>&dp)
  {
      if(n<0 || sum<0)
      return 0;
      else if (sum==0)
      return 1;
      else if(dp[n][sum]!=-1) return dp[n][sum];
      else 
      return dp[n][sum]=coin(coins,sum,n-1,dp)+coin(coins,sum-coins[n],n,dp);
  }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return coin(coins,sum,n-1,dp);
    }
};