/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-09 21:06:55
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-09 21:08:32
 */
/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。

 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]
*/
void quick_sort(int *nums,int left,int right){
    if(left>=right){
        return;
    }
    int i = left;
    int j = right;
    int key = nums[left];
    while(i<j){
        while(i<j && nums[j]>=key){
            j--;
        }
        nums[i] = nums[j];
        while(i<j && nums[i]<=key){
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = key;
    quick_sort(nums,left,i-1);
    quick_sort(nums,i+1,right);
}
void sortColors(int* nums, int numsSize) {
    quick_sort(nums,0,numsSize-1);
}