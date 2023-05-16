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
template <typename T> bool chkmax(T &x,T y){return x < y ? x = y,true : false;}
template <typename T> bool chkmin(T &x,T y){return x > y ? x = y,true : false;}
const LD PI = 3.14159265358979323846;
const LD eps = 1e-10;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> a(n, 0);
        int m = sz(queries);
        vector<int> res(m);
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int idx = queries[i][0], c = queries[i][1];
            if(!a[idx]) {
                a[idx] = c;
                if(idx < n - 1 && a[idx] == a[idx + 1]) cnt++;
                if(idx > 0 && a[idx] == a[idx - 1]) cnt++;
            }
            else {
                if(idx < n - 1 && a[idx] == a[idx + 1]) cnt--;
                if(idx > 0 && a[idx] == a[idx - 1]) cnt--;
                a[idx] = c;
                if(idx < n - 1 && a[idx] == a[idx + 1]) cnt++;
                if(idx > 0 && a[idx] == a[idx - 1]) cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};