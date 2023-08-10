/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-11 00:26:04
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-11 01:32:27
 */
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
答案可以按 任意顺序返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1不对应任何字母。
2--->abc,3-->def,4-->ghi,5-->jkl,
6-->mno,7-->pqrs,8-->tuv,9-->wxyz

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<string.h>

const char *dp[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
// 回溯函数，用于生成字母组合
void backtrack(char *digits, char *current, int index, char **result, int *returnSize) {
    // 如果已经处理完所有数字，将当前组合添加到结果数组中
    if (index == strlen(digits)) {
        //复制地址current中的字符串，并将指针赋值给result[*returnSize]
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    // 获取当前要处理的数字
    int digit = digits[index] - '2';
    // 遍历当前数字对应的所有字母
    for (int i = 0; i < strlen(dp[digit]); i++) {
        // 在当前位置放置一个字母
        current[index] = dp[digit][i];
        // 递归调用处理下一个数字
        backtrack(digits, current, index + 1, result, returnSize);
    }
}

// 主函数，生成所有字母组合
char **letterCombinations(char *digits, int *returnSize) {
    // 如果输入为空，返回空结果
    if (digits == NULL || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    // 计算总的组合数
    int totalCombinations = 1;
    int digitsLength = strlen(digits);
    for (int i = 0; i < digitsLength; i++) {
        int digit = digits[i] - '2';
        totalCombinations *= strlen(dp[digit]);
    }

    // 分配结果数组和当前组合数组的内存
    char **result = (char **)malloc(totalCombinations * sizeof(char *));
    *returnSize = 0;
    char *current = (char *)malloc((digitsLength + 1) * sizeof(char));
    current[digitsLength] = '\0';

    // 调用回溯函数生成所有字母组合
    backtrack(digits, current, 0, result, returnSize);

    // 释放当前组合数组的内存
    free(current);

    // 返回最终结果数组
    return result;
}



