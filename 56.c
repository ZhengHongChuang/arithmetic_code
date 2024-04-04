/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-03 19:11:35
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-04 17:22:30
 */
/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void quick_sort(int** intervals, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int* key = intervals[left];
    while (i < j)
    {
        while (i < j && key[0] <= intervals[j][0])
        {
            j--;
        }
        intervals[i] = intervals[j];
        while (i < j && key[0] >= intervals[i][0])
        {
            i++;
        }
        intervals[j] = intervals[i];
    }
    intervals[i] = key;
    quick_sort(intervals, left, i - 1);
    quick_sort(intervals, i + 1, right);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    quick_sort(intervals, 0, intervalsSize - 1);
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;
    for (int i = 0; i < intervalsSize; i++)
    {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if (*returnSize == 0 || res[*returnSize - 1][1] < left)
        {
            res[*returnSize] = (int*)malloc(sizeof(int) * 2);
            res[*returnSize][0] = left;
            res[*returnSize][1] = right;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        else
        {
            res[*returnSize - 1][1] = res[*returnSize - 1][1] > right ? res[*returnSize - 1][1] : right;
        }
    }
    return res;
}