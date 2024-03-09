/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-07 15:24:08
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-09 19:56:30
 */

/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。



示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(res, -1, sizeof(int) * 2);
    if (numsSize == 0)
    {

        return res;
    }
    if (numsSize == 1)
    {
        if (target == nums[0])
        {
            memset(res, 0, sizeof(int) * 2);
        }
        else
        {
            memset(res, -1, sizeof(int) * 2);
        }
        return res;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            int i = mid;
            int j = mid;
            while (i >= 0 && nums[i] == target)
            {
                i--;
            }
            while (j < numsSize && nums[j] == target)
            {
                j++;
            }
            res[0] = i + 1;
            res[1] = j - 1;
            return res;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
    }

    return res;
}
int main()
{
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 6;
    int *res;
    int numsSize = sizeof(nums) / sizeof(int);
    res = searchRange(nums, numsSize, target, res);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}