class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        for (int i = 0; i < n; i += k) {
            string group;
            for (int j = 0; j < k; ++j) {
                if (i + j < n) {
                    group += s[i + j];
                } else {
                    group += fill;
                }
            }
            result.push_back(group);
        }
        return result;
    }
};