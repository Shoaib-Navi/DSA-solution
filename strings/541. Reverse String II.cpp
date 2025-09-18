// 541. Reverse String II

class Solution {
public:
    string reverseStr(string s, int k) {
        int index = 0, n = s.size();
        string temp = s;

        while(index < n) {
            if (n - index < k) {
                reverse(temp.begin() + index, temp.end());
                break;
            }
            reverse(temp.begin() + index, temp.begin() + index + k);
            index += (2 * k);
        }
        return temp;
    }
};