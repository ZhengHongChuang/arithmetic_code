/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-01 15:10:37
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-01 15:19:44
 */

/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
*/
int removeDuplicates(int* nums, int numsSize) {
    int num = 1;
    int flag = 1;
    int curNum = nums[0];
    for(int i = 1; i<numsSize;i++){
        if(curNum==nums[i]){
            continue;
        }else{
            curNum = nums[i];
            nums[flag] = curNum;
            num++;
        }
    }
    return num;
    
}