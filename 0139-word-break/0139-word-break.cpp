class Solution {
public:
    void printVec(vector<bool> vec){
        cout<<endl;
        for(auto val:vec){
            cout<<val<<endl;
        }
    }

    bool fooTabular(string s,vector<string> dictr){
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<dictr.size();j++){
                string wrd=dictr[j];
                if((i+wrd.size() <= n) && (s.substr(i,wrd.size())==wrd)){
                    dp[i]=dp[i+wrd.size()];
                }
                if(dp[i]==true){
                    break;
                }
            }
        }
        return dp[0];
    }

    //timed out
    bool fooTab(string s,unordered_map<string,int> mp){
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;

        string part="";
        for(int i=n-1;i>=0;i--){
            part=s.substr(0,i+1);
            bool belong=(mp.count(part)>0);
            if(belong && s[i+1]){
                dp[i]=dp[i+1];
            }
            dp[i]=false;
        }
        printVec(dp);
        return dp[0];
    }

    //Memo still has TLE
    int fooMemo(string s,unordered_map<string,int> map,vector<int> dp,int idx){
        int n=s.size();
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        string part="";
        for(int i=idx;i<n;i++){
            part+=s[i];
            bool belong=map.count(part)>0;
            dp[i]=fooMemo(s,map,dp,i+1);
            if(belong==true && dp[i]==1){
                return 1;
            }
        }
        return dp[idx]=0;
    }
    
    bool fooRecur(string s, vector<string>& wordDict, int idx){
        int n=s.size();
        if(idx==n){
            return true;
        }

        bool res=false;
        string part="";
        for(int i=idx;i<s.size();i++){
            part+=s[i];
            if(find(wordDict.begin(),wordDict.end(),part)!=wordDict.end() && fooRecur(s,wordDict,i+1)){
                return true;
            }
        }

        return res;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //Recursive soution.
        //bool res=fooRecur(s,wordDict,0);
        int res;
        int n=s.size();

        unordered_map<string,int> map;
        for(auto& val:wordDict){
            map[val]=1;
        }

        //Working Tabulatio Code
        return fooTabular(s,wordDict);

        //DP memo
        // vector<int> dp(n+1,-1);
        // dp[n]=1;
        // res=fooMemo(s,map,dp,0);
        // return res;

        //Find in vector is a bottle nexk. converting it to maps for O(1) access;
    //     unordered_map<string,int> mp;
    //     for(auto& val:wordDict){
    //         mp[val]=1;
    //     }

    //     for(auto& pair:mp){
    //         cout<<pair.first<<" "<<pair.second<<endl;
    //     }

    //     bool ans=fooTab(s,mp);
    //     return bool(ans);
    }
};