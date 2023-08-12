/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-13 00:27:25
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-13 01:03:08
 */
/*
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
//迭代遍历
struct ListNode *mergeTwoLists1(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmp = res;
    while (list1 && list2)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (list1->val <= list2->val)
        {
            node->val = list1->val;
            node->next = NULL;
            tmp->next = node;
            tmp = tmp->next;
            list1 = list1->next;
        }else{
            node->val = list2->val;
            node->next = NULL;
            tmp->next = node;
            tmp = tmp->next;
            list2 = list2->next;
        }
    }

    while (list2 != NULL)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = list2->val;
        node->next = NULL;
        tmp->next = node;
        tmp = tmp->next;
        list2 = list2->next;
    }
    while (list1 != NULL)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = list1->val;
        node->next = NULL;
        tmp->next = node;
        tmp = tmp->next;
        list1 = list1->next;
    }
    return res->next;
}
//递归法
struct ListNode *mergeTwoLists2(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}