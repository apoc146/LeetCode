class Solution {
public:
        static bool comp(vector<int> v1,vector<int> v2){
        if(v1.front()<v2.front()){
            return true;
        }else if(v1.front()>v2.front()){
            return false;
        }else{
            if(v1.back()<v2.back()){
                return true;
            }else{
                return false;
            }
        }
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            
            int x=intervals[i][0];
            int y=intervals[i][1];
            
            int lastEleX=res.back()[0];
            int lastEleY=res.back()[1];
            
            if(lastEleY>=x){
                res[res.size()-1][1]=max(res[res.size()-1][1],y);
            }else{
                res.push_back(intervals[i]);
            }
        }
        
        return res;
        
// My original solution which is correct but times out    
        
//         sort(intervals.begin(),intervals.end());

//         int i=0;
//         while(i<intervals.size()-1){
//             vector<int> a=intervals[i];
//             vector<int> b=intervals[i+1];
//             if(a.front()<=b.front() && a.back() >= b.back()){
//                 intervals.erase(intervals.begin()+i+1);                    
//             }
//             else if(a.back()>=b.front()){
//                 //merge
//                 vector<int> mergedVec;
//                 mergedVec.push_back(a.front());
//                 mergedVec.push_back(b.back());
//                 intervals.erase(intervals.begin()+i,intervals.begin()+i+2);
//                 intervals.insert(intervals.begin()+i,mergedVec);
//             }else{
//                 i++;
//             }
//         }
//         return intervals;
    }
};