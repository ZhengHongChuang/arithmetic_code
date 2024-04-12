/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 16:22:24
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-12 16:22:26
 */
/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

 

示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]
 
*/
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* s = malloc(sizeof(struct ListNode));
    struct ListNode* sHead = s;
    struct ListNode* l = malloc(sizeof(struct ListNode));
    struct ListNode* lHead = l;
    while(head!=NULL){
        if(head->val < x ){
            s->next = head;
            s = s->next;
        }else{
            l -> next = head;
            l = l->next;
        }
        head = head ->next;
    }
    l->next = NULL;
    s->next = lHead->next;
    return sHead->next;
}
