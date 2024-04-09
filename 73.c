/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-08 22:38:25
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-09 20:27:08
 */
/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include <stdbool.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = *matrixColSize;
    int flag_col0 = false;
    for(int i = 0 ;i < m ;i++){
        if(matrix[i][0] == 0){
            flag_col0 = true;
        }
        for(int j = 1;j < n;j++){              
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i = m - 1;i >= 0;i--){
        for(int j = n - 1;j >= 1;j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if(flag_col0){
            matrix[i][0] = 0;
        }
    }
}