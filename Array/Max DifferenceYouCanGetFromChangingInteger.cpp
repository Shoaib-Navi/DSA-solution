// 1432. Max Difference You Can Get From Changing an Integer


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        
        string s_max = s;
        for (char c : s) {
            if (c != '9') {
                char from = c;
                for (char& ch : s_max) {
                    if (ch == from) ch = '9';
                }
                break;
            }
        }
        
        
        string s_min = s;
        if (s[0] != '1') {
            char from = s[0];
            for (char& ch : s_min) {
                if (ch == from) ch = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char from = s[i];
                    for (char& ch : s_min) {
                        if (ch == from) ch = '0';
                    }
                    break;
                }
            }
        }
        
        int maxNum = stoi(s_max);
        int minNum = stoi(s_min);
        return maxNum - minNum;
    }
};


int main() {
    Solution solution;
    int num;
    cin >> num;
    cout << solution.minMaxDifference(num) << endl;
    return 0;
}