/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-08 21:13:25
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-08 22:37:19
 */

/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。

 

示例 1：

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 
示例 2：

输入：path = "/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
示例 3：

输入：path = "/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入：path = "/a/./b/../../c/"
输出："/c"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ** split(const char * s, char delim, int * returnSize) {
    int n = strlen(s);
    char ** ans = (char **)malloc(sizeof(char *) * n);
    int pos = 0;
    int curr = 0;
    int len = 0;
    
    while (pos < n) {
        while (pos < n && s[pos] == delim) {
            ++pos;
        }
        curr = pos;
        while (pos < n && s[pos] != delim) {
            ++pos;
        }
        if (curr < n) {
            ans[len] = (char *)malloc(sizeof(char) * (pos - curr + 1)); 
            strncpy(ans[len], s + curr, pos - curr);
            ans[len][pos - curr] = '\0';
            ++len;
        }
    }
    *returnSize = len;
    return ans;
}

char * simplifyPath(char * path){
    int namesSize = 0;
    int n = strlen(path);
    char ** names = split(path, '/', &namesSize);
    char ** stack = (char **)malloc(sizeof(char *) * namesSize);
    int stackSize = 0;
    for (int i = 0; i < namesSize; ++i) {
        if (!strcmp(names[i], "..")) {
            if (stackSize > 0) {
                --stackSize;
            } 
        } else if (strcmp(names[i], ".")){
            stack[stackSize] = names[i];
            ++stackSize;
        } 
    }
    
    char * ans = (char *)malloc(sizeof(char) * (n + 1));
    int curr = 0;
    if (stackSize == 0) {
        ans[curr] = '/';
        ++curr;
    } else {
        for (int i = 0; i < stackSize; ++i) {
            ans[curr] = '/';
            ++curr;
            strcpy(ans + curr, stack[i]);
            curr += strlen(stack[i]);
        }
    }
    ans[curr] = '\0';
    for (int i = 0; i < namesSize; ++i) {
        free(names[i]);
    }
    free(names);
    free(stack);
    return ans;
}


int main(){
    char path[] = "/...";
    printf("%s\n",simplifyPath(path));
    return 0;
}