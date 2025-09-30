// 28. Find the Index of the First Occurrence in a String

class Solution {
public:
     int strStr(string haystack, string needle) {
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};