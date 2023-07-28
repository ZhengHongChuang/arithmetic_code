/*
 * @Descripttion: Leetcode_code2
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-07-27 14:34:20
 * @LastEditors: zhc
 * @LastEditTime: 2023-07-28 16:17:09
 */

/*
给你两个非空的链表表示两个非负的整数。
它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储 一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* resNode = NULL;
    struct ListNode* tmpNode = NULL;
    int count = 0;
    while(l1||l2){
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1+n2+count;
        if(!resNode){
            resNode = tmpNode = malloc(sizeof(struct ListNode));
            tmpNode->val = sum%10;
            tmpNode->next = NULL;
        }else{
            tmpNode->next = malloc(sizeof(struct ListNode));
            tmpNode->next->val = sum%10;
            tmpNode = tmpNode->next;
            tmpNode->next = NULL;
        }
        count = sum/10;
        if(l1){
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if(count==1){
        tmpNode->next = malloc(sizeof(struct ListNode));
        tmpNode->next->val = count;
        tmpNode = tmpNode->next;
        tmpNode->next = NULL;
    }
    return resNode;
}
