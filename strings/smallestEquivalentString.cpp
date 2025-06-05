class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x], parent);
        return parent[x];
    }

    void unionSet(int x, int y, vector<int>& parent) {
        int px = findParent(x, parent);
        int py = findParent(y, parent);
        if (px == py) return;
        // Always attach bigger to smaller to keep smallest lex char as parent
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        // Union all equivalent characters
        for (int i = 0; i < s1.size(); ++i) {
            unionSet(s1[i] - 'a', s2[i] - 'a', parent);
        }

        // Build result
        string result;
        for (char ch : baseStr) {
            int root = findParent(ch - 'a', parent);
            result += (char)(root + 'a');
        }

        return result;
    }
};
