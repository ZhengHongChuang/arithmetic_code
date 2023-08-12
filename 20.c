/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-12 00:16:35
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-13 00:25:56
 */


/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false
*/
#include<stdbool.h>
#include<string.h>
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}
bool isValid(char * s){
    int len = strlen(s);
    if(len%2==1){
        return false;
    }
    char stk[len+1];
    int top=0;
    for (int i = 0; i < len; i++)
    {
        char ch = pairs(s[i]);
        if (ch)
        {
            if(top==0||stk[top-1]!=ch){
                return false;
            }
            top--;
        }else{
            stk[top++] = s[i];
        }     
    }
    return top==0;   
}

