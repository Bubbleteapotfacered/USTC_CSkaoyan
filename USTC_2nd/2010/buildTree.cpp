#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};
// 构建二叉排序树
TreeNode* buildTree(TreeNode* root, int val){
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->left = buildTree(root->left, val);
    else if(val > root->val) root->right = buildTree(root->right, val);
    return root;
}
// 后续遍历
void PostOrder(TreeNode* root){
    if(root == nullptr) return;
    PostOrder(root->left);

    PostOrder(root->right);
    cout << root->val << " ";
}
int main(){
    int num;
    vector<int> nums;
    TreeNode* root = nullptr;
    while(cin >> num){
        if(num == 0) break;
        else root = buildTree(root, num);
    }
    PostOrder(root);
}