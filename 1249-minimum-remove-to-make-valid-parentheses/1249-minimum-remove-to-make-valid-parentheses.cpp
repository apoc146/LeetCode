class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ele=s[i];
            if(ele=='('){
                st.push(make_pair(ele,i));
            }else if(ele==')'){
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