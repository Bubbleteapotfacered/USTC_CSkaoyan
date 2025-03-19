#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    char c;
    TreeNode* left;
    TreeNode* right;
    // TreeNode() : c(), left(nullptr), right(nullptr) {} ;
    TreeNode(char c) : c(c), left(nullptr), right(nullptr) {} ;
};
// 求二叉树的高度
int h = 0;

// 通过先序序列构造二叉树
TreeNode* buildTree(string& s, int& cur){
    if(cur >= s.size()) return nullptr;
    if(s[cur] == '0') {
        cur++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(s[cur]);
    cur++;
    node->left = buildTree(s, cur);
    node->right = buildTree(s, cur);
    return node;
}
// 先序遍历求高度
void PreOrder(TreeNode* root, int depth){
    if(root == nullptr) { 
        return;
    }
    // 得到高度
    h = max(depth, h);
    PreOrder(root->left, depth + 1);
    PreOrder(root->right, depth + 1);
}
// 中序遍历输出
void InOrder(TreeNode* root, int depth){
    if(root == nullptr) return;
    InOrder(root->left, depth + 1);
    if(depth <= h / 2) cout << root->c << " ";
    InOrder(root->right, depth + 1);
}


int main(){
    ifstream ifs("tree.in");
    string s;
    ifs >> s;

    int cur  = 0;
    // 构造二叉树
    TreeNode* root = buildTree(s, cur);
    // 求深度
    int depth = 1;
    PreOrder(root, depth);
    // 中序输出
    InOrder(root, depth);

    ifs.close();
    return 0;
}