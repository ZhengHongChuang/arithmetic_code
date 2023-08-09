/*
 * @Descripttion: Leetcode_code15
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-09 13:20:05
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-10 02:26:21
 */
/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return (*(int *)a - *(int *)b);

}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //数组排序
    qsort(nums,numsSize,sizeof(int),compare);
    //结果数组
    // int **res = NULL;
    int base_malloc = 5;
    int** res=malloc(sizeof(int*) * base_malloc);
    returnColumnSizes =NULL;
    *returnSize= 0;
    //双指针
    int left = 0, right = 0, target = 0 ,sum = 0;

    for (int i = 0; i < numsSize-2; i++)
    {
        //排序后的数组若nums[i]>0时必定nums[left]+nums[right]+nums[i]>0
        if(nums[i]>0){
            break;
        }
        if (i>0 && nums[i]==nums[i-1]) 
        {
            continue;
        }
        left = i+1;
        right = numsSize - 1;
        while (left<right)
        {
            sum = nums[left]+nums[right]+nums[i];
            
            if (sum>0)
            {
                right--;
            }else{
                if (sum<0)
                {
                    left++;
                }else{
                    (*returnSize)++;
                    //过渡realloc会导致在leetcode中出现内存限制超出
                    // res = (int**)realloc(res,sizeof(int *)*(*returnSize));
                    res[(*returnSize)-1] = (int *)malloc(sizeof(int)*3);
                    // res[(*returnSize)-1] = 3;
                    res[(*returnSize)-1][0] = nums[i];
                    res[(*returnSize)-1][1] = nums[left];
                    res[(*returnSize)-1][2] = nums[right];
                    if(*returnSize==base_malloc){
                        base_malloc *= 2;
                        res = (int**)realloc(res,sizeof(int *)*base_malloc);
                    }
                    //left和right去重
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right]==nums[right-1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                
            }
            
        }
    }
    // 分配和返回结果
    if (*returnSize > 0) {
        *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
        for (int i = 0; i < *returnSize; i++) {
            (*returnColumnSizes)[i] = 3;

            // returnColumnSizes[0][i]=3;
        }
    }
 
    return res;
}