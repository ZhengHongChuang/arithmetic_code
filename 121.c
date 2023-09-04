/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-04 11:36:07
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-04 11:45:22
 */

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择某一天买入这只股票并选择在 未来的某一个不同的日子 卖出该股票。
设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
*/
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; // 如果数组为空或只有一个元素，无法交易，返回0
    }

    int dp[pricesSize]; // 创建dp数组，用于存储每一天卖出股票所能获得的最大利润
    dp[0] = 0; // 第一天的最大利润为0
    int minPrice = prices[0]; // 最低买入价格初始化为第一天的价格

    // 从第二天开始遍历价格数组
    for (int i = 1; i < pricesSize; i++) {
        // 更新最低买入价格，将其更新为当前价格和之前的minPrice中的较小值
        minPrice = min(minPrice, prices[i]);

        // 使用动态规划公式来更新dp[i]
        // dp[i]等于之前的最大利润dp[i-1]和当前卖出价格与最低买入价格之差的较大值
        dp[i] = max(dp[i - 1], prices[i] - minPrice);
    }

    return dp[pricesSize - 1]; // 返回最大利润
}