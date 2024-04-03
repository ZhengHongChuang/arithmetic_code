/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-03 16:45:04
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-03 16:50:41
 */
/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

 

示例 1：


输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：1
 
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int solutionsCount;
void backtrack( int *queens, int n, int row, int *columns, int *diagonals1, int *diagonals2)
{
    if(row == n){
        solutionsCount++;
        return;
    }
    for(int i = 0;i < n ;i++){
        if(columns[i]){
            continue;
        }
        int diagonal1 = row - i + n - 1;
        if(diagonals1[diagonal1]){
            continue;
        }
        int diagonal2 = row + i;
        if(diagonals2[diagonal2]){
            continue;
        }
        queens[row] = i;
        columns[i] = 1;
        diagonals1[diagonal1] = 1;
        diagonals2[diagonal2] = 1;
        backtrack(queens, n, row + 1, columns, diagonals1, diagonals2);
        queens[row] = -1;
        columns[i] = 0;
        diagonals1[diagonal1] = 0;
        diagonals2[diagonal2] = 0;
    }    
}
int totalNQueens(int n) {
    solutionsCount = 0;
    int *queens = (int *)malloc(n * sizeof(int));
    int *columns = (int *)malloc(n * sizeof(int));
    int *diagonals1 = (int *)malloc(2 * n * sizeof(int));
    int *diagonals2 = (int *)malloc(2 * n * sizeof(int));
    memset(queens, -1, n * sizeof(int));
    memset(columns, 0, n * sizeof(int));
    memset(diagonals1, 0, 2 * n * sizeof(int));
    memset(diagonals2, 0, 2 * n * sizeof(int));
    backtrack(queens, n, 0, columns, diagonals1, diagonals2);
    return solutionsCount;
    
}
int main(){
    int n = 4;
    printf("%d\n",totalNQueens(n));
    return 0;
}