/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-18 18:51:45
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-18 18:52:56
 */
/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

 

示例 1：

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
*/
/**
 * 搜素回溯
*/
int ansSize ;
int candidatesSize_tmp ;
int *ansColumnSize;
int combinSize;
void dfs(int * candidates,int target,int ** ans,int * combine,int id){
    if(id == candidatesSize_tmp){
        return ;
    }
    if(target == 0){
        int *tmp = malloc(sizeof(int)*combinSize);
        for(int i = 0;i<combinSize;i++){
            tmp[i] = combine[i];
        }
        ans[ansSize] = tmp;
        ansColumnSize[ansSize++] = combinSize;
        return;
    }

    if(target-candidates[id] >= 0){
        combine[combinSize++] = candidates[id];
        dfs(candidates,target-candidates[id],ans,combine,id);
        combinSize--;
    }
    dfs(candidates,target,ans,combine,id+1);

}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    candidatesSize_tmp = candidatesSize;
    ansSize = combinSize = 0;
    int **ans = malloc(sizeof(int*)*1001);
    ansColumnSize = malloc(sizeof(int)*1001);
    int combine[2001];
    dfs(candidates,target,ans,combine,0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ans;
    
}