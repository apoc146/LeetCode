class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //using monotonic stack approach 
        int n=temperatures.size();
        vector<int> res(n);
        stack<pair<int,int>> stk;

        for(int i=0;i<n;i++){
            int ele=temperatures[i];

            if(stk.empty()){
                stk.push(make_pair(ele,i));
            }else{
                if(stk.top().first>=ele){
                    stk.push(make_pair(ele,i));
                }else{
                    while(!stk.empty() && ele>stk.top().first){
                        int pop_ele=stk.top().first;
                        int pop_ele_idx=stk.top().second;
                        stk.pop();
                        res[pop_ele_idx]=i-pop_ele_idx;
                    }
                    stk.push(make_pair(ele,i));
                }
            }
        }
        return res;
    }
};