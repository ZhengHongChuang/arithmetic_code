/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 20:13:16
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-12 20:57:38
 */
/*
 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
*/
#include <stdlib.h>
#include <string.h>
void backtrack(char *s, int start, int part, char *ip, char **result, int *returnSize) {
    if (part == 4) {
        if (start == strlen(s)) {
            ip[strlen(ip) - 1] = '\0';  
            result[*returnSize] = malloc(strlen(ip) + 1);
            strcpy(result[*returnSize], ip);
            (*returnSize)++;
        }
        return;
    }
    int ip_len = strlen(ip);
    for (int len = 1; len <= 3; len++) {
        if (start + len > strlen(s)) break; 
        char *segment = malloc(len + 1);
        strncpy(segment, &s[start], len);
        segment[len] = '\0';
        int num = atoi(segment);
        if (segment[0] == '0' && len > 1 || num == 0 && len > 1) break;  
        if (num <= 255) {
            strcat(ip, segment);
            strcat(ip, ".");
            backtrack(s, start + len, part + 1, ip, result, returnSize);
            ip[ip_len] = '\0';  
        }

        if (num == 0 && len > 1) break;  
    }
}

char **restoreIpAddresses(char *s, int *returnSize) {
    char **result = malloc(100 * sizeof(char *));
    *returnSize = 0;
    char ip[20] = "";  
    backtrack(s, 0, 0, ip, result, returnSize);
    return result;
}