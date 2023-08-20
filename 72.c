/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 16:58:06
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-21 00:56:30
 */

/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/
#include <stdio.h>
#include <string.h>
// 计算三个数中的最小值
int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val)
        min_val = b;
    if (c < min_val)
        min_val = c;
    return min_val;
}

// 计算将 word1 转换成 word2 所需的最少操作数
int minDistance(char *word1, char *word2) {
    int len1 = strlen(word1); // 获取 word1 的长度
    int len2 = strlen(word2); // 获取 word2 的长度

    // 创建一个二维数组 dp，dp[i][j] 表示将 word1 的前 i 个字符转换成 word2 的前 j 个字符所需的最少操作数
    int dp[len1 + 1][len2 + 1];

    // 初始化第一行和第一列，表示将一个字符串转换为空串的操作数
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    // 填充数组 dp
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                // 当前字符相同，不需要额外操作，继承上一个状态的操作数
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 当前字符不同，选择插入、删除或替换操作中的最小操作数
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    // 返回将整个 word1 转换成 word2 所需的最少操作数
    return dp[len1][len2];
}



