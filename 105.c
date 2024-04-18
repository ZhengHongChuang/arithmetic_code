/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-18 19:39:56
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-18 20:56:57
 */
/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize==0) return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=preorder[0];
    int i;
    for(i=0;i<inorderSize;i++){
        if(inorder[i]==preorder[0]) break;
    }
    root->left=buildTree(preorder+1,i,inorder,i);
    root->right=buildTree(preorder+i+1,preorderSize-i-1,inorder+i+1,inorderSize-i-1);
    return root;
}