/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-01 00:20:46
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-04 11:25:08
 */

/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上.相邻的结点在这里指的是下标与上一层结点下标相同或者等于上一层结点下标 + 1的两个结点。
也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
输入：triangle = [[-10]]
输出：-10
*/

#include<string.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
   int dp[triangleSize][triangleSize];
   memset(dp,0,sizeof(dp));
   dp[0][0] = triangle[0][0];
   for (int i = 1; i < triangleSize; ++i) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    int res = dp[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++)
        res = min(res, dp[triangleSize - 1][i]);
    return res;
}