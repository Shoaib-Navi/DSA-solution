class Solution {
public:
    int findKthNumber(int n, int k) {
        long long current = 1;
        k--;
        while (k > 0) {
            int steps = calculateSteps(n, current, current + 1);
            if (steps <= k) {
                current += 1;
                k -= steps;
            } else {
                current *= 10;
                k -= 1;
            }
        }
        return current;
    }
    
private:
    int calculateSteps(int n, long long n1, long long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};


int main() {
    Solution sol;
    int n = 13;
    int k = 2;
    std::cout << "The " << k << "-th smallest number in lexicographical order up to " << n << " is: " << sol.findKthNumber(n, k) << std::endl;
    return 0;
}