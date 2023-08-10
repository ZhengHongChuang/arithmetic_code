/*
 * @Descripttion: Leetcode_code15
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-10 02:29:24
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-11 00:21:58
 */

/*

给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。

示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：
输入：nums = [0,0,0], target = 1
输出：0
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(const void *a,const void *b){
    return (*(int *)a - *(int *)b);

}
int threeSumClosest(int* nums, int numsSize, int target){
    //数组排序
    qsort(nums,numsSize,sizeof(int),compare);
    int closestSum = nums[0] + nums[1] + nums[2]; // 初始最接近的和
    int minDiff = abs(closestSum - target); // 初始最小差值
    for (int i = 0; i < numsSize-2; i++)
    {
        int left = i+1;
        int right = numsSize - 1;
        while (left<right)
        {
            int currentSum = nums[i] + nums[left] + nums[right];
            int currentDiff = abs(currentSum - target);
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                closestSum = currentSum;
            }
            if (currentSum < target) {
                left++;
            } else if(currentSum > target){
                right--;
            }else{
                return target;
            }
        }    
    }
    return closestSum;
}