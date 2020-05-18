//
//  main.cpp
//  BiTree
//
//  Created by 费雄君 on 2020/5/7.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
* 二叉搜索树结点
*
* 参数说明：
*     key -- 关键字
*     left -- 左孩子结点地址
*     right -- 右孩子结点地址
*     parent -- 双亲结点地址
*/
struct BiTreeNode {
    int key;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode *parent;
    BiTreeNode(int x) : key(x), left(nullptr), right(nullptr), parent(nullptr) {}       // 初始化结点方案
};
struct BiTree{
    BiTreeNode* root;
    BiTree() : root(nullptr) {}
};

/*
* 插入结点到二叉搜索树
*
* 参数说明：
*     root -- 根节点
*     k -- 待插入关键字
*/
void TreeInsort(BiTree* tree, int k)
{
    // 创建关键字k的结点
    BiTreeNode *root = tree->root;
    BiTreeNode *node = new BiTreeNode(k);
    BiTreeNode *temp = nullptr;
    while (root != nullptr) {
        temp = root;
        if (root->key > k) {
            root = root->left;      // 插入位置在左子树
        }
        else{
            root = root->right;     // 插入位置在右子树
        }
    }
    node->parent = temp;
    if (temp == nullptr) {
        tree->root = node;      //树为空
    }
    else if (node->key < temp->key) {
        temp->left = node;
    }
    else
    {
        temp->right = node;
    }
}

/*
* 中序遍历二叉搜素树
*
* 参数说明：
*     node -- 二叉搜素树根结点
*/
void InorderTreeWalk(BiTreeNode* node)
{
    if (node != nullptr)
    {
        InorderTreeWalk(node->left);
        cout << node->key << "\t";
        InorderTreeWalk(node->right);
    }
}

/*
* 输出二叉搜素树最小值
*
* 参数说明：
*     node -- 二叉搜素树根结点
* 返回值说明：
*     min -- 二叉搜素树值最小根结点
*/
BiTreeNode* Minmum(BiTreeNode* node)
{
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/*
* 输出二叉搜素树最大值
*
* 参数说明：
*     node -- 二叉搜素树根结点
* 返回值说明：
*     max -- 二叉搜素树值最大根结点
*/
BiTreeNode* Maxmum(BiTreeNode* node)
{
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

/*
* 查找关键字为k的结点
*
* 参数说明：
*     node -- 二叉搜素树根结点
*     k -- 待查找关键字
* 返回值说明：
*     node -- 关键字结点
*/
BiTreeNode* TreeSearch(BiTreeNode* node, int k)
{
    while (node != nullptr) {
        if (k == node->key)
        {
            return node;
        }
        else if (k > node->key)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return node;
}

/*
* 返回结点后继
*
* 参数说明：
*     node -- 结点
* 返回值说明：
*     node -- 后继结点
*/
BiTreeNode* TreeSuccessor(BiTreeNode* node)
{
    // 右孩子非空，向下查找
    if (node->right != nullptr)
    {
        return Minmum(node->right);
    }
    // 右孩子为空，向上查找
    BiTreeNode* p_node = node->parent;
    while (p_node != nullptr && node == p_node->right)
    {
        node = p_node;
        p_node = node->parent;
    }
    return p_node;
}

/*
* 返回结点前驱
*
* 参数说明：
*     node -- 结点
* 返回值说明：
*     node -- 前驱结点
*/
BiTreeNode* TreePredecessor(BiTreeNode* node)
{
    // 右孩子非空，向下查找
    if (node->left != nullptr)
    {
        return Maxmum(node->left);
    }
    // 右孩子为空，向上查找
    BiTreeNode* p_node = node->parent;
    while (p_node != nullptr && node == p_node->left)
    {
        node = p_node;
        p_node = node->parent;
    }
    return p_node;
}

/*
* 删除关键字为k的结点
*
* 参数说明：
*     tree -- 二叉搜索树
*     node -- 待删除结点
*
*/
void TreeDelete(BiTree* tree, BiTreeNode* node)
{
    
}

int main(int argc, const char * argv[]) {
    // 创建BiTree
    vector<int> vec1{3, 5, 2, 6, 8, 1, 9};
    BiTree* tree = new BiTree();
    for (int i = 0; i < vec1.size(); i++) {
        TreeInsort(tree, vec1[i]);
    }
    // 中序遍历BiTree
    InorderTreeWalk(tree->root);
    cout << endl;
    
    // 获取BiTree最大，最小结点
    BiTreeNode* min = Minmum(tree->root);
    BiTreeNode* max = Maxmum(tree->root);
    cout << min->key << "\t" << max->key << endl;
    
    // 查找关键字结点k
    int k = 4;
    BiTreeNode* pos = TreeSearch(tree->root, k);
    if (pos != nullptr)
    {
        cout << pos->key << endl;
    }
    else
    {
        cout  << "there is no " << k << " in the tree!" << endl;
    }
    
    // 删除关键字结点k
    
    
    return 0;
}
