/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-19 19:14:03
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-19 19:55:20
 */
/*
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    struct TreeNode** queue = malloc(sizeof(struct TreeNode*) * 2001);
    int front=0,rear=0;
    int** res=(int**)malloc(sizeof(int*)*2001);
    *returnColumnSizes=(int*)malloc(sizeof(int)*2001);
    *returnSize=0;
    queue[rear++]=root;
    while(front < rear){
        int size=rear-front;
        res[*returnSize]=(int*)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++){
            struct TreeNode* node=queue[front++];
            res[*returnSize][i]=node->val;
            if(node->left!=NULL){
                queue[rear++]=node->left;
            }
            if(node->right!=NULL){
                queue[rear++]=node->right;
            }
        }
         (*returnColumnSizes)[*returnSize] = size;
         (*returnSize)++;
    }
    for (int i = 0; i < *returnSize / 2; ++i) {
        int* tmp1 = res[i];
        res[i] = res[*returnSize - i - 1];
        res[*returnSize - i - 1] = tmp1;
        int tmp2 = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[*returnSize - i - 1];
        (*returnColumnSizes)[*returnSize - i - 1] = tmp2;
    }
    return res;
}