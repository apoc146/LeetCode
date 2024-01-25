class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        vector<int> ans(n1+n2,0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int prod=(num1[i]-'0')*(num2[j]-'0')+ans[i+j];
                ans[i+j]=prod%10;
                ans[i+j+1]+=(prod)/10;
            }
        }

        reverse(ans.begin(),ans.end());
        int idx=0;
        while(idx<ans.size()-1 and ans[idx]==0){
            idx++;
        }
        string ansFinal="";
        vector<int> ans2(ans.begin()+idx,ans.end());
        for(auto& ele:ans2){
            ansFinal+=(ele+48);
        }
        return ansFinal;
    }
};