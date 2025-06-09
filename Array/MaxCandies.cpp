#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> opened(n, false);
        queue<int> q;
        int total = 0;
        
      
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                opened[box] = true;
            }
        }
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            
            total += candies[current];
            
           
            for (int key : keys[current]) {
                hasKey[key] = true;
               
                if (hasBox[key] && !opened[key]) {
                    q.push(key);
                    opened[key] = true;
                }
            }
            
          
            for (int box : containedBoxes[current]) {
                hasBox[box] = true;
              
                if ((status[box] == 1 || hasKey[box]) && !opened[box]) {
                    q.push(box);
                    opened[box] = true;
                }
            }
        }
        
        return total;
    }
};

int main() {
    Solution sol;
    
    // Sample input 1
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};
    
    int result = sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies collected: " << result << endl;
    
    // Sample input 2
    status = {1, 0, 0, 0, 0, 0};
    candies = {1, 1, 1, 1, 1, 1};
    keys = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    containedBoxes = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    initialBoxes = {0};
    
    result = sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies collected: " << result << endl;
    
    return 0;
}