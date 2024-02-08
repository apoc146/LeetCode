class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n,0);
        int lastKnownStartTime=0;
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
                    ans[st.top()]+=(time-lastKnownStartTime);
                }

                st.push(pid);
                lastKnownStartTime=time;
            }else{
                ans[pid]+=(time-lastKnownStartTime+1);
                st.pop();
                lastKnownStartTime=time+1;
            }
        }
        return ans;
    }
};