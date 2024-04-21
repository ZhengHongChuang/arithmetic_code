/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-21 22:14:17
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-21 22:14:19
 */
/*
给定一个二叉树，判断它是否是 
平衡二叉树

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：


输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：

输入：root = []
输出：true
*/
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return fmax(height(root->left), height(root->right)) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    
}