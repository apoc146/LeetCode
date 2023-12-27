/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (57.55%)
 * Likes:    12570
 * Dislikes: 162
 * Total Accepted:    868.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 * 
 * 
 * For example, "ace" is a subsequence of "abcde".
 * 
 * 
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3  
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 * 
 * 
 */

#include<string>
#include<vector>
#include<uiostream>
using namespace std;
// @lc code=start
class Solution {
class Solution {
public:
    string t1="", t2="";
    int n1=0,n2=0;
    
    int foo(int idx1, int idx2){
        if(idx1<0 or idx2<0){
            return 0;
        }
        //match
        if(t1[idx1]==t2[idx2]){
            return 1+foo(idx1-1,idx2-1);
        }
        // mis match
        return max(foo(idx1-1,idx2),foo(idx1,idx2-1));        
    }
    
    int memo(vector<vector<int>>& dp, int idx1, int idx2){
        if(idx1<0 or idx2<0){
            return 0;
        }
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        
        //match
        if(t1[idx1]==t2[idx2]){
            return dp[idx1][idx2]=1+memo(dp,idx1-1,idx2-1);
        }
        // mis match
        return dp[idx1][idx2]=max(memo(dp,idx1-1,idx2),memo(dp,idx1,idx2-1));        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        t1=text1;
        t2=text2;
        n1=text1.size();
        n2=text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2,-1));
        memo(dp,n1-1, n2-1);
        return dp[n1-1][n2-1];
        // return foo(n1-1,n2-1);
    }
};
// @lc code=end

