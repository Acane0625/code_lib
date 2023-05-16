const int N = 1e5 + 10;
class Solution {
public:
    int c[N];
    int minIncrements(int n, vector<int>& cost) {
        for(int i = 1; i <= n; i++) c[i] = cost[i - 1];
        //i 2*i 2*i+1
        int ans = 0;
        for(int i = n; i > 1; i -= 2) {
            //p 2*p 2*p+1
            //c[i-1] c[i]
            ans += abs(c[i] - c[i - 1]);
            c[(i - 1) / 2] += max(c[i], c[i - 1]);
        }
        return ans;
    }
};