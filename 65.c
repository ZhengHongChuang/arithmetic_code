/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-06 12:23:50
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-07 19:42:33
 */
/*

有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
 
*/
#include<stdbool.h>
#include<string.h>
bool isNumber(char* s) {
    bool isNum = false, isDecimal = false, isE = false,isSign = false;
        int len = strlen(s);
        for(int i = 0; i < len ;i++){
            char temp = s[i];
            if(0<=temp-'0' && temp-'0' <= 9){
                isNum = true;
            }else if(temp=='.'){
                if(isDecimal||(!isNum && i == len-1)||isE)
                    return false;
                isDecimal = true;
            }else if(temp=='e'||temp=='E'){
                if(i==len-1 || isE || !isNum )
                    return false;
                isE = true;
            }else if(temp == '+' || temp == '-'){
                if( (i>0 && s[i-1] != 'e' && s[i-1] != 'E' )||i == len-1)
                    return false;
                isSign = true;
            }else{
                return false;
            }

        }
        return true;
}
