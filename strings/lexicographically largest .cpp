class Solution {
public:
  string answerString(string word, int numFriends) {
    // Find lexicographically largest substring of size n - numFriends + 1 or
    // less starting at every index. if no such substring exists, return empty
    // string.
    // Step 1: Handle base case where all friends can split the string
    int N = word.size();
    if (numFriends == 1) {
      return word;
    }

    // Step 2: Find the lexicographically largest character in the string
    char c = *max_element(word.begin(), word.end());
    string max_string = "";

    // Step 3: Iterate through the positions of the largest character
    for (int pos = 0; pos < N; pos++) {
      if (word[pos] == c) {
        // Step 4: Compute the maximum allowable substring length from this
        // position
        int l_allowed = min((int)(N - pos), N - numFriends + 1);

        // Skip if no valid substring can be formed
        if (l_allowed <= 0) {
          continue;
        }

        // Step 5: Extract the substring and compare with the current maximum
        string s = word.substr(pos, l_allowed);
        if (s > max_string) {
          max_string = s; // Update the maximum string
        }
      }
    }

    // Step 6: Return the result
    return max_string;
  }
};