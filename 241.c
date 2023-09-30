/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-29 15:44:28
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-30 16:02:59
 */

/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

 

示例 1：

输入：expression = "2-1-1"
输出：[0,2]
解释：
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2：

输入：expression = "2*3-4*5"
输出：[-34,-14,-10,-10,10]
解释：
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *diffWaysToComputeHelper(char *expression, int *res, int left, int right, int *resSize) {
    int returnLeft = 0;
    int returnRight = 0;

    for (int i = left; i < right; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            returnLeft = 0;
            returnRight = 0;
            int *resLeft = (int *)malloc(sizeof(int) * 100);
            int *resRight = (int *)malloc(sizeof(int) * 100);

            resLeft = diffWaysToComputeHelper(expression, resLeft, left, i, &returnLeft);
            resRight = diffWaysToComputeHelper(expression, resRight, i + 1, right, &returnRight);

            for (int j = 0; j < returnLeft; j++) {
                for (int k = 0; k < returnRight; k++) {
                    if (expression[i] == '+') {
                        res[(*resSize)++] = resLeft[j] + resRight[k];
                    } else if (expression[i] == '-') {
                        res[(*resSize)++] = resLeft[j] - resRight[k];
                    } else if (expression[i] == '*') {
                        res[(*resSize)++] = resLeft[j] * resRight[k];
                    }
                }
            }
            free(resLeft);
            free(resRight);   
        }
    }

    if (*resSize == 0) {
        int num = atoi(expression + left);
        res[(*resSize)++] = num;
    }

    return res;
}

int *diffWaysToCompute1(char *expression, int *returnSize) {
    int len = strlen(expression);
    int *res = (int *)calloc(100, sizeof(int));
    *returnSize = 0;
    diffWaysToComputeHelper(expression, res, 0, len, returnSize);
    return res;
}
int *diffWaysToCompute1(char *expression, int *returnSize) {
    
}