class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;

        for(int i=0;i< (1<<n); i++)
        {
            vector<int>a;
            int b=i;
            int c=0;
            while(b!=0)
            {
                int t = b&1;
                if(t==1)
                {
                    a.push_back(nums[c]);
                }
                c++;
                b=b>>1;
            }
            ans.push_back(a);
        }
        return ans;
    }
};