// 2200. Find All K-Distant Indices in an Array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        
        unordered_set<int> resultSet;
        for (int j : keyIndices) {
            int start = max(0, j - k);
            int end = min((int)nums.size() - 1, j + k);
            for (int i = start; i <= end; ++i) {
                resultSet.insert(i);
            }
        }
        
        vector<int> result(resultSet.begin(), resultSet.end());
        sort(result.begin(), result.end());
        return result;
    }
};