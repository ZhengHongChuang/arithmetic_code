/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-03 16:52:56
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-03 19:09:51
 */
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include<stdio.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int rows = matrixSize, columns = *matrixColSize;
    int *res = (int *)malloc((rows * columns) * sizeof(int));
    *returnSize = rows * columns;
    int index = 0;
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++)
        {
            res[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            res[index++] = matrix[i][right];
        }
        right--;

        if (left <= right && top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res[index++] = matrix[bottom][i];
            }
            bottom--;

            for (int i = bottom; i >= top; i--)
            {
                res[index++] = matrix[i][left];
            }
            left++;

        }
    }
    return res;
}
int main(){
    int matrixSize = 3;
    int matrixColSize = 3;
    int **matrix = (int **)malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
    }
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    int returnSize;
    int *res = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}