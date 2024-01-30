/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-14 01:32:23
 * @LastEditors: zhc
 * @LastEditTime: 2024-01-24 21:26:28
 */
/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：
输入：lists = []
输出：[]
示例 3：
输入：lists = [[]]
输出：[]
*/
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0){
        return NULL;
    }
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* p = head;
    int min = 0;
    int flag = 0;
    while(1){
        for(int i = 0;i<listsSize;i++){
            if(lists[i]!=NULL){
                flag = 1;
                min = i;
                break;
            }
        }
        if(flag == 0){
            break;
        }
        for(int i = min+1;i<listsSize;i++){
            if(lists[i]!=NULL&&lists[i]->val<lists[min]->val){
                min = i;
            }
        }
        p->next = lists[min];
        p = p->next;
        lists[min] = lists[min]->next;
    }
    return head->next;

}