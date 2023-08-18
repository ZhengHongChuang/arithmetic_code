/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 14:08:30
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-18 14:16:25
 */

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（
子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
*/
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize){
    int *dp = (int *)malloc(sizeof(int)*numsSize);
    int res = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if(dp[i-1]+nums[i]>nums[i]){
            dp[i] = dp[i-1]+nums[i];
        }else{
            dp[i] = nums[i];
        }
        res = res>dp[i]?res:dp[i];
    }
    free(dp);
    return res;
    
}