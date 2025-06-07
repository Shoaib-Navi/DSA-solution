//3170. Lexicographically Minimum String After Removing Stars

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        vector<bool> removed(s.size(), false);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                pq.push({s[i], -i});
            } else {
                if (!pq.empty()) {
                    auto [c, neg_idx] = pq.top();
                    pq.pop();
                    int idx = -neg_idx;
                    removed[idx] = true;
                    removed[i] = true;
                }
            }
        }
        
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!removed[i] && s[i] != '*') {
                result += s[i];
            }
        }
        
        return result;
    }
};