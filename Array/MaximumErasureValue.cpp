// 1695. Maximum Erasure Value


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, currSum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                ++left;
            }
            seen.insert(nums[right]);
            currSum += nums[right];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
