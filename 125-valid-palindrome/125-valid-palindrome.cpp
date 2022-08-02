class Solution {
public:
    
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                s1.push_back(tolower(s[i]));
            }
        }
        
        string s2(s1.rbegin(),s1.rend());
        cout<<s2;
        if(s1==s2){
            return true;
        }
        return false;
        
    }
    
};