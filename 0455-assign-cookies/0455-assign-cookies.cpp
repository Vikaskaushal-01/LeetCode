class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child_i = 0;
        int cookie_j = 0;
        while (child_i < g.size() && cookie_j < s.size()) {
            if (s[cookie_j] >= g[child_i]) {
                child_i++; 
            }
            cookie_j++;
        }
        return child_i; 
    }
};