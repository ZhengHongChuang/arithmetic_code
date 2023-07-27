/*
 * @Descripttion: Leetcode_code
 * @version: 1.0s
 * @Author: zhc
 * @Date: 2023-07-26 23:29:52
 * @LastEditors: zhc
 * @LastEditTime: 2023-07-27 14:32:16
 */
/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值target的那两个整数，
并返回它们的数组下标。你可以假设每种输入只会对应一个答案。
但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 
*/

#include<stdio.h>
#include<stdlib.h>
#include"uthash.h"

/*暴力枚举
    时间复杂度：O(N^2)
    空间复杂度：O(1)
*/
int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i]+nums[j]==target)
            {
                int *ret = (int*)malloc(sizeof(int)*2);
                ret[0]=i; ret[1] = j;
                *returnSize = 2;
                return ret;

            }
            
        }
        
    }
    *returnSize = 0;
    return NULL;
    
}


//hash结构体
typedef struct hashTable
{
    //存放数组的值
    int key;
    //存放数组值对应的下标
    int val;
    //用于管理哈希表的一个辅助数据结构
    UT_hash_handle hh;
}hashTable;
//全局hash表
hashTable *hashtable;
/*
    @Descripttion:通过值查找对应的数组下标
    @return:返回找到的元素地址，若未找到返回NULL
*/
hashTable * find(int key){
    hashTable*tmp;
    HASH_FIND_INT(hashtable,&key,tmp);
    return tmp;
}
/*
    @Descripttion:将K-V插入hashtable
*/
void insert(int ikey,int ival){
    hashTable *tmp = find(ikey);
    if(tmp==NULL){
        hashTable *hashNode = (hashTable*)malloc(sizeof(hashTable));
        hashNode->key = ikey;
        hashNode->val = ival;
        HASH_ADD_INT(hashtable,key,hashNode);
    }else{
        tmp->val = ival;
    }

}
/*哈希
    时间复杂度：O(N)
    空间复杂度：O(N)
*/
int* twoSum2(int* nums, int numsSize, int target, int* returnSize){
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        hashTable*it = find(target-nums[i]);
        if (it!=NULL)
        {
            int *ret = (int*)malloc(sizeof(int)*2);
            ret[0]=it->val;ret[1]=i;
            *returnSize = 2;
            return ret;
        }
        //若为找到则将对应的K-V插入hashTable
        insert(nums[i],i);

        
    }
    *returnSize = 0;
    return NULL;
    

}

int main(){
    int nums[4] = {2,7,11,15};
    int target = 9 , returenSize = 0;
    // int * ret = twoSum1(nums,4,target,&returenSize);
    int * ret = twoSum2(nums,4,target,&returenSize);
    if (ret!=NULL)
    {
        printf("[%d,%d]",ret[0],ret[1]);    
    }else{
        printf("[]");
    }
    return 0;
}