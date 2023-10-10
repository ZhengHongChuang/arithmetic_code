/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-10-10 19:16:56
 * @LastEditors: zhc
 * @LastEditTime: 2023-10-10 20:40:41
 */

/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）
数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
*/
#include<string.h>
#include<stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int lengthOfLIS(int* nums, int numsSize){
    int dp[numsSize];
    memset(dp,0,sizeof(dp));
    int res = 1;
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i ;j++){
            if(nums[i] > nums[j]){
                dp[i] = dp[i] > dp[j]+1 ? dp[i]:dp[j]+1;
                res = max(dp[i],res);
            }
        }
    }
    return res;
    
}