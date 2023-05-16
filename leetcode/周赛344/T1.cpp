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
    int n;
    vector<int> distinctDifferenceArray(vector<int>& a) {
        n = sz(a);
        vector<int> res(n, 0);
        vector<int> l(n + 1, 0), r(n + 1, 0);
        map<int, int> mp;
        for(int i = 0, j = 0; i < n; i++) {
            if(!mp.count(a[i])) {
                mp[a[i]] = 1;
                j++;
            }
            l[i] = j;
        }
        mp.clear();
        for(int i = n - 1, j = 0; i >= 0; i--) {
            if(!mp.count(a[i])) {
                mp[a[i]] = 1;
                j++;
            }
            r[i] = j;
        }
        for(int i = 0; i < n; i++) res[i] = l[i] - r[i + 1];
        return res; 
    }
};