/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-24 19:07:38
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-24 19:11:48
 */
/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
*/
#include <stdlib.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int min(int a,int b){
    return a<b?a:b;
}
int minDepth(struct TreeNode* root) {
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    int min_depth=INT_MAX;
    if(root->left!=NULL){
        min_depth=min(minDepth(root->left),min_depth);
    }
    if(root->right!=NULL){
        min_depth=min(minDepth(root->right),min_depth);
    }
    return min_depth+1;
}