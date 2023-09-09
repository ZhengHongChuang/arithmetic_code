/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-07 21:42:15
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-10 00:20:13
 */

/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
请你判断是否可以利用字典中出现的单词拼接出 s
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isInDict(char *s, char **wordDict, int wordDictSize) {
    for (int i = 0; i < wordDictSize; i++) {
        if (strcmp(s, wordDict[i]) == 0) {
            return true;
        }
    }
    return false;
}
// 主函数，判断是否可以利用字典中的单词拼接出字符串s
bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len + 1]; // 创建一个布尔数组dp，长度为s的长度+1，dp[i]表示s的前i个字符是否可以被拆分成字典中的单词
    memset(dp, false, sizeof(dp)); // 初始化dp数组为false
    dp[0] = true; // 空字符串可以被拆分

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
          if (dp[j])
          {
               char destination[len+1]; // 目标字符串需要足够大
               char *start = s+j;
               char *end = s + i;  // 指向源字符串的第12个字符（索引从0开始）
               size_t length = end - start; // 计算范围长度
               strncpy(destination, start, length); // 复制指定范围的内容到目标字符串
               destination[length] = '\0'; // 手动添加字符串结束符     
               if (isInDict(destination,wordDict,wordDictSize))
               {
                    dp[i] = true;
                    break;
               }
               
          }

        }
    }

    return dp[len]; // 返回dp[len]的值，表示整个字符串s是否可以被拆分成字典中的单词
}

int main()
{
     char *s = "aaaaaaa";
     char *wordDict[] = {"aaa", "aaaa"};
     int wordDictSize = 2;

     if (wordBreak(s, wordDict, wordDictSize))
     {
          printf("可以拼接出字符串s\n");
     }
     else
     {
          printf("无法拼接出字符串s\n");
     }

     return 0;
}
