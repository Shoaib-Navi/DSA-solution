// 2040. Kth Smallest Product of Two Sorted Arrays


class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        long long answer = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countLessOrEqual(nums1, nums2, mid) >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
    
private:
    long long countLessOrEqual(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num : nums1) {
            if (num == 0) {
                if (target >= 0) {
                    count += nums2.size();
                }
            } else if (num > 0) {
                long long max_val = floor((double)target / num);
                auto it = upper_bound(nums2.begin(), nums2.end(), max_val);
                count += it - nums2.begin();
            } else {
                long long min_val = ceil((double)target / num);
                auto it = lower_bound(nums2.begin(), nums2.end(), min_val);
                count += nums2.end() - it;
            }
        }
        return count;
    }
};