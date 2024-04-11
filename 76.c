/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-09 21:12:16
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 11:59:21
 */
/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。



注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。


示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *minWindow(char *s, char *t)
{
    int need[100] = {0};
    int isFind[100] = {0};
    int sLen = strlen(s);
    int tLen = strlen(t);
    int count = 0, left = 0, right = 0, minWight = sLen + 1, labelCount = 0, resLeft = 0, resRight = 0;
    for (int i = 0; i < tLen; i++)
    {
        if (need[t[i] - 'A'] == 0)
        {
            count++;
        }
        need[t[i] - 'A']++;
    }
    while (right < sLen )
    {
        if (need[s[right] - 'A'] != 0)
        {
            isFind[s[right] - 'A']++;
            if (isFind[s[right] - 'A'] == need[s[right] - 'A'])
            {
                labelCount++;
            }
        }
        while (labelCount == count)
        {
            if (right - left < minWight)
            {
                minWight = right - left;
                resLeft = left;
                resRight = right;
            }
            if (need[s[left] - 'A'] != 0)
            {
                isFind[s[left] - 'A']--;
                if (isFind[s[left] - 'A'] < need[s[left] - 'A'])
                {
                    labelCount--;
                }
            }
            left++;
        }
        right++;
    }
    if (minWight == sLen + 1)
    {
        return "";
    }
    char *res = (char *)malloc(sizeof(char) * (minWight + 2));
    for (int i = 0; i <= minWight; i++)
    {
        res[i] = s[resLeft + i];
    }
    res[minWight + 1] = '\0';
    return res;
}

int main()
{
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    char *res = minWindow(s, t);
    printf("\n%s\n", res);
    return 0;
}