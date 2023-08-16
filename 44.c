/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-16 01:14:37
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-16 15:26:48
 */


/*
给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符序列（包括空字符序列）。
判定匹配成功的充要条件是：字符模式必须能够完全匹配输入字符串（而不是部分匹配）。

 
示例 1：
输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。

示例 2：
输入：s = "aa", p = "*"
输出：true
解释：'*' 可以匹配任意字符串。

示例 3：
输入：s = "cb", p = "?a"
输出：false
解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
*/


#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    // 获取输入字符串和字符模式的长度
    int slen = strlen(s);
    int plen = strlen(p);
    
    // 创建匹配状态表，dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配
    bool dp[slen + 1][plen + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // 空字符串和空模式是匹配的

    // 处理特殊情况，当 p 开头有多个 '*' 时，空字符串也能匹配
    for (int j = 1; j <= plen; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        } else {
            break; // 如果遇到非 '*' 字符，跳出循环
        }
    }

    // 填充匹配状态表
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                // 当前字符匹配或为 '?'，继承前一个状态
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // 当前字符为 '*'，可以选择以下两种情况：
                // 1. 让 '*' 匹配空字符，继承前一个状态 dp[i][j - 1]
                // 2. 让 '*' 匹配多个字符，继承上一行的状态 dp[i - 1][j]
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[slen][plen]; // 返回整个字符串是否匹配的结果
}




