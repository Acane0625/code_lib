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
const LD PI = 3.14159265358979323846;
const LD eps = 1e-10;
const int N = 2e5 + 10;
class Solution {
public:
    int n, b[N], lb, c[N];
    void add(int i, int x) {
        while(i <= lb) {
            c[i] = max(c[i], x);
            i += i & -i;
        }
    }
    int query(int i) {
        int res = -1;
        while(i > 0) {
            res = max(res, c[i]);
            i -= i & -i;
        }
        return res;
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int m = sz(queries);
        vector<int> q(m);
        for(int i = 0; i < m; i++) q[i] = i;
        sort(all(q), [&] (int a, int b) {
            return queries[a][0] > queries[b][0];
        });
        lb = 0, n = sz(nums1);
        vector<array<int, 3>> p;
        for(int i = 0; i < n; i++) {
            p.push_back({nums1[i], -nums2[i], nums1[i] + nums2[i]});
            b[++lb] = -nums2[i];
        }
        for(int i = 0; i < sz(queries); i++) b[++lb] = -queries[i][1];
        sort(b + 1, b + 1 + lb);
        lb = unique(b + 1, b + 1 + lb) - b - 1;
        for(int i = 0; i <= lb; i++) c[i] = -1;
        sort(all(p), [&] (array<int, 3> &a, array<int, 3> &b) {
            return a[0] > b[0];
        });
        int l = 0;
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int qx = queries[q[i]][0], qy = queries[q[i]][1];
            qy = lower_bound(b + 1, b + 1 + lb, -qy) - b;
            while(l < sz(p) && p[l][0] >= qx) {
                int pp = lower_bound(b + 1, b + 1 + lb, p[l][1]) - b;
                add(pp, p[l][2]);
                l++;
            }
            ans[q[i]] = query(qy);
        }
        return ans;
    }
};