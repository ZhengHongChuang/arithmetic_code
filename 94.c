/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 20:59:10
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-12 21:11:10
 */
/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void inorder(struct TreeNode* root, int *res,int* returnSize){
    if(root == NULL){
        return;
    }
    inorder(root->left,res,returnSize);
    res[(*returnSize)++] = root->val;
    inorder(root->right,res,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int)*501);
    *returnSize = 0;
    inorder(root,res,returnSize);
    return res;
}
