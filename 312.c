/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-10-10 20:53:09
 * @LastEditors: zhc
 * @LastEditTime: 2023-11-22 20:56:06
 */

/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，
你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 
这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。
如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
求所能获得硬币的最大数量。

示例 1：
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

示例 2：
输入：nums = [1,5]
输出：10
*/
// 思路：动态规划
#include<stdlib.h>
int rec[502][502];
int val[502];   
#define max(a,b) ((a)>(b)?(a):(b))    
int dp(int left ,int right){
    if(left >= right - 1)return 0;
    if(rec[left][right] != -1)return rec[left][right];
    for (int i = left + 1 ;i<right ; i++){
        int sum = val[left] * val[i] * val[right];
        sum += dp(left,i)+dp(i,right);
        rec[left][right] = max(rec[left][right],sum);
    }
    return rec[left][right];

}
int maxCoins(int* nums, int numsSize) {
    memset(rec,-1,sizeof(rec));
    val[0] = val[numsSize+1] = 1;
    for(int i=1;i<=numsSize;i++){
        val[i] = nums[i-1];
    }
    return dp(0,numsSize+1);
    
}