// User function Template for C++

class Solution {
  public:
  int rod(vector<int>&price,int len,int n , vector<vector<int>>&dp)
  {
      if(n<0 || len==0)
      return 0;
      else if (dp[n][len]!=-1) 
      return dp[n][len];
      int skip=rod(price,len,n-1,dp);
      if(len - n - 1 < 0)
      return dp[n][len]=skip;
      else
      return dp[n][len]= max(skip,price[n]+rod(price,len-n-1,n,dp));
  }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return rod(price,n,n-1,dp);
    }
};