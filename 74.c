/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-09 20:27:45
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-09 21:05:20
 */
/*
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool search(int* nums, int target, int left, int right) {
    if (left > right) {
        return false;
    }
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return true;
    } else if (nums[mid] > target) {
        return search(nums, target, left, mid - 1);
    } else {
        return search(nums, target, mid + 1, right);
    }
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if(matrix[0][0] > target || target > matrix[matrixSize - 1][*matrixColSize -1 ]){
        return false;
    }
    int * temp = matrix[0];
    for(int i = 1;i<matrixSize;i++){
        if(matrix[i][0] <=target && matrix[i][*matrixColSize-1]>=target){
            temp = matrix[i];
            break;
        }
    } 
    // for(int i = 0;i<*matrixColSize;i++){
    //     printf("%d ",temp[i]);
    // }
    return search(temp,target,0,(*matrixColSize -1));
}
int main(){
    int ** matrix = (int **)malloc(sizeof(int *)*3);
    int a[4] = {1,3,5,7};
    int b[4] = {10,11,16,20};
    int c[4] = {23,30,34,60};
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    int matrixColSize = 4;
    int target = 10;
    printf("%d\n",searchMatrix(matrix,3,&matrixColSize,target));
    return 0;
}