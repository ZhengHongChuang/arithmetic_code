/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-28 18:46:05
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-28 19:22:43
 */
/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。



示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
*/
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool isPalindrome(char *s)
{
    if (s == NULL)
        return true;
    int n = strlen(s);
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
        {
            ++left;
        }
        while (left < right && !isalnum(s[right]))
        {
            --right;
        }
        if (left < right)
        {
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            ++left;
            --right;
        }
    }
    return true;
}