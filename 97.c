/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-29 02:06:16
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-31 18:30:39
 */

/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
两个字符串 s 和 t 交错 的定义与过程如下，
其中每个字符串都会被分割成若干非空子字符串：
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

示例 1：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true

示例 2：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false

示例 3：
输入：s1 = "", s2 = "", s3 = ""
输出：true
 
*/
#include <stdbool.h>  // 引入 bool 类型的头文件
#include <string.h>   // 引入字符串处理函数的头文件

// 判断 s3 是否可以由 s1 和 s2 交错组成
bool isInterleave(char *s1, char *s2, char *s3) {
    int lenS1 = strlen(s1);  // 计算 s1 的长度
    int lenS2 = strlen(s2);  // 计算 s2 的长度
    int lenS3 = strlen(s3);  // 计算 s3 的长度

    if ((lenS1 + lenS2) != lenS3) {
        return false;  // 如果 s1 和 s2 长度之和不等于 s3 的长度，直接返回 false
    }

    bool dp[lenS1 + 1][lenS2 + 1];  // 创建动态规划数组，dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符能否交错组成 s3 的前 i+j 个字符
    memset(dp, false, sizeof(dp));   // 初始化 dp 数组为 false

    dp[0][0] = true;  // 空字符串可以由空字符串交错组成

    // 动态规划遍历
    for (int i = 0; i <= lenS1; i++) {
        for (int j = 0; j <= lenS2; j++) {
            // 如果 s1 的第 i 个字符等于 s3 的第 i+j 个字符，并且之前的子问题也能交错组成
            if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                dp[i][j] |= dp[i - 1][j];  // 使用位操作符 |= 进行状态转移，相当于 dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            // 如果 s2 的第 j 个字符等于 s3 的第 i+j 个字符，并且之前的子问题也能交错组成
            if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                dp[i][j] |= dp[i][j - 1];  // 使用位操作符 |= 进行状态转移，相当于 dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return dp[lenS1][lenS2];  // 返回最终结果，表示 s3 是否可以由 s1 和 s2 交错组成
}
