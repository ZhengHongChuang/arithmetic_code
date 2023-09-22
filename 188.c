/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-22 14:56:32
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-22 15:45:14
 */

/*
188. 买卖股票的最佳时机 IV
困难
1K
相关企业
给你一个整数数组 prices和一个整数 k,其中 prices[i]是某支给定的股票在第 i天的价格。
设计一个算法来计算你所能获取的最大利润。
你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1：
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

示例 2：
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/
#include<stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int k, int* prices, int pricesSize) {
    if (k <= 0 || pricesSize <= 1) {
        return 0;
    }

    int* dp = (int*)malloc(sizeof(int) * (2 * k));
    

    for (int i = 0; i < 2 * k; i++) {
        if (i % 2 == 0) {
            dp[i] = -prices[0];
        } else {
            dp[i] = 0;
        }
    }

    for (int i = 1; i < pricesSize; i++) {
        for (int j = 0; j < 2 * k; j++) {
            if (j % 2 == 0) {
                dp[j] = max(dp[j], -prices[i] + (j > 0 ? dp[j - 1] : 0));
            } else {
                dp[j] = max(dp[j], prices[i] + dp[j - 1]);
            }
        }
    }

    int maxProfit = dp[2 * k - 1];
    free(dp);
    return maxProfit;
}
