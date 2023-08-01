/*
 * @Descripttion: Leetcode_code4
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-07-30 21:50:09
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-01 17:48:05
 */

/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
eg:
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
*/

#include<stdio.h>
double getMedian(int* nums1, int nums1Size, int* nums2, int nums2Size,int midIndex){
    int indexNum1 = 0,indexNum2=0;
    while(1){
        if(indexNum1==nums1Size){
            return nums2[indexNum2+midIndex-1];
        }
        if(indexNum2==nums2Size){
            return nums1[indexNum1+midIndex-1];
        }
        if (midIndex==1){
            return nums1[indexNum1]<=nums2[indexNum2]?nums1[indexNum1]:nums2[indexNum2];
        }
        int half = midIndex/2;
        int newIndex1 = (indexNum1+half<=nums1Size?indexNum1+half:nums1Size)-1;
        int newIndex2 = (indexNum2+half<=nums2Size?indexNum2+half:nums2Size)-1;
        int pivot1 = nums1[newIndex1],pivot2 = nums2[newIndex2];
        if(pivot1<=pivot2){
            midIndex-=(newIndex1-indexNum1+1);
            indexNum1 = newIndex1 +1;
        }else{
            midIndex-=(newIndex2-indexNum2+1);
            indexNum2 = newIndex2 +1;
        }
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalLength = nums1Size+nums2Size;
    double media;
    if(totalLength%2==1){
        int midIndex = totalLength/2;
        media = getMedian(nums1,nums1Size,nums2,nums2Size,midIndex+1);
    }else{
        int midIndex1 = totalLength / 2 - 1;
        int midIndex2 = totalLength / 2;
        media = (getMedian(nums1,nums1Size,nums2,nums2Size,midIndex1+1)+getMedian(nums1,nums1Size,nums2,nums2Size,midIndex2+1))/2.0;
    }
    return media;
}
// int main(){
//     int nums1[2] ={1,3} , nums2[4] ={2,4,5,6};
//     printf("%lf",findMedianSortedArrays(nums1,2,nums2,4));


// }