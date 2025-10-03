// 500. Keyboard Row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row[128] = {0};
        string r2 = "asdfghjklASDFGHJKL";
        string r3 = "zxcvbnmZXCVBNM";
        for (int i = 0, n = r2.size(); i < n; ++i) row[r2[i]] = 1;
        for (int i = 0, n = r3.size(); i < n; ++i) row[r3[i]] = 2;
        vector<string> res;
        for (int i = 0, n = words.size(); i < n; ++i) {
            int base = row[words[i][0]];
            bool ok = true;
            for (int j = 1, m = words[i].size(); j < m; ++j) {
                if (row[words[i][j]] != base) {
                    ok = false;
                    break;
                }
            }
            if (ok) res.push_back(words[i]);
        }
        return res;
    }
};