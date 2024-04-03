/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-29 11:26:54
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-03 16:42:48
 */
/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。



示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int solutionsCount;
void backtrack(char ***solutions, int *queens, int n, int row, int *columns, int *diagonals1, int *diagonals2)
{
    if (row == n)
    {
        char **board = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++)
        {
            board[i] = (char *)malloc((n + 1) * sizeof(char));
            memset(board[i], '.', n);
            board[i][queens[i]] = 'Q';
            board[i][n] = '\0';
        }
        solutions[solutionsCount++] = board;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (columns[i])
        {
            continue;
        }
        int diagonal1 = row - i + n - 1;
        if (diagonals1[diagonal1])
        {
            continue;
        }
        int diagonal2 = row + i;
        if (diagonals2[diagonal2])
        {
            continue;
        }
        queens[row] = i;
        columns[i] = 1;
        diagonals1[diagonal1] = 1;
        diagonals2[diagonal2] = 1;
        backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
        queens[row] = -1;
        columns[i] = 0;
        diagonals1[diagonal1] = 0;
        diagonals2[diagonal2] = 0;
    }
}
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    solutionsCount = 0;
    int queens[n];
    int columns[n];
    int diagonals1[2 * n];
    int diagonals2[2 * n];
    memset(queens, -1, sizeof(queens));
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));
    char ***solutions = (char ***)malloc(501 * sizeof(char **));
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    *returnSize = solutionsCount;
    *returnColumnSizes = (int *)malloc(solutionsCount * sizeof(int));
    for (int i = 0; i < solutionsCount; i++)
    {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
}
