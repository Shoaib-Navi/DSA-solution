// 2294. Partition Array Such That Maximum Difference Is K

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;  
        int minElement = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - minElement > k) {
                count++;
                minElement = nums[i];  
            }
        }

        return count;
    }
};
