/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-15 01:03:19
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-16 00:55:20
 */

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
*/
//动态规划
int trap1(int* height, int heightSize) {
    if (heightSize == 0) {
        return 0;
    }
    int leftMax[heightSize],rightMax[heightSize],res = 0;
    memset(leftMax, 0, sizeof(leftMax));
    leftMax[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        leftMax[i] = leftMax[i-1]>height[i]?leftMax[i-1]:height[i];
    }
    memset(rightMax, 0, sizeof(rightMax));
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; --i) {
        rightMax[i] = rightMax[i+1]>height[i]?rightMax[i+1]:height[i];
    }
    for (int i = 0; i < heightSize; ++i) {
        res += (leftMax[i]<rightMax[i]?leftMax[i]:rightMax[i]) - height[i];
    }
    return res;
}
//双指针+动态规划
int trap(int* height, int heightSize) {
    int ans = 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = fmax(leftMax, height[left]);
        rightMax = fmax(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}

