/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-07 19:43:43
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-07 19:43:49
 */
/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

 

示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]
 
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    for(i=digitsSize-1;i>=0;i--){
        if(digits[i]!=9){
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    int *res=(int*)malloc(sizeof(int)*(digitsSize+1));
    res[0]=1;
    for(i=1;i<=digitsSize;i++){
        res[i]=0;
    }
    *returnSize=digitsSize+1;
    return res;
}