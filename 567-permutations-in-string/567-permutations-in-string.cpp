#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0;
        int l=s1.size();
        vector<int> s1_vec(26);

        for(int i=0;i<s1.size();i++){
            s1_vec[s1[i]-'a']++;
        }

        while(i+l <= s2.size()){
            int j=i;
            int k=i+l;
            vector<int> s2_vec(26);
            for(int z=j;z<k;z++){
                s2_vec[s2[z]-'a']++;
            }
            if(s1_vec==s2_vec){
                return true;
            }
            i++;
        }
        return false;
    }
};

int main(){
    Solution s=Solution();
    string s1="adc";
    string s2="dcda";
    cout<<"Test Output\n";
    cout<<"Ans->"<<s.checkInclusion(s1,s2);
}