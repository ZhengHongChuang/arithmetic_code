/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-21 00:59:11
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-22 18:07:49
 */

/*
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
找出只包含 1 的最大矩形，并返回其面积。

示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。

示例 2：
输入：matrix = []
输出：0

示例 3：
输入：matrix = [["0"]]
输出：0
*/
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))  // 定义取两数较大值的宏
#define min(a, b) ((a) < (b) ? (a) : (b))  // 定义取两数较小值的宏

// 计算以当前行为底边的最大矩形面积
int calculateMaxRectangle(int* heights, int cols) {
    int maxArea = 0;

    for (int j = 0; j < cols; j++) {
        int minHeight = heights[j];  // 当前列的高度
        for (int k = j; k >= 0; k--) {
            if (heights[k] == 0) {
                break;  // 如果高度为0，不再继续向左计算
            }
            minHeight = min(minHeight, heights[k]);  // 更新最小高度
            maxArea = max(maxArea, minHeight * (j - k + 1));  // 计算矩形面积并更新最大值
        }
    }

    return maxArea;  // 返回最大矩形面积
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        return 0;  // 如果矩阵为空，直接返回0
    }

    // 创建和初始化高度数组
    int *heights = (int *)malloc(sizeof(int) * (*matrixColSize));
    // for (int j = 0; j < *matrixColSize; j++) {
    //     heights[j] = 0;  // 初始化高度数组为0
    // }
    memset(heights,0,sizeof(int) * (*matrixColSize));
    int maxArea = 0;  // 初始化最大矩形面积为0

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;  // 遇到 '1' 增加当前列的高度
            } else {
                heights[j] = 0; // 遇到 '0' 将当前列的高度重置为0
            }
        }

        // 计算以当前行为底边的最大矩形面积并更新最大值
        maxArea = max(maxArea, calculateMaxRectangle(heights, *matrixColSize));
    }

    free(heights);  // 释放高度数组的内存
    return maxArea;  // 返回最大矩形面积
}

