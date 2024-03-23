/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-20 18:31:00
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-23 12:02:25
 */

/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。


示例 1：

输入：nums = [1,2,0]
输出：3
解释：范围 [1,2] 中的数字都在数组中。
示例 2：

输入：nums = [3,4,-1,1]
输出：2
解释：1 在数组中，但 2 没有。
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
解释：最小的正数 1 没有出现。
*/
#include <stdio.h>
int firstMissingPositive(int *nums, int numsSize)
{
    int temp = numsSize+1;
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])
        {
            temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i+1)
        {
            return i + 1;
        }
    }
    return numsSize+1;
}
int main()
{
    int nums[] = {2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", firstMissingPositive(nums, numsSize));
    return 0;
}