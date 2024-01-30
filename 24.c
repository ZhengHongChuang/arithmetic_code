/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-01-30 14:48:02
 * @LastEditors: zhc
 * @LastEditTime: 2024-01-30 21:43:27
 */

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;
    while (current->next != NULL && current->next->next != NULL) {
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;
        first->next = second->next;
        second->next = first;
        current->next = second;
        current = current->next->next;
    }
    return dummy->next;
}
