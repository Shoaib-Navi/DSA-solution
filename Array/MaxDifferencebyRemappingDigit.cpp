// Maximum Difference by Remapping a Digit

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s, minStr = s;

        
        for (char d : s) {
            if (d != '9') {
                char from = d;
                for (char &c : maxStr)
                    if (c == from) c = '9';
                break;
            }
        }


        for (char d : s) {
            if (d != '0') {
                char from = d;
                for (char &c : minStr)
                    if (c == from) c = '0';
                break;
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};
