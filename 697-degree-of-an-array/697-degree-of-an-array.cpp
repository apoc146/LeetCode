class Solution {
public:
    void printVec(vector<int> arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void printMap(unordered_map<int,vector<int> >map){
        cout<<endl;
        unordered_map<int,vector<int> >::iterator it;
        for(it=map.begin();it!=map.end();it++){
            cout<<it->first;
            cout<<" ";
            printVec(it->second);
        }
        cout<<endl;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int> > map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }

        // printMap(map);
        // cout<<"\n";

        // cout<<"Printing Degrees\n";
        int degree=0;
        unordered_map<int,vector<int> >::iterator it;
        for(it=map.begin();it!=map.end();it++){
            degree=max(degree,(const int)(it->second).size());
            // cout<<"******";
            // cout<<it->first<<":";
            // printVec(it->second);
            // cout<<degree;
            // cout<<endl;
        }

        int res=INT_MAX;
        for(it=map.begin();it!=map.end();it++){
            if(it->second.size()==degree){
                cout<<"\n"<<it->second.back()<<"\n";
                res=min(res,it->second.back()-it->second.front()+1);
                // int temp = it->second.back()-it->second.front();
                // res=min(it->second.back()-it->second.front(),res);
            }
        }

        return res?res:1;
    }
};