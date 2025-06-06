#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            min_suffix[i] = min(s[i], min_suffix[i + 1]);

        stack<char> t;
        string p;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);
            while (!t.empty() && (i == n - 1 || t.top() <= min_suffix[i + 1])) {
                p.push_back(t.top());
                t.pop();
            }
        }

        return p;
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter the string: ";
    cin >> input;
    string result = sol.robotWithString(input);
    cout << "Lexicographically smallest string: " << result << endl;
    return 0;
}