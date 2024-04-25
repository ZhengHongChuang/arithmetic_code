/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-24 19:17:34
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-25 19:31:11
 */
/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：


输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 
*/
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **res;
int resSize;
int *temp;
int tempSize;
void dfs(struct TreeNode* root, int targetSum, int curSum,int **returnColumnSizes){
    curSum += root->val;
    temp[tempSize++] = root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (curSum == targetSum)
        {
            res[resSize] = (int*)malloc(sizeof(int)*tempSize);
            (*returnColumnSizes)[resSize] = tempSize;
            for (int i = 0; i < tempSize; i++)
            {
                res[resSize][i] = temp[i];
            }
            resSize++;
        }
        tempSize--;
        return;
    }
    else
    {
        if(root->left!=NULL){
            dfs(root->left, targetSum, curSum, returnColumnSizes);
        }

        if(root->right!=NULL){
            dfs(root->right, targetSum, curSum, returnColumnSizes);
        }
        
    }
    tempSize--;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*1000);
    res = (int**)malloc(sizeof(int*)*1000);
    resSize = 0;
    temp = (int*)malloc(sizeof(int)*1000);
    tempSize = 0;
    dfs(root, targetSum, 0, returnColumnSizes);
    *returnSize = resSize;
    return res;
}