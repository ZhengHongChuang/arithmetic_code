/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-22 21:50:39
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-22 21:50:53
 */
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下 ，
今晚能够偷窃到的最高金额。
示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/

// 辅助函数，用于计算两个整数的最大值
int max(int a, int b) {
    return a > b ? a : b;
}

// 辅助函数，计算在给定范围内（start到end）能够偷窃到的最高金额
int robHelper(int* nums, int start, int end) {
    int prevMax = 0;  // 到前一个房屋为止能偷窃到的最高金额
    int currMax = 0;  // 到当前房屋为止能偷窃到的最高金额

    // 遍历指定范围内的房屋
    for (int i = start; i <= end; i++) {
        int temp = currMax;
        // 计算到当前房屋为止能偷窃到的最高金额
        currMax = max(currMax, prevMax + nums[i]);
        prevMax = temp;  // 更新上一个房屋的最高金额，以备下一轮迭代使用
    }

    return currMax;  // 返回在指定范围内能够偷窃到的最高金额
}

// 主函数，计算能够偷窃到的最高金额
int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;  // 没有房屋可以偷窃，返回0
    if (numsSize == 1) return nums[0];  // 只有一个房屋，偷窃它即可

    // 计算要么从第一个房屋偷到倒数第二个房屋，要么从第二个房屋偷到最后一个房屋，取最大值
    return max(robHelper(nums, 0, numsSize - 2), robHelper(nums, 1, numsSize - 1));
}
