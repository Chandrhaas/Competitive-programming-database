class Solution {
  public:
  
  int longest(string& s1, string& s2,int n,int m,vector<vector<int>>&dp,int& maxl)
  {
      if(n<0||m<0)
        return 0;
    else
    {
        if(dp[n][m]!=-1)return dp[n][m];
        
        longest(s1,s2,n-1,m,dp,maxl);
        longest(s1,s2,n,m-1,dp,maxl);
        
        if(s1[n]==s2[m]){
       dp[n][m]=1+longest(s1,s2,n-1,m-1,dp,maxl);
       maxl=max(maxl,dp[n][m]);
        }
        else
        {
        dp[n][m]=0;
    }
    return dp[n][m];
  }
  }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int maxl=0;
        longest(s1,s2,n-1,m-1,dp,maxl);
        return maxl;
    }
};