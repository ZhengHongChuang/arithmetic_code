/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-23 19:59:56
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-24 15:58:08
 */
/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
void backtrack(int ** res , int *nums , int first , int len , int *returnSize , int ** returnColumnSizes){
    if(first == len){
        res[*returnSize] = (int *)malloc(sizeof(int) * len);
        memcpy(res[*returnSize] , nums , sizeof(int) * len);
        (*returnColumnSizes)[*returnSize] = len;
        (*returnSize)++;

        return;
    }
    for(int i = first ; i < len ; i++){
        swap(&nums[first] , &nums[i]);
        backtrack(res , nums , first + 1 , len , returnSize , returnColumnSizes);
        swap(&nums[first] , &nums[i]);
    }
 
}
int jiecheng(int n){
    if(n == 1){
        return 1;
    }
    return n * jiecheng(n - 1);
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = jiecheng(numsSize);
    int **res = (int **)malloc(sizeof(int *) * size);
    *returnColumnSizes = (int *)malloc(sizeof(int) * size);
    *returnSize = 0;
    backtrack(res , nums , 0 , numsSize , returnSize , returnColumnSizes);
    
    return res;
}
int main(){
    int nums[3] = {1,2,3};
    int returnSize;
    int *returnColumnSizes;
    int **res = permute(nums , 3 , &returnSize ,&returnColumnSizes);
    for(int i = 0 ; i < returnSize ; i++){
        for(int j = 0 ; j < returnColumnSizes[i] ; j++){
            printf("%d " , res[i][j]);
        }
        printf("\n");
    }
    return 0;
}