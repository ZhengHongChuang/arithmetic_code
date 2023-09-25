/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-24 01:45:19
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-25 20:48:08
 */

/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
示例 1：
输入：n = 13
输出：6

示例 2：
输入：n = 0
输出：0
*/

int countDigitOne(int n){
    int count = 0; // 保存数字 1 的个数
    int rem = 0; // 保存尾数，方便统计对应位上存在有多少个 1
    for (int i = 0; n != 0; i++) {
        int temp = n / 10; // 当前位前面的数大小
        if (temp * 10 + 1 < n) {
            temp++; // 如果当前位前面的数加上 1 后小于 n，那么当前位上一定存在数字 1
        } else if (temp * 10 + 1 == n) {
            count += rem + 1; // 如果当前位前面的数加上 1 等于 n，那么当前位上存在数字 1 的个数为尾数加 1
        }
        count += (temp * pow(10, i)); // 对应位的 1 前面的个数
        rem += (n % 10 * pow(10, i)); // 保存尾数
        n /= 10; // 继续处理下一位
    }
    return count; // 返回数字 1 的总个数
}