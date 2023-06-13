class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx = 0, mi = 101;
        for(auto c : nums) {
            mx = max(mx, c);
            mi = min(mi, c);
        }
        for(auto c : nums) {
            if(c == mi || c == mx) continue;
            return c;
        }
        return -1;
    }
};