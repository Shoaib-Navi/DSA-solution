// 966. Divide Array Into Arrays With Max Difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size()) return {};
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            if (c - a > k) return {};
            res.push_back({a, b, c});
        }

        return res;
    }
};



int main() {
    vector<int> nums;
    int n, k;

    cout << "Enter the number of elements (multiple of 3): ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    vector<vector<int>> result = sol.divideArray(nums, k);

    if (result.empty()) {
        cout << "[]\n";
    } else {
        cout << "Result:\n";
        for (const auto& group : result) {
            cout << "[";
            for (int i = 0; i < group.size(); ++i) {
                cout << group[i];
                if (i < group.size() - 1) cout << ", ";
            }
            cout << "]\n";
        }
    }

    return 0;
}