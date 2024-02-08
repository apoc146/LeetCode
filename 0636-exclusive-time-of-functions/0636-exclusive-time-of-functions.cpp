class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n,0);
        int prevStartTime=0;
        for(auto& log:logs){
            
            stringstream iss(log);
            vector<string> logSplit;
            string token;
            while(std::getline(iss,token,':')){
                logSplit.push_back(token);
            }
            
            int pid=stoi(logSplit[0]);
            string status=logSplit[1];
            int time=stoi(logSplit[2]);
            
            if(status=="start"){
                if(!st.empty()){
                    ans[st.top()]+=(time-prevStartTime);
                }

                st.push(pid);
                prevStartTime=time;
            }else{
                ans[pid]+=(time-prevStartTime+1);
                st.pop();
                prevStartTime=time+1;
            }
        }
        return ans;
    }
};