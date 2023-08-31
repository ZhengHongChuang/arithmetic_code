/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-31 18:31:24
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-31 22:12:35
 */

/*
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
题目数据保证答案符合 32 位带符号整数范围。

示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit

示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
babgbag
babgbag
babgbag
babgbag
babgbag
*/
#include<string.h>
#include<math.h>
int numDistinct1(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);

    // dp[i][j] 表示 s 的前 i 个字符中包含 t 的前 j 个字符的子序列个数
    unsigned long long dp[m+1][n+1];

    // 初始化 dp 数组
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                dp[i][j] = 1; // 空字符串是任何字符串的子序列
            } else if (i == 0) {
                dp[i][j] = 0; // 空字符串的子序列个数为 0，除非 t 也为空
            } else {
                if (s[i-1] == t[j-1]) {
                    // 当 s[i-1] 和 t[j-1] 相等时，可以选择使用 s[i-1] 或者不使用，两种情况之和
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // 当 s[i-1] 和 t[j-1] 不相等时，只能选择不使用 s[i-1]
                    dp[i][j] = dp[i-1][j];
                  
                }
                
            }
        }
    }
    return (dp[m][n]<pow(2,32))?dp[m][n]:-1;
}
int numDistinct2(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    if (m < n) {
        return 0;
    }
    unsigned long long dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= m; i++) {
        dp[i][n] = 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        char sChar = s[i];
        for (int j = n - 1; j >= 0; j--) {
            char tChar = t[j];
            if (sChar == tChar) {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    
    return (dp[0][0]<pow(2,32))?dp[0][0]:-1;
}