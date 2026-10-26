class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long ans =0;
        for (int i = 0; i < 32; i++) {
        int c = 0;

        for (int x : nums) {
            if ((x >> i) & 1)
                c++;
        }

        if (c % 3)
            ans |= (1LL << i);
    }
    return ans;
    }
};