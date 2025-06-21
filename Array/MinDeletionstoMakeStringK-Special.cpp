class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) freq[c]++;
        
        vector<int> counts;
        for (auto& p : freq) counts.push_back(p.second);
        
        sort(counts.begin(), counts.end());
        int n = counts.size();
        int res = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int x = counts[i], del = 0;
            for (int j = 0; j < n; ++j) {
                if (counts[j] < x) del += counts[j];
                else if (counts[j] > x + k) del += counts[j] - (x + k);
            }
            res = min(res, del);
        }
        return res;
    }
};
