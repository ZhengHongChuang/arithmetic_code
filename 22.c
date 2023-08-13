/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-13 01:06:39
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-14 01:19:29
 */
/*
数字 n 代表生成括号的对数，请你设计一个函数，
用于能够生成所有可能的并且有效的括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 递归辅助函数，生成有效的括号组合
void generateParenthesisHelper(char **res, int *returnSize, char *current, int openCount, int closeCount, int n) {
    // 如果当前组合长度达到 2*n，表示生成一个有效组合
    if (strlen(current)==2*n)
    {
        res[(*returnSize)++] = strdup(current);
        return;
        
    }
    // 如果还可以添加左括号，则继续添加左括号
    if (openCount < n) {
        current[strlen(current)] = '(';         // 在当前组合末尾添加左括号
        generateParenthesisHelper(res, returnSize, current, openCount + 1, closeCount, n);
        current[strlen(current) - 1] = '\0';    // 回溯，将刚刚添加的左括号移除
    }

    // 如果已添加的左括号数大于右括号数，则继续添加右括号
    if (closeCount < openCount) {
        current[strlen(current)] = ')';         // 在当前组合末尾添加右括号
        generateParenthesisHelper(res, returnSize, current, openCount, closeCount + 1, n);
        current[strlen(current) - 1] = '\0';    // 回溯，将刚刚添加的右括号移除
    }
}

// 生成有效的括号组合的主函数
char **generateParenthesis(int n, int *returnSize) {
    // 分配用于存储结果的数组内存
    char **res = (char **)malloc(sizeof(char *) * 1430);
    *returnSize = 0;
    // 分配用于生成括号组合的字符串内存在leetcode要手动将分配空间初始化为0
    // char *current = (char *)malloc(sizeof(char) * (2 * n + 1));
    char *current = (char *)calloc((2 * n + 1), sizeof(char));
    current[0] = '\0';

    // 调用辅助函数生成括号组合
    generateParenthesisHelper(res, returnSize, current, 0, 0, n);

    // 释放临时内存
    free(current);
    return res;
}


