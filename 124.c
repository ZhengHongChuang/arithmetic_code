/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-09-04 21:24:53
 * @LastEditors: zhc
 * @LastEditTime: 2023-09-05 17:51:58
 */

/*
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多出现一次 。该路径至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。
示例 1：
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 定义一个结构体来存储最大路径和
struct MaxPathSum {
    int maxSum;
};

// 辅助函数，计算以当前节点为根的最大路径和
int maxPathSumHelper(struct TreeNode* root, struct MaxPathSum* maxSum) {
    if (root == NULL) {
        return 0;
    }

    // 递归计算左子树和右子树的最大路径和
    int leftMax = maxPathSumHelper(root->left, maxSum);
    int rightMax = maxPathSumHelper(root->right, maxSum);

    // 计算以当前节点为根的最大路径和
    // 这个路径可以是当前节点的值加上左子树的路径或右子树的路径
    // 或者只包含当前节点的路径
    int currentNodeMax = root->val + (leftMax > 0 ? leftMax : 0) + (rightMax > 0 ? rightMax : 0);

    // 更新全局最大路径和
    if (currentNodeMax > maxSum->maxSum) {
        maxSum->maxSum = currentNodeMax;
    }

    // 返回以当前节点为根的最大路径和，但只能选择左子树路径或右子树路径中的一条
    return root->val + (leftMax > rightMax ? (leftMax > 0 ? leftMax : 0) : (rightMax > 0 ? rightMax : 0));
}

// 主函数，计算二叉树的最大路径和
int maxPathSum(struct TreeNode* root) {
    struct MaxPathSum maxSum;
    maxSum.maxSum = INT_MIN; // 初始化最大路径和为负无穷

    maxPathSumHelper(root, &maxSum);

    return maxSum.maxSum;
}