/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-07 18:22:20
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-07 20:38:09
 */

/*
给你一个字符串 s，请你将 s 分割成一些子串，
使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(char* s, int n, int i, int** f, char*** ret, int* retSize, int* retColSize, char** ans, int* ansSize) {
    // 如果已经遍历到字符串的末尾，将当前答案存储到结果中
    if (i == n) {
        // 为临时存储答案创建一个字符指针数组
        char** tmp = malloc(sizeof(char*) * (*ansSize));
        
        // 复制答案到临时数组中
        for (int j = 0; j < (*ansSize); j++) {
            int ansColSize = strlen(ans[j]);
            tmp[j] = malloc(sizeof(char) * (ansColSize + 1));
            strcpy(tmp[j], ans[j]);
        }
        
        // 将临时数组添加到结果中
        ret[*retSize] = tmp;
        retColSize[(*retSize)++] = *ansSize;
        return;
    }

    // 遍历字符串中的每个字符，以找到回文子串
    for (int j = i; j < n; ++j) {
        if (f[i][j]) { // 如果从 i 到 j 是回文串
            // 为当前回文子串分配内存并复制
            char* sub = malloc(sizeof(char) * (j - i + 2));
            for (int k = i; k <= j; k++) {
                sub[k - i] = s[k];
            }
            sub[j - i + 1] = '\0';
            
            // 将当前回文子串添加到答案中，并继续深度优先搜索
            ans[(*ansSize)++] = sub;
            dfs(s, n, j + 1, f, ret, retSize, retColSize, ans, ansSize);
            
            // 回溯，移除当前回文子串
            --(*ansSize);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int retMaxLen = n * (1 << n); // 最大可能的结果数量，2^n
    char*** ret = malloc(sizeof(char**) * retMaxLen); // 存储结果的指针数组
    *returnSize = 0; // 结果集的大小
    *returnColumnSizes = malloc(sizeof(int) * retMaxLen); // 存储每个结果的列数
    int* f[n]; // 动态规划表，记录回文子串的状态
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            f[i][j] = 1; // 初始化为都是回文串
        }
    }

    // 使用动态规划填充回文串状态表
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }

    char* ans[n]; // 存储当前答案的字符串数组
    int ansSize = 0; // 当前答案的大小
    dfs(s, n, 0, f, ret, returnSize, *returnColumnSizes, ans, &ansSize); // 调用深度优先搜索函数来生成回文分割方案
    return ret; // 返回结果
}
