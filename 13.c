/*
 * @Descripttion: Leetcode_code13
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-09 02:19:50
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-09 02:57:28
 */

/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如 罗马数字 2 写做 II ，即为两个并列的 1 。
    12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。
但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。
示例 1:
输入: s = "III"
输出: 3
示例 2:
输入: s = "IV"
输出: 4
*/
#include<string.h>
int romanToInt1(char * s){
    int symbolToValues[26];
    symbolToValues['I' - 'A'] = 1;
    symbolToValues['V' - 'A'] = 5;
    symbolToValues['X' - 'A'] = 10;
    symbolToValues['L' - 'A'] = 50;
    symbolToValues['C' - 'A'] = 100;
    symbolToValues['D' - 'A'] = 500;
    symbolToValues['M' - 'A'] = 1000;
    int len = strlen(s);
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int value = symbolToValues[s[i]-'A'];
        if (i<len-1 && value<symbolToValues[s[i+1]-'A'])
        {
            res -= value;
        }else{
            res += value;
        }
        
    }
    return res;
}
#include"uthash.h"
//hash结构体
typedef struct hashTable
{
    char key;
    int val;
    UT_hash_handle hh;
}hashTable;
hashTable*hashtable;
hashTable * hashFind(char key){
    hashTable*tmp;
    HASH_FIND(hh, hashtable, &key, sizeof(char), tmp);
    return tmp;
}
void insert(char key,int val){
    hashTable *hashNode = (hashTable*)malloc(sizeof(hashTable));
    hashNode->key = key;
    hashNode->val = val;
    HASH_ADD(hh,hashtable,key,sizeof(char),hashNode);
}
int romanToInt2(char * s){
    insert('I',1);
    insert('V',5);
    insert('X',10);
    insert('L',50);
    insert('C',100);
    insert('D',500);
    insert('M',1000);
    int len = strlen(s);
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int value = hashFind(s[i])->val;
        if (i<len-1 && value<hashFind(s[i+1])->val)
        {
            res -= value;
        }else{
            res += value;
        }
        
    }
    return res;
}
