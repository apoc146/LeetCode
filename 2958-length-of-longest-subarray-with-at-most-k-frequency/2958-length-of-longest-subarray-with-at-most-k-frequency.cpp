class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int ans=0;
        while(r<n){
            int ele=nums[r];
            int count=mp.count(ele);
            if(count>0){
               if(mp[ele].size()<k){
                   mp[ele].push_back(r);
                    r++;
               }else{
                    int first_idx=mp[ele][0];
                    mp[ele].erase(mp[ele].begin());
                    // --- IMP ---
                    l=max(first_idx+1,l); 
                   
                    mp[ele].push_back(r);
                    r++;

               } 
            }else{
                mp[ele].push_back(r);
                r++;
            }
            ans=max(ans,(r-1)-l+1);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, vector<int>> mp;
//         int ans = 0;
//         int l = 0, r = 0;
        
//         while (r < n) {
//             int ele = nums[r];
//             if (mp.count(ele) > 0) {
//                 if (mp[ele].size() < k) {
//                     mp[ele].push_back(r);
//                 } else {
//                     int first_idx = mp[ele][0];
//                     mp[ele].erase(mp[ele].begin());
//                     l = max(l, first_idx + 1);
//                     mp[ele].push_back(r);
//                 }
//             } else {
//                 mp[ele].push_back(r);
//             }
//             r++;
//             ans = max(ans, r - l);
//         }
        
//         return ans;
//     }
// };
