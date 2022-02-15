class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int> > map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }

        //check for duplicates
        unordered_map<int,vector<int> >::iterator it;
        for(it=map.begin();it!=map.end();it++){
                if((it->second).size()>1){
                    vector<int> mapValueVec = it->second; 
                    for(int i=1;i<mapValueVec.size();i++){
                        if(mapValueVec[i]-mapValueVec[i-1] <= k){
                            return true;
                        }
                    }
                }
        }

        return false;
    }
};