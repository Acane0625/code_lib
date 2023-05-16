class Solution {
public:
    bool doesValidArrayExist(vector<int>& b) {
       int n = b.size(); 
       vector<int> a(n, 0);
       a[0] = 0;
       //b[i] = a[i]^a[i+1]
       //a[i+1] = b[i] ^ a[i]
       for(int i = 1; i < n; i++) {
           a[i] = b[i - 1] ^ a[i - 1];
       }
        //b[n - 1] a[n - 1] ^ a[0]
        if(b[n - 1] == a[n - 1] ^ a[0]) return true;
        a[0] = 1;
       //b[i] = a[i]^a[i+1]
       //a[i+1] = b[i] ^ a[i]
       for(int i = 1; i < n; i++) {
           a[i] = b[i - 1] ^ a[i - 1];
       }
        //b[n - 1] a[n - 1] ^ a[0]
        if(b[n - 1] == a[n - 1] ^ a[0]) return true;
        return false;
    }
};