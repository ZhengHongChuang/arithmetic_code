/*
 * @Descripttion: Leetcode_code18
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-11 01:37:00
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-11 22:47:24
 */
/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
（若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按任意顺序返回答案 。

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int) * 1001);
    *returnSize = 0;
    
    
    *returnColumnSizes = malloc(sizeof(int) * 1001);
    if (numsSize < 4)
        return res;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 3; i++)
    {
        if ((nums[i] >=0 && nums[i] > target) || ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target))
            break;
        if ((i > 0 && nums[i] == nums[i - 1]) || ((long) nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target))
            continue;
        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if ((j > i + 1 && nums[j] == nums[j - 1]) || ((long) nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target))
                continue;
            if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                break;
            int left = j + 1, right = numsSize - 1;
            while (left < right)
            {
                // int sum = nums[i] + nums[j] + nums[left] + nums[right];
                //leetcode测试用例存在相加超过int范围情况所以类型改为long
                long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    int *tmp = malloc(sizeof(int) * 4);
                    tmp[0] = nums[i], tmp[1] = nums[j], tmp[2] = nums[left], tmp[3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)] = 4;
                    res[(*returnSize)] = tmp;
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}
// int main(){
//     int *returnSize = malloc(sizeof(int));
//     *returnSize = 0;
//     int **returnColumnSizes;
//     int nums[] = {1,-2,-5,-4,-3,3,3,5};
//     returnColumnSizes = fourSum(nums,8,-11,returnSize,returnColumnSizes);


// }