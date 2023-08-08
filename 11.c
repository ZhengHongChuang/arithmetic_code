/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-07 23:48:55
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-09 00:34:25
 */


/*
给定一个长度为 n 的整数数组 height 。
有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。
在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/
//双指针法
int maxArea(int* height, int heightSize){
    int left = 0,right = heightSize - 1;
    int maxArea = 0;
    while (left < right)
    {
        int high = height[left]<=height[right]?height[left]:height[right];
        int wide = right - left;
        int area = high * wide;
        maxArea = area >= maxArea?area:maxArea;
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxArea;
}