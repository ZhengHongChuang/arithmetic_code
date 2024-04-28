/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-25 19:31:57
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-28 12:32:49
 */
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：
输入：root = []
输出：[]
示例 3：
输入：root = [0]
输出：[0]
 
*/
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int num;

void flatten(struct TreeNode* root) {
    num = 0;
    struct TreeNode **l = (struct TreeNode**)malloc(sizeof(struct TreeNode *));
    preorderTraversal(root,&l);
    for(int i = 1;i<num;i++){
        struct TreeNode *pre = l[i-1],*cur = l[i];
        pre->left = NULL;
        pre->right = cur;

    }
    free(l);
}

void preorderTraversal(struct TreeNode* root, struct TreeNode*** l) {
    if (root != NULL) {
        num++;
        (*l) = (struct TreeNode**)realloc((*l),sizeof(struct TreeNode*)*num);
        (*l)[num - 1] = root;
        preorderTraversal(root->left,l);
        preorderTraversal(root->right,l);
    }
}
