/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 18:20:46
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 19:17:23
 */
/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

 

示例 1：


输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：


输入：head = [1,1,1,2,3]
输出：[2,3]
 
*/
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL)
        return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* cur = dummy;
    while(cur->next && cur->next->next)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int x = cur->next->val;
            while(cur->next && cur->next->val == x)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummy->next;
}