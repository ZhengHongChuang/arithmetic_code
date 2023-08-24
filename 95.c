/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-24 14:17:47
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-24 14:40:07
 */

/*
给你一个整数 n,请你生成并返回所有由n个节点组成且节点值从1到 n互不相同的不同二叉搜索树 。
可以按 任意顺序 返回答案。

示例 1：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

示例 2：
输入：n = 1
输出：[[1]]
*/

#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 回溯函数：生成所有可能的唯一二叉搜索树
void backtrack(int start, int end, struct TreeNode*** result, int* returnSize) {
    // start：当前子树可用的节点值的范围起始值
    // end：当前子树可用的节点值的范围终止值
    // result：存储所有生成的树的指针数组的地址
    // returnSize：存储生成的树数量的地址

    // 如果起始值大于结束值，意味着当前分支无法构建树
    if (start > end) {
        // 增加返回大小（即当前已生成的树数量）
        (*returnSize)++;
        // 重新分配结果数组的内存，以容纳新的树
        *result = (struct TreeNode**)realloc(*result, (*returnSize) * sizeof(struct TreeNode*));
        // 添加一个空元素表示当前树配置的结束
        (*result)[*returnSize - 1] = NULL;
        return;
    }

    // 遍历所有可能的根值，从 start 到 end
    for (int i = start; i <= end; i++) {
        struct TreeNode** leftSubtrees = NULL;
        struct TreeNode** rightSubtrees = NULL;
        int leftSize = 0, rightSize = 0;

        // 生成当前根节点值的所有可能左子树
        backtrack(start, i - 1, &leftSubtrees, &leftSize);
        // 生成当前根节点值的所有可能右子树
        backtrack(i + 1, end, &rightSubtrees, &rightSize);

        // 创建树的配置，通过组合左子树和右子树
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                // 创建一个新的树节点，作为当前根节点
                struct TreeNode* root = createNode(i);
                // 设置根节点的左子树和右子树
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                // 增加返回大小，表示新树的生成
                (*returnSize)++;
                // 重新分配结果数组的内存，以容纳新生成的树
                *result = (struct TreeNode**)realloc(*result, (*returnSize) * sizeof(struct TreeNode*));
                // 将新生成的树添加到结果数组中
                (*result)[*returnSize - 1] = root;
            }
        }

        // 清理内存，释放左子树和右子树的分配内存
        free(leftSubtrees);
        free(rightSubtrees);
    }
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    *returnSize = 0;
    struct TreeNode** result = NULL;
    if (n == 0) {
        return result;
    }
    backtrack(1, n, &result, returnSize);
    return result;
}
