#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val, lval, rval;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int val) : val(val), lchild(nullptr), rchild(nullptr){} ;
};

// 构建二叉排序树
TreeNode* buildTree(TreeNode* root, int val){
    if(root == nullptr) return new TreeNode(val);
    else if(root->val < val) root->rchild = buildTree(root->rchild, val);
    else if(root->val > val) root->lchild = buildTree(root->lchild, val);
    return root;
}

// 寻找叶子节点到叶子节点最大值
int res = 0;
int travel(TreeNode* root){
    // 返回值是root到根节点的最大值
    
    // 叶子节点，返回0
    if(root == NULL) return 0;
    // 左子树到叶子的最大和
    int left = travel(root->lchild);
    // 右子树到叶子的最大和
    int right = travel(root->rchild);

    // 记录根节点到叶子的最大和
    res = max(res, left + right + root->val);
    // 返回根节点到叶子的最大和
    // root->val为根节点的值，max(left,right)为左右子树到根节点的最大值
    return root->val + max(left, right);
}
int main(){
    // 构建二叉排序树
    TreeNode* root  = nullptr;
    ifstream ifs("tree.in");
    int num;
    while(ifs >> num){
        root = buildTree(root, num);
    }
    travel(root);
    cout << res;
    ifs.close();
}