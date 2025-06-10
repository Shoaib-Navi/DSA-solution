// 3442. Maximum Difference Between Even and Odd Frequency I

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

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


int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    int result = sol.maxDifference(s);

    cout << "Maximum Difference: " << result << endl;

    return 0;
}