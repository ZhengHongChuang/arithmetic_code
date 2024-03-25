/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-24 16:03:44
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-25 18:47:21
 */
/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* vis;

void backtrack(int* nums, int numSize, int** ans, int* ansSize, int idx, int* perm) {
    if (idx == numSize) {
        int* tmp = malloc(sizeof(int) * numSize);
        memcpy(tmp, perm, sizeof(int) * numSize);
        ans[(*ansSize)++] = tmp;
        return;
    }
    for (int i = 0; i < numSize; ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm[idx] = nums[i];
        vis[i] = 1;
        backtrack(nums, numSize, ans, ansSize, idx + 1, perm);
        vis[i] = 0;
    }
}

int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(sizeof(int*) * 2001);
    int* perm = malloc(sizeof(int) * 2001);
    vis = malloc(sizeof(int) * numsSize);
    memset(vis, 0, sizeof(int) * numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    backtrack(nums, numsSize, ans, returnSize, 0, perm);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}
int main(){
    int nums[] = {0,1,0,0,9}; // 0 0 0 1 9
    int returnSize;
    int* returnColumnSizes;
    int** res = permuteUnique(nums, 5, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
