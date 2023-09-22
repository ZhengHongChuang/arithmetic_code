/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-22 15:51:00
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-22 21:49:52
 */
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。


示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/
int max(int a, int b) {
    return a > b ? a : b;
}
int rob(int* nums, int numsSize){
    if(numsSize<1){
        return 0;
    }
    int dp0 = 0;
    int dp1 = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int noRob = max(dp0, dp1);
        int isRpb = dp0 + nums[i];
        dp0 = noRob;
        dp1 = isRpb;
    }
    return max(dp0, dp1);
}

