/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-10-10 20:42:59
 * @LastEditors: zhc
 * @LastEditTime: 2023-10-10 20:46:54
 */

/*
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，
你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

示例 2:
输入: prices = [1]
输出: 0
*/

int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 1){
        return 0;
    }
    int dp[pricesSize][3];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 1; i<pricesSize; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        dp[i][2] = dp[i-1][1];

    }
    return dp[pricesSize-1][1];

}