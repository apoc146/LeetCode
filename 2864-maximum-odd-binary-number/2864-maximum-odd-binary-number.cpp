class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int ones=0;
        for(auto& ch:s){
            ones+=((ch=='1')?1:0);
        }
        int zeros=n-ones;
        string ans(n,'0');
        ans[n-1]='1';
        int idx=0;
        while(ones-1>0){
            ans[idx++]='1';
             ones--;
        }
        return ans;
    }
};