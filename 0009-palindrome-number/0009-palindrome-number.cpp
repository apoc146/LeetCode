class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        string s_cpy=s;
        reverse(s_cpy.begin(),s_cpy.end());
        return (s_cpy==s);
        
    }
};