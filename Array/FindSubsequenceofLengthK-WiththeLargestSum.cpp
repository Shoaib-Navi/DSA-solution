class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> elementsWithIndices;
        for (int i = 0; i < nums.size(); ++i) {
            elementsWithIndices.emplace_back(i, nums[i]);
        }
        
        sort(elementsWithIndices.begin(), elementsWithIndices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        vector<pair<int, int>> topK(elementsWithIndices.begin(), elementsWithIndices.begin() + k);
        
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        vector<int> result;
        for (const auto& element : topK) {
            result.push_back(element.second);
        }
        
        return result;
    }
};
