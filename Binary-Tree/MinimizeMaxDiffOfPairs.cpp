// 2616. Minimize the Maximum Difference of Pairs

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
        int count = 0, i = 0;
        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), answer = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(nums, mid, p)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;
    cout << sol.minimizeMax(nums, p) << endl;
    return 0;
}
