// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for (int i = 0; i < n; ++i) {
          
            int next = (i + 1) % n;
            int diff = abs(nums[i] - nums[next]);
            
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxAdjacentDistance(nums);

    cout << "Maximum difference between adjacent elements (circular): " << result << endl;

    return 0;
}