/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 12:15:20
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 12:52:54
 */
/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集
（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
// 位运算
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    *returnSize = 1 << numsSize;
    int t[numsSize];
    for (int mask = 0; mask < (1 << numsSize); ++mask) {
        int tSize = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (mask & (1 << i)) {
                t[tSize++] = nums[i];
            }
        }
        int* tmp = malloc(sizeof(int) * tSize);
        memcpy(tmp, t, sizeof(int) * tSize);
        (*returnColumnSizes)[mask] = tSize;
        ans[mask] = tmp;
    }
    return ans;
}
int ** ans;
int ansSize;
int * t;
int tSize;
void dfs(int* nums, int numsSize, int start,int cur, int** returnColumnSizes) {
    if(tSize + numsSize - start < cur) return;
    if(tSize == cur){
        ans[ansSize] = malloc(sizeof(int) * cur);
        memcpy(ans[ansSize], t, sizeof(int) * cur);
        (*returnColumnSizes)[ansSize] = cur;
        ansSize++;
        return;
    }
    if (start == numsSize) return;
    t[tSize++] = nums[start];
    dfs(nums, numsSize, start + 1, cur, returnColumnSizes);
    tSize--;
    dfs(nums, numsSize, start + 1, cur, returnColumnSizes);
}
// 回溯+剪枝
int** subsets1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    ansSize = 0;
    t = malloc(sizeof(int) * numsSize);
    tSize = 0;
    for(int i = 0 ;i <= numsSize;i++){
        tSize = 0;
        dfs(nums, numsSize, 0,i, returnColumnSizes);
    }
    *returnSize = ansSize;
    return ans;
}