/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 16:45:13
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-18 16:52:47
 */
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶

示例 2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
*/
#include<stdlib.h>
//第一种写法
int climbStairs1(int n){
    if (n==1)
    {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }
    
    
    int * dp = (int*)malloc(sizeof(int)*n);
    dp[0]=1,dp[1]=2;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    int res = dp[n-1];
    free(dp);
    return res;
}
//第二种写法
int climbStairs2(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; ++i) {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}
