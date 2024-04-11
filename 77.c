/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 12:02:11
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 12:14:44
 */
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
*/
#include<stdlib.h>
int* temp;
int tempSize;

int** ans;
int ansSize;
void dfs(int cur, int n, int k) {
    if(tempSize + (n - cur + 1) < k) {
        return;
    }
    if(tempSize == k){
        int* tmp = (int*)malloc(sizeof(int) * k);
        for(int i = 0; i < k; i++){
            tmp[i] = temp[i];
        }
        ans[ansSize++] = tmp;
        return;
    }
    temp[tempSize++] = cur;
    dfs(cur + 1, n, k);
    tempSize--;
    dfs(cur + 1, n, k);
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    temp = (int*)malloc(sizeof(int) * k);
    ans = (int**)malloc(sizeof(int*) * 200001);
    tempSize = ansSize = 0;
    dfs(1, n, k);
    *returnSize = ansSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansSize);
    for(int i = 0; i < ansSize; i++){
        (*returnColumnSizes)[i] = k;
    }
    return ans; 
}
