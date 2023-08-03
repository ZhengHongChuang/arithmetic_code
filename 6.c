/*
 * @Descripttion: Leetcode_code6
 * @version: 1.0
 * @Author: zhc
 * @Date: 2023-08-02 22:39:03
 * @LastEditors: zhc
 * @LastEditTime: 2023-08-04 02:20:14
 */

/*
将一个给定字符串 s 根据给定的行数 numRows ，
以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，
排列如下：
P   A   H   N
A P L S I I G
Y   I   R
示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
*/
//二维数组
char * convert1(char * s, int numRows){
    int n = strlen(s);

    if(numRows==1||numRows>n){
        return s;
    }
    int t = 2*numRows-2;
    //(n+t-1)--->向上取整
    int c = (n+t-1)/t*(numRows-1);
    char ** dp = (char**)malloc(sizeof(char *)*numRows);
    for(int i =0;i<numRows;i++){
        dp[i] = (char*)malloc(sizeof(char)*c);
        memset(dp[i],0,sizeof(char)*c);
    }
    for (int i = 0, x = 0, y = 0; i < n; i++) {
        dp[x][y] = s[i];
        if (i % t < numRows - 1) {
            x++; 
        } else {
            x--;
            y++; 
        }
    }
    int pos = 0;
    for(int i = 0;i<numRows;i++){
        for(int j=0;j<c;j++){
            if(dp[i][j]){
                s[pos++]=dp[i][j];
            }
        }
        free(dp[i]);
    }
    free(dp);
    return s;


}
char * convert2(char * s, int numRows)
{
    int len = strlen(s);
    if(len == 1 || numRows == 1)
    {
        return s;
    }

    char *res = (char *)malloc(sizeof(char)* (len + 1));
    int k = 2*numRows-2;

    int ops = 0;
    for(int i = 0; i<numRows ; i++)
    {
        for(int j = 0; j<len ; j++)
        {
            //j%k==i-->竖行数值，j%k==k-i-->左上角上面的数值
            if(j%k == i || j%k == k-i)
            {
                res[ops++] = s[j];
            }
        }
    }
    res[len] = '\0';
    return res;
}
