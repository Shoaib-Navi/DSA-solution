class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int length = 1;
        
        while (count < n) {
            vector<long long> palindromes = generatePalindromes(length);
            for (long long num : palindromes) {
                if (isPalindromeInBase(num, k)) {
                    sum += num;
                    count++;
                    if (count == n) {
                        break;
                    }
                }
            }
            length++;
        }
        
        return sum;
    }
    
private:
    vector<long long> generatePalindromes(int length) {
        vector<long long> palindromes;
        if (length == 1) {
            for (long long i = 1; i <= 9; ++i) {
                palindromes.push_back(i);
            }
            return palindromes;
        }
        
        int halfLength = (length + 1) / 2;
        long long start = pow(10, halfLength - 1);
        long long end = pow(10, halfLength);
        
        for (long long i = start; i < end; ++i) {
            string s = to_string(i);
            string palindromeStr;
            if (length % 2 == 0) {
                palindromeStr = s + string(s.rbegin(), s.rend());
            } else {
                palindromeStr = s + string(s.rbegin() + 1, s.rend());
            }
            palindromes.push_back(stoll(palindromeStr));
        }
        
        return palindromes;
    }
    
    bool isPalindromeInBase(long long num, int base) {
        string s;
        if (num == 0) {
            return true;
        }
        
        long long n = num;
        while (n > 0) {
            s.push_back(n % base + '0');
            n /= base;
        }
        
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        return s == reversed_s;
    }
};