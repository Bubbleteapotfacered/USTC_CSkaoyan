#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    int left_child_sum = 0;
    int right_child_sum = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
};

TreeNode* buildTree(int val, TreeNode* root){
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->left = buildTree(val, root->left);
    if(val > root->val) root->right = buildTree(val, root->right);
    return root;
}
// 中序序列验证二叉排序树
// void InOrder(TreeNode* root){
//     if(root == nullptr) return;
//     InOrder(root->left);
//     cout << root->val << " ";
//     InOrder(root->right);
// }

int calculate_child_sum(TreeNode* root){
    if(root == nullptr) return 0;
    // 记录左子树到根节点的最大累计和
    root->left_child_sum = calculate_child_sum(root->left);
    // 记录右子树到根节点的最大累计和
    root->right_child_sum = calculate_child_sum(root->right);
    // 返回本子树到根节点的最大累计和
    return max(root->left_child_sum, root->right_child_sum) + root->val;
}
int max_val = 0;

void search(TreeNode *root){
    if(root == nullptr) return ;
    // 扫描每个节点
    // 左子树到根节点的累计和  右子树到根节点的累计和
    // 因为要经过自己，所以加上自己的val
    max_val = max(max_val, root->left_child_sum + root->right_child_sum + root->val);
    search(root->left);
    search(root->right);
}

int main(){
    ifstream ifs("tree.in");
    vector<int> node_vals;
    int val;
    TreeNode* root = nullptr;
    // 二叉排序树是从上往下开始构造的  而层序遍历正好也是从上往下开始扫描的
    // 用二叉排序树的层序遍历 来 递归构造新的二叉排序树, 得到的新二叉排序树和原来的一样
    // 它会找到自己的位置
    while(ifs >> val){
        root = buildTree(val, root);
    }
    // InOrder(root);
    calculate_child_sum(root);
    search(root);
    cout << max_val;

    ifs.close();
}
