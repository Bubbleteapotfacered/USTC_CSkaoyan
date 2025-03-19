#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
};
int depth = 1;
void PreOrder(TreeNode* root, int d){
    // 计算高度
    if(root == nullptr) return ;
    depth = max(depth, d);
    PreOrder(root->left, d + 1);
    PreOrder(root->right, d + 1);
}
void InOrder(TreeNode* root, int depth, int d){
    // 中序遍历
    if(root == nullptr) return;
    InOrder(root->left, depth, d + 1);
    if(d <= depth / 2) cout << root->val << " ";
    InOrder(root->right, depth, d + 1);
}
TreeNode* buildTree(int& index, string& s){
    // 构造树
    // 叶子节点
    if(index >= s.size() || s[index] == '0') {
        index++;
        return nullptr;
    }
    // 非叶子节点
    TreeNode* node = new TreeNode(s[index]);
    index++;

    node->left = buildTree(index, s);
    node->right = buildTree(index, s);
    return node;
}


int main(){
    ifstream ifs("tree.in");
    string s;
    ifs >> s;
    int index = 0;
    
    TreeNode* root = buildTree(index, s);

    int d = 1;
    PreOrder(root, d);
    InOrder(root, depth, d);
    ifs.close();
}