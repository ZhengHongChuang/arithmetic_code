/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 16:33:50
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-18 16:41:45
 */

/*
给定一个包含非负整数的 m x n 网格 grid ，
请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。


示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
*/
#include <stdio.h>
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];

    // 创建一个二维数组来存储不同路径的数量
    int dp[m][n];

    // 初始化第一行和第一列的总和数
    dp[0][0] = grid[0][0];
 
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1]+grid[0][j];
    }

    // 填充数组，每个位置的总和等于上方或左方位置的总和最小值与该位置上的数值之和。
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j]<dp[i][j-1]?(dp[i-1][j]+grid[i][j]):(dp[i][j-1]+grid[i][j]);
        }
    }
    return dp[m - 1][n - 1];
}