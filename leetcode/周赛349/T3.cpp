typedef long long LL;
//int 32 [2^31-1,-2^31]  2000000000
//long long 64 [2^63-1,-2^63] 8 10^18
class Solution {
public:
    long long minCost(vector<int>& a, int x) {
        LL ans = 0;
        int n = a.size();
        for(auto c : a) ans += c;
        vector<int> b = a;
        /*
        
        */
        for(int d = 1; d < n; d++) {
            LL sum = 1LL * x * d;
            //a[i] <- a[(i+d) % n]
            for(int i = 0; i < n; i++) {
                b[i] = min(b[i], a[(i + d) % n]);
                sum += b[i];
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};