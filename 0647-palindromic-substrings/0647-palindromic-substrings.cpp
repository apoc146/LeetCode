class Solution {
public:
    
int foo(int i,int j, string s){
        int n=s.size();
        int cnt=0;
        while(i>-1 and j<n and (s[i]==s[j])){
            --i;
            ++j;
            cnt++;
        }
    return cnt;
}
    
    int countSubstrings(string s) {
        int count=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        //either odd or even
        int e=foo(i,i+1,s);
        int o=foo(i,i,s);
        count+=(o+e);
    } 
    return count;
    }
};