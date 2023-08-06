/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-05 17:00:56
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-06 16:53:17
 */

/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

示例 1：
输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
*/
/*
1、如果p为空，s为空匹配，s非空不匹配； 
2、s非空，p == s || p == '.'时第一个字符匹配； 
3、(p+1) != '*'，则递归判断剩下的是否匹配 first_match && isMatch(++s, ++p) 
4、(p+1) == '*'，则有两种情况匹配： 
    a: *匹配0个字符，s匹配剩下的，即isMatch(s, p+2) 
    b: *匹配1个字符，继续用p匹配剩下的s，即first_match && isMatch(s+1, p)

*/
#include<stdbool.h>
bool isMatch(char * s, char * p){
    if(!*p) return !*s;
    bool first_match = *s && (*s==*p||*p=='.');
    if(*(p+1)=='*'){
        return isMatch(s,p+2)||(first_match && isMatch(++s,p));
    }else{
        return first_match && isMatch(++s,++p);
    }
}