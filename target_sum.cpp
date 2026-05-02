class Solution {
public:
    int subset(vector<int>& nums, int target, int n, int curr,
               vector<vector<int>>& dp) {
        if (curr>target) 
            return 0;
        if (n < 0)
            {if (curr == target)
                return 1;
            else return 0;
            }
        else if (dp[n][curr] != -1)
                return dp[n][curr];
        else
        return dp[n][curr]=(subset(nums, target, n - 1, curr + nums[n], dp) + subset(nums, target, n - 1, curr, dp));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i <= n - 1; i++)
            s += nums[i];
        if(abs(target)>s || (target+s)%2!=0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>((target+s)/2 + 1, -1));
        return subset(nums, (target+s)/2, n - 1, 0, dp);
    }
};