/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-07 20:53:05
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-07 20:59:43
 */
/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 。


示例 1：
输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

示例 2：
输入：s = "a"
输出：0

示例 3：
输入：s = "ab"
输出：1
*/
#include<string.h>
int minCut(char *s) {
    int n = strlen(s); // 获取字符串的长度
    
    // 创建动态规划表并初始化为0，f[i][j] 表示从位置 i 到 j 的子串是否为回文串
    int f[n][n];
    
    // 创建数组 dp，用于记录从 i 到 n-1 的最小切割次数
    int dp[n];
    
    // 初始化动态规划表为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j] = 0;
        }
    }

    // 使用动态规划填充回文串状态表
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            
            // 检查是否是回文串，即 s[i:j] 是否回文
            if (s[i] == s[j] && (len <= 2 || f[i + 1][j - 1])) {
                f[i][j] = 1;
            }
        }
    }
    
    // 计算最小切割次数
    for (int i = 0; i < n; i++) {
        dp[i] = i; // 最坏情况下，每个字符都需要切割
    }
    
    for (int i = 1; i < n; i++) {
        if (f[0][i] == 1) {
            dp[i] = 0; // 如果 s[0:i] 是回文串，不需要切割
            continue;
        }
        
        // 在每个位置 i 处寻找更小的切割次数
        for (int j = 0; j < i; j++) {
            if (f[j + 1][i] == 1) {
                dp[i] = fmin(dp[i], dp[j] + 1);
            }
        }
    }
    
    return dp[n - 1]; // 返回从字符串开头到结尾的最小切割次数
}
