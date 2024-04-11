/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 13:00:52
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 13:01:09
 */
/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例 1：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
示例 3：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
*/
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int rowSize;
int colSize;
int wordSize;
bool dfs(char **board, int **mark, int row, int col, char *word, int index) {
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize || mark[row][col] || board[row][col] != word[index]) {
        return false;
    }
    if (index == wordSize - 1) {
        return true;
    }
    mark[row][col] = 1;

    bool res = dfs(board, mark, row + 1, col, word, index + 1) ||
               dfs(board, mark, row - 1, col, word, index + 1) ||
               dfs(board, mark, row, col + 1, word, index + 1) ||
               dfs(board, mark, row, col - 1, word, index + 1);
    mark[row][col] = 0;
    return res;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    rowSize = boardSize;
    colSize = *boardColSize;
    wordSize = strlen(word);
    int **mark = (int **)malloc(rowSize * sizeof(int *));
    for (int i = 0; i < rowSize; i++) {
        mark[i] = (int *)calloc(colSize, sizeof(int));
    }

    bool result = false;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (dfs(board, mark, i, j, word, 0)) {
                result = true;
                break;
            }
        }
        if (result) {
            break;
        }
    }

    for (int i = 0; i < rowSize; i++) {
        free(mark[i]);
    }
    free(mark);

    return result;
}