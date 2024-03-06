class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0;
        int h = n - 1;
        
        while (l < h && s[l] == s[h]) {
            char curr = s[l];
            while (l <= h && s[l] == curr) {
                l++;
            }
            while (l <= h && s[h] == curr) {
                h--;
            }
        }
        
        return max(0, h - l + 1);
    }
};