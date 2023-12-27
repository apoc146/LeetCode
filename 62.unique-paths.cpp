/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (63.88%)
 * Likes:    16022
 * Dislikes: 421
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 * 
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 7
 * Output: 28
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 100
 * 
 * 
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int r=m;
        int c=n;
        vector<vector<int> > dp(r,vector<int>(c,1));
        for(int i=1;i<r;i++){
            vector<int> bottomRow=dp[i-1];
            for(int j=c-1;j>-1;--j){
                int rightVal=0;
                int bottomVal=0;
                if(j!=c-1){
                    rightVal=dp[i][j+1];
                }
                bottomVal=bottomRow[j];
                dp[i][j]=rightVal+bottomVal;
            }
        }
        return dp[m-1][0];
    }
};
// @lc code=end

int main(void){
    Solution s=Solution();
    cout<<s.uniquePaths(3,7);
}
