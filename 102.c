/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-17 10:02:26
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-17 19:10:43
 */

/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
*/
#include <stdlib.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    int** res = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);\

    queue[rear++] = root;
    *returnSize = 0;

    while (front < rear) {
        int size = rear - front;
        res[(*returnSize)] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        (*returnSize)++;
    }
    return res;
}