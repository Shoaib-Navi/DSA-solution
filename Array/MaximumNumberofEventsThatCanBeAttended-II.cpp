// 1751. Maximum Number of Events That Can Be Attended II


class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        int n = events.size();
        vector<int> startTimes(n);
        for (int i = 0; i < n; i++) {
            startTimes[i] = events[i][0];
        }
        
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, events, startTimes, dp);
    }
    
private:
    int solve(int i, int remaining, const vector<vector<int>>& events, 
              const vector<int>& startTimes, vector<vector<int>>& dp) {
        if (i >= events.size() || remaining == 0) return 0;
        if (dp[i][remaining] != -1) return dp[i][remaining];
        
       
        int nextIndex = lower_bound(startTimes.begin(), startTimes.end(), events[i][1] + 1) - startTimes.begin();
        
        
        int take = events[i][2] + solve(nextIndex, remaining - 1, events, startTimes, dp);
        
        
        int skip = solve(i + 1, remaining, events, startTimes, dp);
        
        dp[i][remaining] = max(take, skip);
        return dp[i][remaining];
    }
};
