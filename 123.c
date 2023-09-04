/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-04 17:56:30
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-04 21:22:23
 */
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1:
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
*/
int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize){
     int buy1 = -prices[0]; // 第一次买入股票后剩余的钱，初始化为第一天的股价的相反数
     int sell1 = 0;        // 第一次卖出股票后剩余的钱，初始化为0
     int buy2 = -prices[0]; // 第二次买入股票后剩余的钱，初始化为第一天的股价的相反数
     int sell2 = 0;        // 第二次卖出股票后剩余的钱，初始化为0
     for (int i = 1; i < pricesSize; i++)
     {
          /**
           * 四种情况状态方程
          */
          buy1 = max(buy1,-prices[i]);
          sell1 = max(sell1,buy1+prices[i]);
          buy2 = max(buy2,sell1-prices[i]);
          sell2 = max(sell2,buy2+prices[i]);
     }
     return sell2;
}