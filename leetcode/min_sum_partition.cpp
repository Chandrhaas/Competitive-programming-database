class Solution {
  public:
  
  int subset(vector<int>&arr,int n,int sum,int t,vector<vector<int>>&dp)
  {
      if(n<0) 
      return t;
      else if (t+arr[n]>sum)
      return dp[n][t]=subset(arr,n-1,sum,t,dp);
      else if (dp[n][t]!=-1)
      return dp[n][t];
      else
      return dp[n][t]=max(subset(arr,n-1,sum,t+arr[n],dp),subset(arr,n-1,sum,t,dp));
  }
    int minDifference(vector<int>& arr) {
        // code here
        int n=arr.size();
        int s=0;
        for(int i=0;i<=n-1;i++)
        s+=arr[i];
        vector<vector<int>>dp(n+1,vector<int>(s/2 +1,-1));
        return(s-2*subset(arr,n-1,s/2,0,dp));
    }
};
