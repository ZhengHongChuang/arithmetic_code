/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 21:13:43
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-13 17:27:26
 */
/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左
子树
只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 

示例 1：


输入：root = [2,1,3]
输出：true
示例 2：


输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
*/
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool helper(struct TreeNode* root, long long lower, long long upper) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= lower || root->val >= upper) {
        return false;
    }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

bool isValidBST(struct TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}