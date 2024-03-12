/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-09 22:18:30
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-12 19:33:14
 */
/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool line[9][9];
bool column[9][9];
bool block[3][3][9];
bool valid;
int* spaces[81];
int spacesSize;

void dfs(char** board, int pos) {
    if (pos == spacesSize) {
        valid = true;
        return;
    }

    int i = spaces[pos][0], j = spaces[pos][1];
    for (int digit = 0; digit < 9 && !valid; ++digit) {
        if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            // 
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    memset(line, false, sizeof(line));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;
    spacesSize = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                spaces[spacesSize] = malloc(sizeof(int) * 2);
                spaces[spacesSize][0] = i;
                spaces[spacesSize++][1] = j;
            } else {
                int digit = board[i][j] - '0' - 1;
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            }
        }
    }

    dfs(board, 0);
}

