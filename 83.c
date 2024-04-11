/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-11 19:22:02
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-11 19:23:07
 */
/*
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

 

示例 1：


输入：head = [1,1,2]
输出：[1,2]
示例 2：


输入：head = [1,1,2,3,3]
输出：[1,2,3]
*/
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* cur = head;
    while(cur->next)
    {
        if(cur->val == cur->next->val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}