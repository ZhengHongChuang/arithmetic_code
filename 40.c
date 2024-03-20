/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-18 19:12:52
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-20 18:27:16
 */

/*'
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。



示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**

* Return an array of arrays of size *returnSize.

* The sizes of the arrays are returned as *returnColumnSizes array.

* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

*/
#include<stdio.h>
#include<stdlib.h>
int candidatesSize_temp;
int combinSize;
int ansSize;
int *ansColumnSize;
void dfs(int *candidates, int target, int **ans, int *combine, int idx)
{
    if (target == 0)
    {
        int *tmp = malloc(sizeof(int) * combinSize);
        for (int i = 0; i < combinSize; i++)
        {
            tmp[i] = combine[i];
        }
        ans[ansSize] = tmp;
        ansColumnSize[ansSize++] = combinSize;
        return;
    }

    for (int i = idx; i < candidatesSize_temp; i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
        {
            continue; // Skip duplicates
        }
        if (target - candidates[i] >= 0)
        {
            combine[combinSize++] = candidates[i];
            dfs(candidates, target - candidates[i], ans, combine, i + 1);
            combinSize--;
        }
    }
}

void sort(int *candidates, int candidatesSize)
{
    for (int i = 0; i < candidatesSize; i++)
    {
        for (int j = i + 1; j < candidatesSize; j++)
        {
            if (candidates[i] > candidates[j])
            {
                int temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    candidatesSize_temp = candidatesSize;
    ansSize = combinSize = 0;
    int **ans = malloc(sizeof(int *) * 1001);
    ansColumnSize = malloc(sizeof(int) * 1001);
    int combine[2001];
    sort(candidates, candidatesSize);
    dfs(candidates, target, ans, combine, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ans;
}
int main(){

    int candidates[]={10,1,2,7,6,5,1};//1,1,2,5,6,7,10
    int target=8;
    int returnSize;
    int *returnColumnSizes;
    int **ans=combinationSum2(candidates,7,target,&returnSize,&returnColumnSizes);

    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}