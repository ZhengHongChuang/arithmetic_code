/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-02 20:08:00
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-06 14:33:10
 */
/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-02-02 20:08:00
 * @LastEditors: zhc
 * @LastEditTime: 2024-02-02 20:08:06
 */

/*
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。



示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uthash.h"

typedef struct hashTable
{
    char key[32];
    int val;
    UT_hash_handle hh;
} hashTable;

void insert(hashTable **hashtable, char ikey[], int flag,int *count)
{
    hashTable *tmp = NULL;

    HASH_FIND_STR(*hashtable, ikey, tmp);
    if (tmp == NULL)
    {
        hashTable *hashNode = (hashTable *)malloc(sizeof(hashTable));
        strcpy(hashNode->key, ikey);

        hashNode->val = 1;
        HASH_ADD_STR(*hashtable, key, hashNode);
        if (flag == 1)
        {
            (*count)++;
        }
    }
    else
    {
        tmp->val += 1;
    }
}
void clearHashTable(hashTable **table)
{
    hashTable *current, *tmp;
    HASH_ITER(hh, *table, current, tmp)
    {
        HASH_DEL(*table, current);
        free(current);
    }
}
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    int m = wordsSize, n = strlen(words[0]), ls = strlen(s);
    int *res = (int *)malloc(sizeof(int) * (ls - m * n));
    char word[32] = {0};
    int pos = 0;
    int vaild = 0;
    int count = 0;
    *returnSize = 0;
    hashTable *window = NULL;
    hashTable *map = NULL;
    // hashTable *curr, *tmp;

    for (int i = 0; i < m; i++)
    {
        insert(&map, words[i], 1,&count);
    }
    for (int i = 0; i < ls; i++)
    {
        if (i + m * n > ls)
        {
            break;
        }
        vaild = 0;
        for (int j = 0; j < m; j++)
        {
            snprintf(word, n, "%s", s + i + j * n);
            hashTable *tmp = NULL;
            HASH_FIND_STR(map, word, tmp);
            if (tmp == NULL)
            {
                vaild = 0;
                break;
            }
            else
            {
                hashTable *win_tmp = NULL;
                insert(&window, word, 0,&count);
                HASH_FIND_STR(window, word, win_tmp);

                if (tmp->val == win_tmp->val)
                {
                    vaild++;
                }
            }
        }
        if (vaild == count)
        {
            res[pos++] = i;
        }
        clearHashTable(&window);
    }
    clearHashTable(&map);
    *returnSize = pos;
    return res; // 返回结果数组
}
int main()
{

    char *s = "barfoothefoobarman";
    char *words[] = {"foo","bar"};
    int wordsSize = 2;
    int returnSize;
    int *result = findSubstring(s, words, wordsSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}
