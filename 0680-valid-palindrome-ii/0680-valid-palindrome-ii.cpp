class Solution {
public:
    bool foo(string s, int i, int j){
        string s1=s.substr(i,j-i+1);
        string s2(s1.rbegin(),s1.rend());
        cout<<s1<<" "<<s2;
        return s1==s2;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(j>=i){
            if(s[i]!=s[j]){
                return foo(s,i,j-1) or foo(s,i+1,j);
            }else{
                i++;
                j--;
            }
        }
        return (i>j);
    }
};