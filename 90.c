/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 16:58:46
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-12 20:10:37
 */
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 
子集
（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tempSize;
int *temp;

int **res;
int resSize;


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void dfs(int* nums, int numsSize, int start, int cur, int** returnColumnSizes) {
    if (tempSize + numsSize - start < cur) return;
    if (tempSize == cur) {
        res[resSize] = malloc(sizeof(int) * cur);
        memcpy(res[resSize], temp, sizeof(int) * cur);
        (*returnColumnSizes)[resSize] = cur;
        resSize++;
        return;
    }
    if (numsSize == start) return;
    temp[tempSize++] = nums[start];
    dfs(nums, numsSize, start + 1, cur, returnColumnSizes);
    tempSize--;
    while (start + 1 < numsSize && nums[start] == nums[start + 1]) start++;
    dfs(nums, numsSize, start + 1, cur, returnColumnSizes);


}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    res = malloc(sizeof(int*)*(1 << numsSize));
    temp = malloc(sizeof(int) * numsSize);
    resSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    for (int i = 0; i <= numsSize; i++) {
        tempSize = 0;
        dfs(nums, numsSize, 0, i, returnColumnSizes);
    }
    *returnSize = resSize;
    return res;
}

int main(){
    int nums[] = {1,2,2,2};
    int numsSize = 4;
    int returnSize = 0;
    int *returnColumnSizes = malloc(sizeof(int) * (1<<numsSize));
    int **res = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}