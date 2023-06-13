class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int l = -1, r = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') continue;
            l = i;
            break;
        }
        if(l == -1) {
            s[n - 1] = 'z';
            return s;
        }
        for(int i = l; i < n; i++) {
            if(s[i] == 'a') break;
            r = i;
        }
        //[l,r]
        for(int i = l; i <= r; i++) {
            s[i] = s[i] - 1;
        }
        return s;
    }
};
//aaa
//aaz
