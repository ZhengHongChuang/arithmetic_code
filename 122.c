/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-04 11:46:08
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-04 17:51:54
 */

/*
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。
你在任何时候 最多 只能持有 一股股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
示例 1：
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
*/
//贪心算法
int maxProfit1(int* prices, int pricesSize){
    int res = 0;
    // memset(dp,0,sizeof(dp));
    for(int i = 1;i<pricesSize;i++){
        if(prices[i]>prices[i-1]){
            res += (prices[i]-prices[i-1]);
        }
    }
    return res;

}
//动态规划
int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit2(int* prices, int pricesSize){
     //dp[n][0]：手中没股票，dp[n][1]：手中有股票
    int dp[pricesSize][2];

    dp[0][0] = 0,dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
     dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
     dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
    }
    return dp[pricesSize-1][0];
}
