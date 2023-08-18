/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-18 14:18:44
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-18 16:07:58
 */

/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
*/
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0; // 记录当前能够到达的最远位置
    
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false; // 如果当前位置超过了最远位置，说明无法继续前进，返回 false
        }
        maxReach = (i + nums[i]) > maxReach ? (i + nums[i]) : maxReach; // 更新最远位置
        if (maxReach >= numsSize - 1) {
            return true; // 如果最远位置已经超过了数组末尾，返回 true
        }
    }
    
    return false;
}