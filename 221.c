/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-22 22:36:12
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-24 01:42:58
 */
/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4

示例 2：
输入：matrix = [["0","1"],["1","0"]]
输出：1

示例 3：
输入：matrix = [["0"]]
输出：0

*/

#include<stdlib.h>
int min(int a, int b, int c) {
    int temp = a > b ? b : a;
    return temp > c ? c : temp;
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize < 1) {
        return 0;
    }

    // 分配dp数组的内存
    int **dp = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
        memset(dp[i], 0, sizeof(int) * (*matrixColSize));
    }

    int res = 0;

    // 填充dp数组
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j] - '0'; // 将字符'0'转换为整数
            } else {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }

            if (dp[i][j] > res) {
                res = dp[i][j];
            }
        }
    }

    // 释放dp数组的内存
    for (int i = 0; i < matrixSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return res * res;
}

