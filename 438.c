/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-03 12:56:33
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-03 22:29:25
 */

/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。



示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int *findAnagrams(char *s, char *p, int *returnSize)
{
    int pos = 0 ,count = 0; 
    int left = 0, right = 0;
    int winRes = 0, mapRes = 0;
    int index = 0;
    int vaild = 0;
    int p_len = strlen(p);
    int s_len = strlen(s);

    *returnSize = 0;
    if (s_len < p_len)
    {
        
        return NULL;
    }
    int *map = (int*)malloc(sizeof(int) * 26);    // 滑动窗口哈希表初始化为0
    int *window = (int*)malloc(sizeof(int) * 26); // p哈希表初始化为0
    int *ans = (int*)malloc(sizeof(int) * s_len);
    memset(map,0,sizeof(int)*26);
    memset(window,0,sizeof(int)*26);
    for (int i = 0; i < p_len; i++)
    {
        index = p[i] - 'a';
        if (map[index] == 0)
        {
            count++;
        }
        map[index]++;
    }

    while (right < s_len)
    {
        index = s[right++] - 'a';
        mapRes = map[index];
        if (mapRes!=0)
        {
            window[index]++;
            winRes = window[index];
            if (mapRes == winRes)
            {
                vaild++;
            }
        }
        while (right - left == p_len)
        {
            if (vaild == count)
            {
                ans[pos++] = left;
                (*returnSize)++;
            }
            index = s[left++] - 'a';
            mapRes = map[index];
            if (mapRes)
            {
                winRes = window[index];
                if (mapRes == winRes)
                {
                    vaild--;
                }
                window[index]--;
            }
        }
    }
    free(map);
    free(window);
    return ans;
}

