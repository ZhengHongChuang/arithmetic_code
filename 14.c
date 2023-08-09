/*
 * @Descripttion: Leetcode_code14
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-09 03:02:08
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-09 12:52:19
 */
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
#include<string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    int len = strlen(strs[0]),j = 0,i=0;
    for (int i = 1; i < strsSize; i++)
    {
        len = len < strlen(strs[i])?len:strlen(strs[i]);
    }
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < strsSize-1; j++)
        {
            if(strs[j][i] != strs[j+1][i]){
                break;
            }
        }
        if (j!=strsSize-1)
        {
            break;
        }    
    }
    strs[0][i] = '\0';
    return strs[0];
}