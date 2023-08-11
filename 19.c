/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-11 23:02:05
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-12 00:10:09
 */

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
示例 1：

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
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
//计算链表长度解决
struct ListNode* removeNthFromEnd1(struct ListNode* head, int n){
    if (head==NULL)
    {
        return NULL;
    }
    struct ListNode * tmp = head;
    int count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    tmp = head;
    if(count==n){
        return head->next;
    }
    int target = count - n - 1;
    while (tmp)
    {
        if (target!=0)
        {
            target--;
            tmp = tmp->next;
        }else{
            tmp->next = tmp->next->next;
            break;
        }
    }
    return head;
    
    
}
//双指针
struct ListNode* removeNthFromEnd2(struct ListNode* head, int n){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *first = head;
    struct ListNode *second = head;
    for (int i = 0; i < n; i++) {
        if (second == NULL) {
            return head;
        }
        second = second->next;
    }
    if (second == NULL) {
        head = head->next;
        free(first); 
        return head;
    }
    while (second->next != NULL) {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return head;
}
