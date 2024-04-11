/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 19:25:12
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 21:58:10
 */
/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4
*/
#include<stdio.h>
#include<stdlib.h>
int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int)*heightsSize);
    int top = -1;
    int res = 0;
    for(int i=0;i<heightsSize;i++)
    {
        while(top != -1 && heights[i] <= heights[stack[top]]){
            int h = heights[stack[top]];
            top --;
            int w = top == -1 ? i:i-stack[top]-1;
            res = res > h*w ?res:h*w;
        }
        stack[++top] = i;
    }
    while(top != -1){
        int h = heights[stack[top]];
        top --;
        int w = top == -1?heightsSize:heightsSize-stack[top] - 1;
        res = res > h*w ?res:h*w;
    }
    return res;
    
}