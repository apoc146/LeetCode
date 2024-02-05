class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token="";
        stack<string> st;
        
        while(getline(ss,token,'/')){
            if(token.size()==0 or token=="."){
                //skip
                continue;
            }
            
            if(token==".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(token);
            }
        }
        
        string ans;
        while(!st.empty()){
            string dir=st.top();
            reverse(dir.begin(),dir.end());
            ans+=dir;
            ans+='/';
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "/";
        }
        return ans;
    }
};