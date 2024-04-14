/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-14 18:26:20
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-14 19:04:16
 */
/*
给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。

 

示例 1：


输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：


输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void recoverTree(struct TreeNode* root) {
    struct TreeNode* pre = NULL;
    struct TreeNode* x = NULL;
    struct TreeNode* y = NULL;
    struct TreeNode* p = root;
    struct TreeNode* stack[100];
    int top = -1;
    while (top != -1 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->left;
        }
        p = stack[top--];
        if (pre != NULL && pre->val > p->val) {
            y = p;
            if (x == NULL) {
                x = pre;
            } else {
                break;
            }
        }
        pre = p;
        p = p->right;
    }
    int temp = x->val;
    x->val = y->val;
    y->val = temp;

}