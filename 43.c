/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-03-23 12:10:55
 * @LastEditors: zhc
 * @LastEditTime: 2024-03-23 19:56:25
 */
/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。



示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *multiply(char *num1, char *num2)
{
    if(num1[0] == '0' || num2[0] == '0')
    {
        char *res = (char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    char *res = (char *)malloc(sizeof(char) * (len+1));
    memset(res, '0', sizeof(char) * (len+1));
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            res[i + j + 1] = (temp % 10) + '0';
            res[i + j] = (res[i + j] - '0' + temp / 10) + '0';
        }
    }
    // printf("%s++\n", res);
    while(*res == '0')
    {
        res++;
        len--;
    }
    res[len] = '\0';
    return res;
}
int main()
{
    char *num1 = "5";
    char *num2 = "12";
    char *res = multiply(num1, num2);
    // printf("%d\n", strlen(res));
    for (int i = 0; i < strlen(res); i++)
    {
        printf("%c", res[i]);
    }
    return 0;
}