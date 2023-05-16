const int N = 60;

class Solution {
public:
    int st[N];
    vector<int> g[N];
    vector<int> b;
    /*
    0: 1,2
    1: 0,2, 
    2: 0,1,
    3:
    4:
    5:
    */
    void dfs(int u) {
        st[u] = 1;
        b.push_back(u);
        for(auto v : g[u]) {
            if(!st[v]) dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
            g[i].clear();
            st[i] = 0;
        }
        for(auto &p : edges) {
            int u = p[0], v = p[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        //st[i]
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!st[i]) {
                b.clear();
                dfs(i);
                int m = b.size();
                map<int, int> mp;
                map<pair<int, int>, int> e; 
                for(auto c : b) mp[c] = 1;
                // m * (m - 1) / 2
                int cnt = 0;
                for(auto &p : edges) {
                    int u = p[0], v = p[1];
                    if((mp[u] || mp[v]) && e[make_pair(u,v)] == 0){
                        e[make_pair(v, u)] = e[make_pair(u, v)] = 1;
                        cnt++;
                    }
                }
                if(cnt == m * (m - 1) / 2) ans++;
            }
        }
        return ans;
    }
};