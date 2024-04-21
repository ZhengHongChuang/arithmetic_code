/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-21 21:57:37
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-21 21:59:25
 */
/*
给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 
平衡
 二叉搜索树。

示例 1:

输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
示例 2:

输入: head = []
输出: []
*/
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* pre = NULL;
    while (fast != NULL && fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;
    pre->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}