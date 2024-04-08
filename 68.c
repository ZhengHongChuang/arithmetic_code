/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-08 20:25:48
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-08 21:01:23
 */
/*
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
 

示例 1:

输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **res = (char**)malloc(sizeof(char *) * wordsSize);
    int wordColSize[wordsSize];
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        wordColSize[i] = strlen(words[i]);
        res[i] = malloc(sizeof(char) * (maxWidth + 1));
        memset(res[i], ' ', sizeof(char) * maxWidth);
        res[i][maxWidth] = '\0';
    }
    int wordCount = 1, wordWidth = wordColSize[0];
    for (int i = 1; i < wordsSize; i++) {
        if (wordCount + wordColSize[i] + wordWidth > maxWidth) {
            if (wordCount == 1) {
                strncpy(res[*returnSize], words[i - 1], wordColSize[i - 1]);
                (*returnSize)++;
            } else {
                int sepLength = (maxWidth - wordWidth) / (wordCount - 1);
                int biasLength = (maxWidth - wordWidth) % (wordCount - 1);
                char *temp = res[*returnSize];
                for (int j = i - wordCount; j < i; j++) {
                    strncpy(temp, words[j], wordColSize[j]);
                    temp += wordColSize[j];
                    if (j != i - 1) {
                        if(biasLength>0){ 
                            // *temp = ' ';
                            temp += sepLength + 1;
                            biasLength--;
                        }else{
                            temp += sepLength;
                        }
                    }
                }
                (*returnSize)++;
            }
            wordCount = 1;
            wordWidth = wordColSize[i];
        } else {
            wordCount++;
            wordWidth += wordColSize[i];
        }
    }
    if (wordCount != 0) {
        char *temp = res[*returnSize];
        for (int j = wordsSize - wordCount; j < wordsSize; j++) {
            
            strncpy(temp, words[j], wordColSize[j]);
            temp += wordColSize[j];
            if (j < wordsSize - 1) {
                *temp = ' ';
                temp++;
            }
        }
        (*returnSize)++;
    }
    return res;
}

int main(){
    char *words[] = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int returnSize;
    char **res = fullJustify(words, 18, 20, &returnSize);
    printf("%d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }
    
    return 0;
}
