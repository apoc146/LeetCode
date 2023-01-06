class Solution {
public:
    int countSubstrings(string s) {
        vector<string> res;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            //odd
            int l=i;
            int r=i;
            
            while((l>=0 && r<n)&&(s[l]==s[r])){
                res.push_back(s.substr(l,r-l+1));
                l--;
                r++;
            }
            
            //check for even
            l=i;
            r=i+1;
            while((l>=0 && r<n)&&(s[l]==s[r])){
                res.push_back(s.substr(l,r-l+1));
                l--;
                r++;
            }
        }
        
        return res.size();
    }
};