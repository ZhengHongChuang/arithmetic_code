/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-22 18:09:43
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-24 00:03:23
 */

/*
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串
即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。
即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
如果是，返回 true ；否则，返回 false 。

 

示例 1：
输入：s1 = "great", s2 = "rgeat"
输出：true
解释：s1 上可能发生的一种情形是：
"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
"gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。
两个子字符串分别在随机下标处进行一轮分割
"g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
"r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
算法终止，结果字符串和 s2 相同，都是 "rgeat"
这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true

示例 2：
输入：s1 = "abcde", s2 = "caebd"
输出：false

示例 3：
输入：s1 = "a", s2 = "a"
输出：true
*/
#include<stdbool.h>
#include<string.h>
bool isScramble(char *s1, char *s2) {
    int len = strlen(s1);
    
    // 长度不同直接返回 false
    if (len != strlen(s2)) {
        return false;
    }
    
    // 创建一个三维的动态规划数组，dp[i][j][k] 表示 s1[i:i+k-1] 和 s2[j:j+k-1] 是否是扰乱字符串
    bool dp[len][len][len + 1];
    
    // 初始化单个字符的情况
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            dp[i][j][1] = s1[i] == s2[j];  // 初始化长度为 1 的子串
        }
    }
    
    // 枚举子串长度
    for (int k = 2; k <= len; k++) {
        for (int i = 0; i <= len - k; i++) {
            for (int j = 0; j <= len - k; j++) {
                dp[i][j][k] = false;  // 初始化当前长度的子串为 false
                for (int m = 1; m < k && !dp[i][j][k]; m++) {
                    // 尝试不同的分割点 m，判断两种情况是否满足扰乱字符串条件
                    dp[i][j][k] = (dp[i][j][m] && dp[i + m][j + m][k - m]) || 
                                  (dp[i][j + k - m][m] && dp[i + m][j][k - m]);
                }
            }
        }
    }
    
    // 返回整个字符串的判断结果
    return dp[0][0][len];
}
