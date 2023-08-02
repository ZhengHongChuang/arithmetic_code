/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-01 21:19:57
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-02 22:35:56
 */
/*
给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
方法一：动态规划算法
思路：
len = strlen(s)
1、len==0 or s==NULL return ""
2、dp[len][len] = {0},dp[i][i] = 1
3、s[i]==s[i+1] --> dp[i][i+1]=1
4、j = i+len-1
   s[i] == s[j] and dp[i+1][j-1]==1 -->isPalindrome
*/
char* longestPalindrome1(char* s) {
    if(s==NULL||strlen(s)==0){
        return "";
    }
    int n = strlen(s);
    int dp[n][n]; // 存储子串是否是回文串的状态数组
    memset(dp, 0, sizeof(dp)); // 初始化为0
    int start = 0; // 记录最长回文子串的起始位置
    int maxLen = 1; // 记录最长回文子串的长度

    // 单个字符本身是回文串
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 判断长度为2的子串是否是回文串
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    // 判断长度大于2的子串是否是回文串
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // 子串结束位置
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                start = i;
                maxLen = len;
            }
        }
    }

    // 提取最长回文子串
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
/*
方法二：中心扩展法（Manacher算法
*/
// 辅助函数：将字符串s转换为包含特殊字符的新字符串t
char* preprocessString(const char* s) {
    int n = strlen(s);
    char* t = (char*)malloc(2 * n + 3);
    t[0] = '$'; // 特殊字符$作为新字符串的起始字符
    t[1] = '#'; // 特殊字符#用来分隔原字符串的字符
    int j = 2;
    for (int i = 0; i < n; i++) {
        t[j++] = s[i]; // 将原字符串的字符添加到新字符串中
        t[j++] = '#'; // 在每个字符之间插入特殊字符#
    }
    t[j] = '\0'; // 新字符串的末尾添加空字符\0，形成C风格字符串
    return t;
}

char* longestPalindrome2(char* s) {
    if (s == NULL || strlen(s) == 0) {
        return "";
    }

    char* t = preprocessString(s); // 将原字符串s转换为新字符串t
    int n = strlen(t); // 新字符串t的长度
    int* P = (int*)malloc(n * sizeof(int)); // 用于存储每个字符为中心的回文串的半径长度的数组
    int C = 0; // 当前回文串的中心
    int R = 0; // 当前回文串的右边界
    int maxLen = 0; // 最长回文子串的长度
    int centerIndex = 0; // 最长回文子串的中心在字符串t中的索引

    for (int i = 1; i < n - 1; i++) {
        int iMirror = 2 * C - i; // i关于中心C的对称点
        P[i] = (R > i) ? (R - i < P[iMirror] ? R - i : P[iMirror]) : 0;

        // 扩展以i为中心的回文串
        while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
            P[i]++;
        }

        // 更新C和R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // 更新最长回文子串的信息
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // 释放内存
    free(t);
    free(P);

    // 计算原字符串中的起始位置和长度
    int start = (centerIndex - maxLen) / 2;
    int end = start + maxLen;

    // 提取最长回文子串
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}

