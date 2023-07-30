/*
 * @Descripttion: Leetcode_code3
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-07-28 16:19:44
 * @LastEditors: zhc
 * @LastEditTime: 2023-07-30 21:43:04
 */

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/
#include<stdio.h>
#include<string.h>
#include"uthash.h"
//hash结构体
typedef struct hashTable
{
    char key;
    int val;
    UT_hash_handle hh;
}hashTable;
hashTable*hashtable;
hashTable * hashFind(char val){
    hashTable*tmp;
    HASH_FIND(hh, hashtable, &val, sizeof(char), tmp);
    return tmp;
}
void insert(char ival,int pos){
    hashTable *hashNode = (hashTable*)malloc(sizeof(hashTable));
    hashNode->key = ival;
    hashNode->val = pos;
    HASH_ADD(hh,hashtable,key,sizeof(char),hashNode);
}
/*
法一
*/
int lengthOfLongestSubstring1(char * s){
    int len = strlen(s);
    int left = 0, right = 0;
    int maxLen = 0;
    while(right<len){
        hashTable*tmp = hashFind(s[right]);
        if(tmp){
            while(left<tmp->val+1){
                hashTable * delNode = hashFind(s[left]);
                HASH_DEL(hashtable,delNode);
                free(delNode);    
                left++;
            }
        }
        insert(s[right],right);
        int currentLen = right - left + 1;
        maxLen = maxLen>currentLen ? maxLen:currentLen;
        right++;
    }
    return maxLen;

}

/*
法二：
*/
int lengthOfLongestSubstring2(char * s){
    int i;                  /*    计数器    */
    int count = 0;          /* 子串当前长度 */
    int max = 0;            /* 子串最大长度 */
    int start = 0;          /* 子串起始位置 */
    int index[128] = {0};   /* 记录每个字符先后出现位置采用ASCII码设置对应位置 */
    for(i = 0; s[i] != '\0'; i++){
        if(index[s[i]] > start){ /* 若为真，则说明字符s[i]在之前重复出现过 */
            count = i - start; /* 记录此时子串的长度 */
            max = count > max ? count : max;
            start = index[s[i]]; /* 更新新子串的起始位置 */
        }
        index[s[i]] = i + 1; /* 记录字符s[i]在整个字符串中出现的位置 */
    }
    count = i - start; /* 计算最后一个子串的长度 */
    return count > max ? count : max;
}
