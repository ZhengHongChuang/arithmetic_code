/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-09 20:04:38
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-09 22:07:58
 */

/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
*/
#include <stdbool.h>
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' + 1;
                int box_index = (i / 3) *3 + j / 3;
                if(row[i][num] || col[j][num] || box[box_index][num]){
                    return false;
                }
                row[i][num] = 1;
                col[j][num] = 1;
                box[box_index][num] = 1;
            }
        }
    }
    return true;
}