/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-04 17:45:20
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-04 17:48:55
 */

/*
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。

在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。

返回插入之后的 intervals。

注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (intervalsSize + 1));
    int resSize = 0;
    int i = 0;
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[resSize] = (int *)malloc(sizeof(int) * 2);
        res[resSize][0] = intervals[i][0];
        res[resSize][1] = intervals[i][1];
        (*returnColumnSizes)[resSize] = 2;
        resSize++;
        i++;
    }
    if (i == intervalsSize) {
        res[resSize] = (int *)malloc(sizeof(int) * 2);
        res[resSize][0] = newInterval[0];
        res[resSize][1] = newInterval[1];
        (*returnColumnSizes)[resSize] = 2;
        resSize++;
    } else {
        int left = newInterval[0];
        int right = newInterval[1];
        while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
            left = fmin(left, intervals[i][0]);
            right = fmax(right, intervals[i][1]);
            i++;
        }
        res[resSize] = (int *)malloc(sizeof(int) * 2);
        res[resSize][0] = left;
        res[resSize][1] = right;
        (*returnColumnSizes)[resSize] = 2;
        resSize++;
        while (i < intervalsSize) {
            res[resSize] = (int *)malloc(sizeof(int) * 2);
            res[resSize][0] = intervals[i][0];
            res[resSize][1] = intervals[i][1];
            (*returnColumnSizes)[resSize] = 2;
            resSize++;
            i++;
        }
    }
    *returnSize = resSize;
    return res;
}