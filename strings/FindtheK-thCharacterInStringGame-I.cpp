// 3304. Find the K-th Character in String Game I


class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string next;
            for (char c : word) {
                if (c == 'z') {
                    next += 'a';
                } else {
                    next += c + 1;
                }
            }
            word += next;
        }
        return word[k - 1];
    }
};