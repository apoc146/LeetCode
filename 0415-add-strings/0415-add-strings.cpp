class Solution {
public:
    void printVec(vector<int> vec){
        for(auto& ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    string addStrings(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        vector<int> ans(n1+n2+1,0);
        int cnt=0;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        while(cnt<n1+n2){
            int n1=(num1.size()>cnt)?num1[cnt]-'0':0;
            int n2=(num2.size()>cnt)?num2[cnt]-'0':0;
            int sum=n1+n2+ans[cnt];
            ans[cnt]=(sum)%10;
            ans[cnt+1]=sum/10;
            cnt++;
        }
        
        reverse(ans.begin(),ans.end());
        // printVec(ans);
        cout<<ans.size();
        cnt=0;
        while(ans.size()>0 and cnt<ans.size() and ans[cnt]==0){
            cnt++;
        }
        string str="";
        for(int i=cnt;i<ans.size();i++){
            str+=(ans[i]+'0');
        }
        // for(auto& num:ans){
        //     if(num!=0){
        //         str+=(num+'0');
        //     }
        // }
        if(str==""){
            return "0"; 
        }
        return str;
    }
};