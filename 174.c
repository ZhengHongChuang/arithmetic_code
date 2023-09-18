/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-18 09:45:15
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-18 12:44:53
 */
/*
恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。
地下城是由 m x n 个房间组成的二维网格。我们英勇的骑士最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；
其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。
返回确保骑士能够拯救到公主所需的最低初始健康点数。
注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

输入：dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
输出：7
解释：如果骑士遵循最佳路径：右 -> 右 -> 下 -> 下 ，则骑士的初始健康点数至少为 7 。

示例 2：
输入：dungeon = [[0]]
输出：1
*/
#include<stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    if (dungeon == NULL || dungeonSize <= 0 || dungeonColSize == NULL || *dungeonColSize <= 0) {
        return 0;
    }
    int rows = dungeonSize;
    int cols = *dungeonColSize;
    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(cols * sizeof(int));
    }
    dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] < 0 ? 1 - dungeon[rows - 1][cols - 1] : 1;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i == rows - 1 && j == cols - 1) {
                continue;
            }
            int right = j + 1 < cols ? max(dp[i][j + 1] - dungeon[i][j], 1) : INT_MAX;
            int down = i + 1 < rows ? max(dp[i + 1][j] - dungeon[i][j], 1) : INT_MAX;
            dp[i][j] = min(right, down);
        }
    }
    int result = dp[0][0];
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}