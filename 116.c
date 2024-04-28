/*
 * @Descripttion: Leetcode_code
 * @version: 1.0
 * @Author: zhc
 * @Date: 2024-04-28 12:33:40
 * @LastEditors: zhc
 * @LastEditTime: 2024-04-28 12:34:04
 */
/*
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

示例 1：



输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
示例 2:

输入：root = []
输出：[]
 
*/
#include <stdlib.h>
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
struct Node* connect(struct Node* root) {
    if(root==NULL)
        return NULL;
    struct Node* leftmost = root;
    while(leftmost->left!=NULL){
        struct Node* head = leftmost;
        while(head!=NULL){
            head->left->next = head->right;
            if(head->next!=NULL){
                head->right->next = head->next->left;
            }
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}