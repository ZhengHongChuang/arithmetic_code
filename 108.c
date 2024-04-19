/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-19 19:55:55
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-19 19:57:34
 */
/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 
平衡
 二叉搜索树。

 

示例 1：


输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

示例 2：


输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize==0){
        return NULL;
    }
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid=numsSize/2;
    root->val=nums[mid];
    root->left=sortedArrayToBST(nums,mid);
    root->right=sortedArrayToBST(nums+mid+1,numsSize-mid-1);
    return root;
    
}