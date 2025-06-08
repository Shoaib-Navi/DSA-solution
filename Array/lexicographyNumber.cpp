// 386. Lexicographical Numbers

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current >= n) {
                    current /= 10;
                }
                current += 1;
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }
        return result;
    }
};


int main() {
    Solution solution;
    int n = 13;
    vector<int> result = solution.lexicalOrder(n);
    
    cout << "Lexicographical order of numbers from 1 to " << n << ":" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}