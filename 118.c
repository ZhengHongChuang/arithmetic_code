/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-31 22:34:09
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-01 00:00:40
 */

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2:
输入: numRows = 1
输出: [[1]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **res = malloc(sizeof(int*)*numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    for(int i = 0;i<numRows;i++){
        res[i] = (int *)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i]=i+1;
        res[i][0] = 1;
        res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            if(j==i-j){
                res[i][j] = res[i-1][j-1] + res[i-1][j]; 
               break;
            }else{
                res[i][i-j] = res[i][j] = res[i-1][j-1] + res[i-1][j]; 
            }
            
        }
    }
    return res;
}
