/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-14 01:43:49
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-15 01:01:03
 */

/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
示例 1：
输入：s = '(()'
输出：2
解释：最长有效括号子串是 '()'

示例 2：
输入：s = ')()())'
输出：4
解释：最长有效括号子串是 '()()'

示例 3：
输入：s = ''
输出：0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//动态规划
int longestValidParentheses1(char *s) {
    int maxLength = 0; // 最长有效括号子串的长度
    int n = strlen(s);

    if (n <= 1) {
        return maxLength; // 如果字符串长度小于等于1，不可能存在有效括号子串
    }
    int *dp = (int *)malloc(sizeof(int)*n);
    memset(dp,0,sizeof(int)*n);
    for (int i = 1; i < n; i++)
    {
        if(s[i]==')'){
            if (s[i-1]=='(')
            {
                // 情况一：前一个字符是左括号，形如...()
                // 这种情况下，当前右括号可以和前面的左括号组成有效括号对
                // 判断是否有前面的子串，如果有，加上前面子串的长度
                // 如果没有前面的子串，长度为2
                dp[i] = (i>=2?dp[i-2]:0)+2;
            }else if (i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
            {
                // 情况二：前一个字符也是右括号，形如...(())
                // 这种情况下，当前右括号可以和前面的左括号组成有效括号对
                // 但前面的左括号可能不止一个，因此需要跳过中间的右括号，找到对应的左括号
                // 判断是否有前面的子串，如果有，加上前面子串的长度
                // 如果没有前面的子串，长度为0
                // 还需要考虑中间可能有有效括号对，因此加上中间有效括号对的长度
                dp[i] = dp[i - 1] + ((i-dp[i-1]>=2)?dp[i-dp[i-1]-2]:0)+2;
            }
   
        }
        maxLength = dp[i]>maxLength?dp[i]:maxLength;
    }
    return maxLength;
}
//堆栈
int longestValidParentheses2(char *s) {
    int n = strlen(s); // 输入字符串的长度
    if (n <= 1) {
        return 0; // 如果字符串长度小于等于1，不可能存在有效括号子串
    }
    
    int maxLength = 0; // 记录最长有效括号子串的长度
    int top = 0;       // 栈顶指针，初始化为0
    int stk[n + 1];    // 使用数组作为栈来辅助处理括号匹配
    stk[top] = -1;     // 在栈底压入一个特殊值-1，用于辅助计算有效括号子串长度
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') { // 当前字符为左括号
            stk[++top] = i; // 将当前左括号的索引压入栈中
        } else {           // 当前字符为右括号
            top--;         // 弹出栈顶元素，表示匹配了一个括号对
            
            if (top == -1) { // 如果栈为空，表示当前右括号没有匹配的左括号
                stk[++top] = i; // 将当前右括号的索引压入栈中，用于辅助计算有效括号子串的长度
            } else {         // 否则，栈中还有未匹配的左括号
                maxLength = ((i - stk[top]) > maxLength) ? (i - stk[top]) : maxLength;
                // 计算当前右括号与栈顶元素之间的有效括号子串长度，更新最大长度
            }
        }
    }
    
    return maxLength; // 返回最长有效括号子串的长度
}

