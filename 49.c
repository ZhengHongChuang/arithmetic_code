/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-26 19:45:30
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-28 16:40:09
 */
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
}
void swap(char* a, char* b) {
	char temc = *a;
	*a = *b;
	*b = temc;
}

int Partition(char* s, int l, int r) {
	char c = s[r];
	int slow = l, fast = l;
	while (fast < r)
	{
		if (s[fast] < c) {
			swap(s + slow, s + fast);
			++slow;
		}
		++fast;
	}
	swap(s + slow, s + r);
	return slow;
}

void Quick_Sort(char* s, int l, int r) {
	if (l >= r) {
		return;
	}
	int q = Partition(s, l, r);
	Quick_Sort(s, l, q - 1);
	Quick_Sort(s, q + 1, r);
}
//练习一下快速排序；

char* Get_Sorted(char* s) {
	int len = strlen(s);
	char* rc = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(rc, s);
	Quick_Sort(rc, 0, len - 1);
	return rc;
}
//得到排序后的字符串(新的字符串，不进行原地修改)；

typedef struct str_node {
	char* s;
	struct str_node* next;
}str_node;
//单链表结构体

void Init(str_node** head) {
	*head = (str_node*)malloc(sizeof(str_node));
	(*head)->next = NULL;
}
//带头结点单链表的初始化

void Add(str_node* head, char* sa) {
	str_node* tems = (str_node*)malloc(sizeof(str_node));
	tems->s = sa;
	tems->next = head->next;
	head->next = tems;
}
//带头结点单链表的元素加入；

typedef struct hashtable {
	char* s;
	int num;
	str_node* head;
	UT_hash_handle hh;
}hashtable;
//哈希表结构体；

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
	hashtable* hash_head = NULL;
	int count = 0;//不同的字母异位词集的数量；
	for (int i = 0; i < strsSize; i++) {
		char* sorted_str = Get_Sorted(strs[i]);
		hashtable* temh = NULL;
		HASH_FIND_STR(hash_head, sorted_str, temh);
		if (temh) {
			++(temh->num);
			Add(temh->head, strs[i]);
			continue;
		}
		++count;
		temh = (hashtable*)malloc(sizeof(hashtable));
		temh->num = 1;
		temh->s = sorted_str;
		Init(&(temh->head));
		Add(temh->head, strs[i]);
        HASH_ADD_STR(hash_head, s, temh);
	}//将strs中的元素按情况加入到哈希表中；
	*returnSize = count;//返回不同字母异位词集的数量；
	*returnColumnSizes = (int*)malloc(sizeof(int) * count);
	char *** rccc = (char***)malloc(sizeof(char**) * count);
	int ind = 0;
	for (hashtable* htb = hash_head; htb; htb = (hashtable*)(htb->hh.next)) {
		(*returnColumnSizes)[ind] = htb->num;
		char** rcc = (char**)malloc(sizeof(char*) * (htb->num));
		int ind_rcc = 0;
		for(str_node* np = htb->head->next; np; np = np->next){
            rcc[ind_rcc] = np->s;
			++ind_rcc;
        }
		rccc[ind] = rcc;
		++ind;
	}//对每一个字母异位词集在*returnColumnSizes和rccc中记录其数量及内容；
	return rccc;
}

