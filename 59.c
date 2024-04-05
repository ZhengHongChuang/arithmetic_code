/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-04 17:58:29
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-05 12:13:06
 */
/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        res[i] = (int *)malloc(n * sizeof(int));
    }
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1, target = n * n;
    while (num <= target) {
        for (int i = left; i <= right; i++) {
            res[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            res[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            res[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            res[i][left] = num++;
        }
        left++;
    }
    return res;  
}
