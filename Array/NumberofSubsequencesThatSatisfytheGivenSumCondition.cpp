class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        int left = 0, right = n - 1;
        int res = 0;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                int count = right - left;
                res = (res + pow2[count]) % MOD;
                left++;
            }
        }
        return res;
    }
};