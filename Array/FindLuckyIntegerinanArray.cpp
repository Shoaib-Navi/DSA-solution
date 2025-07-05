// 1394. Find Lucky Integer in an Array


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        
        for (int num : arr) {
            frequencyMap[num]++;
        }
        
        int maxLucky = -1;
        
        for (const auto& pair : frequencyMap) {
            if (pair.first == pair.second) {
                if (pair.first > maxLucky) {
                    maxLucky = pair.first;
                }
            }
        }
        
        return maxLucky;
    }
};