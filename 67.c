/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-07 19:59:19
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-07 19:59:36
 */

/*
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 

示例 1：

输入:a = "11", b = "1"
输出："100"
示例 2：

输入：a = "1010", b = "1011"
输出："10101"
*/
char* addBinary(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int len = lena>lenb?lena:lenb;
    char *res = (char*)malloc(sizeof(char)*(len+2));
    res[len+1] = '\0';
    int carry = 0;
    int i = lena-1;
    int j = lenb-1;
    int k = len;
    while(i>=0 || j>=0){
        int sum = carry;
        if(i>=0){
            sum += a[i--]-'0';
        }
        if(j>=0){
            sum += b[j--]-'0';
        }
        res[k--] = sum%2+'0';
        carry = sum/2;
    }
    if(carry){
        res[k] = '1';
        return res;
    }
    return res+1;
}