class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(make_pair(s[i],i));
            }else if(s[i]==')'){
                if(!st.empty() and st.top().first=='('){
                    st.pop();                
                }else{
                    st.push(make_pair(')',i));
                }
            }
        }

        while(!st.empty()){
            s.erase(s.begin()+st.top().second);
            st.pop();
        }

        return s;
    }
};