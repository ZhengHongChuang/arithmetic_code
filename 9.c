/*
 * @Descripttion: Leetcode_code9
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-05 16:58:47
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-05 16:59:07
 */

/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1：
输入：x = 121
输出：true
示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
*/
#include<stdbool.h>
bool isPalindrome(int x){
    int x_copy = x;
    int i;
    long res =0;
    while(x>0){
        i = x%10;
        x/=10;
        res = res*10+i;
    }
    if(res == x_copy){
        return true;
    }
    return false;
}