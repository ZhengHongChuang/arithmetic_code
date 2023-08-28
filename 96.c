/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-29 00:52:08
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-29 02:03:02
 */

/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的二叉搜索树有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
输入：n = 3
输出：5

示例 2：
输入：n = 1
输出：1
*/
#include<string.h>
#include<stdlib.h>
int numTrees(int n) {
    if (n <= 0) {
        return 0;
    }
    // 创建一个数组来存储卡塔兰数
    int catalan[n + 1];
    memset(catalan,0,sizeof(int)*(n+1));
    catalan[0] = catalan[1] = 1;
    // 使用动态规划计算卡塔兰数
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        // 计算 catalan[i]，利用递推关系
        for (int j = 0; j < i; j++) {
            // 左子树的节点数量为 j，右子树的节点数量为 i - j - 1
            // 左子树和右子树的二叉搜索树数量相乘，然后累加到 catalan[i]
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    // 返回卡塔兰数的值，即不同节点数的二叉搜索树的数量
    return catalan[n];
}