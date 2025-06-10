// 3442. Maximum Difference Between Even and Odd Frequency I

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<int> oddFreq;
        vector<int> evenFreq;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 1) {
                oddFreq.push_back(count);
            } else {
                evenFreq.push_back(count);
            }
        }

        int maxOdd = *max_element(oddFreq.begin(), oddFreq.end());
        int minEven = *min_element(evenFreq.begin(), evenFreq.end());

        return maxOdd - minEven;
    }
};