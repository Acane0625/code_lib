class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        //0...n-1
        vector<int> st(n, 0);
        int u = 0, d = k;
        while(1) {
            if(st[u]) break;
            st[u] = 1;
            u = (u + d) % n;
            d += k;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(!st[i]) res.push_back(i + 1);
        }
        return res;
    }
};