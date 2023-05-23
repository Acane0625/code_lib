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
const int N = 1010;

int st[N], ok = 0;

class Solution {
public:
    int a[N], cnt = 0, flag = 0;

    void dfs(int u , int now, int sum, int target) {
        if(u == cnt) {
            if(sum == target) flag = 1;
            return;
        }
        dfs(u + 1, now * 10 + a[u + 1], sum - now + now * 10 + a[u + 1], target);
        dfs(u + 1, a[u + 1], sum + a[u + 1], target);
    }

    bool check(int x) {
        int t = x * x;
        cnt = 0;
        while(t) {
            a[++cnt] = t % 10;
            t /= 10;
        }
        reverse(a + 1, a + 1 + cnt);
        flag = 0;
        dfs(1, a[1], a[1], x);
        return flag;
    }

    void init() {//1 ... 1000
        for(int i = 1; i <= 1000; i++) {
            st[i] = check(i);
        }
        ok = 1;

    }

    int punishmentNumber(int n) {
        if(!ok) init();
        int ans = 0;
        for(int i = 1; i <= n; i++) if(st[i]) ans += i * i;
        return ans;
    }
};






















