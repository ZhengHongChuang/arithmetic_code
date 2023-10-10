/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-30 21:10:25
 * @LastEditors: zhc
 * @LastEditTime: 2023-10-10 19:13:36
 */

/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，
其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
*/
#include<stdlib.h>
#include<string.h>
int min(int a, int b) {
    return a > b ? b : a;
}
int numSquares(int n){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; i -j*j >= 0 ; j++)
        {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }   
    }
    return dp[n]; 
}