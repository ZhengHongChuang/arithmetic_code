/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-05 13:13:34
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-06 12:02:17
 */
/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：

输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：

输入：head = [0,1,2], k = 4
输出：[2,0,1]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    struct ListNode *p = head;
    int len = 1;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    p->next = head;
    k = len - k % len;
    while(k--){
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}