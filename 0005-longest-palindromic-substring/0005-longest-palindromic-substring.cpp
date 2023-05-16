class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool isEven=(n%2==0);
        int maxlen=0;
        string res="";
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            //ODD
            l=i;
            r=i;
            while((l>=0 && r<=n-1) && (s[l]==s[r])){
                if((r-l+1)>=maxlen){
                    maxlen=r-l+1;
                    res=s.substr(l,r-l+1);
                    cout<<res<<endl;
                }
                
                l--;
                r++;       
            }

            l=i;
            r=i+1;
            while((l>=0 && r<=n-1) && (s[l]==s[r])){
                if((r-l+1)>=maxlen){
                    maxlen=r-l+1;
                    res=s.substr(l,r-l+1);   
                }
                
                l--;
                r++;       
            }

        }
        
        cout<<" l:"<<l<<" r:"<<r<<endl;
        if(res==""){
            res=s[0];
        }
        return res;
    }
};