class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        for (int x : nums)
            xr ^= x;

        int bit = xr & (-xr);

        int a = 0, b = 0;

        for (int x : nums) {
            if (x & bit)
                a ^= x;
            else
                b ^= x;
        }

        return {a, b};
    }
};