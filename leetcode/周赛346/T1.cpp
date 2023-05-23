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
    int minLength(string s) {
        while(1) {
            int ok = 0;
            for(int i = 0; i < sz(s) - 1; i++) {
                if(s.substr(i, 2) == "AB") {
                    //i i+1
                    ok = 1;
                    string pre = s.substr(0, i);
                    string suf = s.substr(i + 2, sz(s) - i - 2);
                    s = pre + suf;
                    break;
                }
                if(s.substr(i, 2) == "CD") {
                    //i i+1
                    ok = 1;
                    string pre = s.substr(0, i);
                    string suf = s.substr(i + 2, sz(s) - i - 2);
                    s = pre + suf;
                    break;
                }
            }
            if(!ok) break;
        }   
        return sz(s);
    }
};
