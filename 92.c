/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-12 20:10:56
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-12 20:12:03
 */
/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
示例 2：

输入：head = [5], left = 1, right = 1
输出：[5]
*/


#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void reverseLinkList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return;
    }
    struct ListNode *p;
    struct ListNode *q;
    struct ListNode *r;
    p=head;
    p = head;
    q = head->next;
    head->next = NULL; 
    while (q) {
        r = q->next; 
        q->next = p; 
        p = q;
        q = r;
    }
    head = p; 
    

}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* dunmyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dunmyNode->val=0;
    dunmyNode->next=head;
    struct ListNode* tempLeftPreNode = dunmyNode;
    for(int i=0;i<left-1;i++){
        tempLeftPreNode = tempLeftPreNode->next;
    }
    struct ListNode* tempRightNode = tempLeftPreNode;
    for(int i=left;i<right+1;i++){
        tempRightNode = tempRightNode->next;
    }
    struct ListNode * tempLeftNode = tempLeftPreNode->next;
    struct ListNode * tempRightNextNode = tempRightNode->next;
    tempLeftPreNode->next=NULL;
    tempRightNode->next=NULL;
    reverseLinkList(tempLeftNode);
    tempLeftPreNode->next = tempRightNode;
    tempLeftNode->next = tempRightNextNode;
    return dunmyNode->next;
}