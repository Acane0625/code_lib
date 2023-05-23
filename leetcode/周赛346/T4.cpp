#include<bits/stdc++.h>
#define fi first
#define se second
#define bit(x) (1 << (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#define lson 2 * p,l,(l + r) / 2
#define rson 2 * p + 1,(l + r) / 2 + 1,r
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef double LD;
const int N = 110, INF = 2e9;
class Solution {
public:
    vector<PII> G[N];
    int st[N], d[N], n, m;

    void dij(int s) {
        for(int i = 0; i < n; i++) {
            st[i] = 0;
            d[i] = INF;
        }
        priority_queue<PII, vector<PII>, greater<PII> > Q;
        d[s] = 0;
        Q.push({d[s], s});
        while(sz(Q)) {
            auto t = Q.top(); Q.pop();
            int u = t.se, dd = t.fi;
            if(st[u]) continue;
            st[u] = 1;
            for(auto e : G[u]) {
                int v = e.fi, w = e.se;
                if(d[v] > dd + w) {
                    d[v] = dd + w;
                    Q.push({d[v], v});
                }
            }

        }
    }

    vector<vector<int>> modifiedGraphEdges(int nn, vector<vector<int>>& edges, int source, int destination, int target) {
        n = nn, m = sz(edges);
        for(int i = 0; i < m; i++) {
            auto &p = edges[i];
            int u = p[0], v = p[1], w = p[2];
            if(w == -1) continue;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dij(source);
        if(d[destination] < target) return vector<vector<int>> ();
        vector<vector<int>> res = edges;
        bool ok = false;
        for(int i = 0; i < m; i++) {
            auto &p = res[i];
            if(p[2] == -1) {
                if(!ok) {
                    p[2] = 1;
                    G[p[0]].push_back({p[1], 1});
                    G[p[1]].push_back({p[0], 1});
                    dij(source);
                    if(d[destination] <= target) {
                        p[2] += target - d[destination];
                        ok = true;
                    }
                    G[p[0]].back() = {p[1], p[2]};
                    G[p[1]].back() = {p[0], p[2]};
                } else {
                    p[2] = INF;
                }
            }
        }
        dij(source);
        if(d[destination] != target) return vector<vector<int>> ();
        return res;
    }
};









