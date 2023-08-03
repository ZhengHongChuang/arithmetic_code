/*
 * @Descripttion: Leetcode_code7
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-04 02:24:49
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-04 02:31:10
 */
/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。
 
示例 
输入：x = 123
输出：321
*/
#include<limits.h>
int reverse(int x){
    int res = 0;
    while (x!=0)
    {
        if(res<INT_MIN/10||res>INT_MAX/10){
            return 0;
        }
        int digit = x % 10;
        x/=10;
        res = res * 10 +digit;
    }
    return res;
    

}