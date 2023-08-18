/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 16:11:41
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-18 16:18:21
 */

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。
机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？


示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：

从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下

示例 3：
输入：m = 7, n = 3
输出：28

示例 4：
输入：m = 3, n = 3
输出：6
*/
#include <stdio.h>

int uniquePaths(int m, int n) {
    // 创建一个二维数组来存储不同路径的数量
    int dp[m][n];

    // 初始化边界条件，第一行和第一列都只有一种路径到达
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    

    // 从左上角开始填充数组，每个位置的路径数等于上方和左方位置的路径数之和
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
        
    }
    

    return dp[m - 1][n - 1];
}
