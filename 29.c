/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-01 20:10:38
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-02 13:40:52
 */

/*
给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。



示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = 3.33333.. ，向零截断后得到 3 。
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = -2.33333.. ，向零截断后得到 -2 。
*/
#include <limits.h>
int divide(int dividend, int divisor)
{
    int res = 0;
    int flag = 0;
    if (dividend == INT_MIN)
    {
        if (divisor == 1)
        {
            return INT_MIN;
        }
        if (divisor == -1)
        {
            return INT_MAX;
        }
    }
    if (dividend == INT_MAX)
    {
        if (divisor == 1)
        {
            return INT_MAX;
        }
        if (divisor == -1)
        {
            return -INT_MAX;
        }
    }
    if (divisor == INT_MIN)
    {
        return dividend == INT_MIN ? 1 : 0;
    }
    if (dividend == 0)
    {
        return 0;
    }
    if(divisor == 1){
        return dividend;
    }
    if (dividend > 0 && divisor > 0)
    {
        dividend = -dividend;
        divisor = -divisor;
    }
    if (dividend > 0)
    {
        dividend = -dividend;
        flag = 1;
    }
    if (divisor > 0)
    {
        divisor = -divisor;
        flag = 1;
    }

    while (dividend <= divisor)
    {
        if (++res >= INT_MAX)
        {
            if (flag && -res <= INT_MIN)
            {
                return INT_MIN;
            }
            return INT_MAX;
        }
        dividend -= divisor;
    }
    if (flag)
    {
        return -res;
    }
    else
    {
        return res;
    }
}
int divide2(int dividend, int divisor){
    int cnt = 0;
    int sign = 1;
    if ((dividend ^ divisor) < 0) { // 两数任意一个为负数
        sign = -1;
    }
    if (divisor == INT_MIN) { // 除数边界值特殊处理
        if (dividend == INT_MIN) {
            return 1;
        } else {
            return 0;
        }
    }
    if (dividend == INT_MIN) { // 被除数边界值特殊处理
        if (divisor == -1) {
            return INT_MAX;
        } else if (divisor == 1) {
            return INT_MIN;
        }
        dividend += abs(divisor); // 先执行一次加操作，避免abs转换溢出
        cnt++;
    } 
    int a = abs(dividend);
    int b = abs(divisor);
    while (a >= b) {
        int c = 1;
        int s = b;
        // 需指数级快速逼近，以避免执行超时
        while (s < (a >> 1)) { // 逼近至一半，同时避免溢出
            s += s;
            c += c;
        }
        cnt += c;
        a -= s;
    }
    return (sign == -1) ? -cnt : cnt;
}
