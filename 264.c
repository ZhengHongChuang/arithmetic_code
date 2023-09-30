/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-30 20:31:20
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-30 20:31:52
 */

/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。

示例 1：
输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。

示例 2：
输入：n = 1
输出：1
解释：1 通常被视为丑数。
*/
#include<stdlib.h>
int min(int a, int b) {
    return a > b ? b : a;
}
int nthUglyNumber(int n){
    int *dp = (int*) malloc(sizeof(int) * (n+1));
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for(int i=2;i<=n;i++){
        dp[i] = min(min(dp[p2]*2, dp[p3]*3), dp[p5]*5);
        if (dp[i]==dp[p2]*2) p2++;
        if (dp[i]==dp[p3]*3) p3++;
        if (dp[i]==dp[p5]*5) p5++; 
    }
    return dp[n];
}