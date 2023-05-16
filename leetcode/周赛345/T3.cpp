class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) f[i][0] = 1;
        int ans = 0;
        for(int j = 1; j < m; j++) {
            int ok = false;
            for(int i = 0; i < n; i++) {
                if(f[i][j-1]) {
                    if(g[i][j-1] < g[i][j]) {f[i][j] = 1;ok = true;}
                }
                if(i-1 >= 0 && f[i-1][j-1]) {
                    if(g[i-1][j-1] < g[i][j]) {f[i][j] = 1;ok = true;}
                }
                if(i+1 < n && f[i+1][j-1]) {
                    if(g[i+1][j-1] < g[i][j]) {f[i][j] = 1;ok = true;}
                }
            }
            if(ok) ans = j;
            else break;
        }

        return ans;
    }
};