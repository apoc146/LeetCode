class Solution {
public:
    int calculate(string s) {
        char sign='+';
        stack<int> st;
        int cur=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                cur=10*cur+(s[i]-'0');
            }
            if(!isdigit(s[i])  && s[i] != ' ' || i == s.size()-1){
                if(sign=='+'){
                    st.push(cur);
                }else if(sign=='-'){
                    st.push(-1*cur);
                }else if(sign=='*'){
                    int val=st.top()*cur;
                    st.pop();
                    st.push(val);
                }else if(sign=='/'){
                    int val=st.top()/cur;
                    st.pop();
                    st.push(val);
                }
                sign=s[i];
                cur=0;
            }
        }
        
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};