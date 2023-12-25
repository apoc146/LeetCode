/*
// 46/46 cases passed (27 ms)
// Your runtime beats 14.37 % of cpp submissions
// Your memory usage beats 11.72 % of cpp submissions (17.7 MB)

 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (46.41%)
 * Likes:    16559
 * Dislikes: 724
 * Total Accepted:    1.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool fooMemo(int idx, string s,vector<string> wordDict, vector<int>& dp){
        int n=s.size();
        if(idx>=n){
            return true;
        }        

        //I missed this = Used vec of true/false instead of -1. even false is an imp info
        if(dp[idx]!=-1){
            return dp[idx];
        }


        bool ans=false;
        for(int i=idx;i<n+1;i++){
            int len=(i-idx)+1;
            string word=s.substr(idx,len);
            // if word exists
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                ans|=fooMemo(i+1, s, wordDict, dp);
                if(ans==true){
                    break;
                }
            }
        }
        return dp[idx]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        bool sink=fooMemo(0, s, wordDict, dp);
        return sink;
    }
};
// @lc code=end