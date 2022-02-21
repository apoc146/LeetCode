class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int> > map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        
        vector<int> res;
        unordered_map<int,vector<int> >::iterator it;
        for(it=map.begin();it!=map.end();it++){
            if(map.count(target- it->first) && target != 2*(it->first)){
                    res.push_back(it->second.front());
                    res.push_back(map.find(target-it->first)->second[0]);
                    break;
            }else if(2*(it->first)==target && it->second.size()==2){
                res.push_back(it->second[0]);
                res.push_back(it->second[1]);
                break;
            }
        }
        return res;
    }
};