/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-01-30 21:45:37
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-01 14:58:23
 */

/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
示例一：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例二：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
*/
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* p = head;
    struct ListNode* q = NULL;
    struct ListNode* temp = NULL;
    int i = 0;
    int j = 0;
    while (p!=NULL)
    {
        i++;
        p = p->next;
    }
    if (i < k) {
        return head;
    }
    p = head;
    while(j<k){
        temp = p->next;
        p->next = q;
        q = p;
        p = temp;
        j++;
    }
    head->next = reverseKGroup(p,k);
    return q;
    

}