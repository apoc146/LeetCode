class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        vector<int> ans;
        int carry=1;
        for(int i=0;i<digits.size();i++){
            int ele=digits[i]+carry;
            ans.push_back(ele%10);
            carry=ele/10;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};