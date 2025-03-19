#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
};

// 递归构造二叉树
TreeNode* buildTree(TreeNode* root, vector<char>& in, vector<char>& post){
    if(in.size() == 0) return nullptr;
    if(in.size() == 1) return new TreeNode(in[0]);
    char val = post[post.size() - 1];

    TreeNode* node = new TreeNode(val);
    int index;
// 找到根节点在中序的位置
    for(index = 0; index < in.size(); index++){
        if(in[index] == val) break;
    }
    // 根据根节点划分左右子树
    vector<char> in_left(in.begin(), in.begin() + index);
    vector<char> in_right(in.begin() + index + 1, in.end());
    vector<char> post_left(post.begin(),post.begin() + index);
    vector<char> post_right(post.begin() + index, post.end() - 1);
// 递归构造
    node->left = buildTree(node->left, in_left, post_left);
    node->right = buildTree(node->right, in_right, post_right);

    return node;
    
}
ofstream ofs("4.out");
// 先序遍历
void PreOrder(TreeNode* root){
    if(root == nullptr) return;
    
    cout << root->val << " ";
    ofs << root->val << " ";

    PreOrder(root->left);
    PreOrder(root->right);
}

int main(){
    ifstream ifs("4.in");
    int n;
    ifs >> n;

    vector<char> in(n, ' ');
    vector<char> post(n, ' ');
    for(int i = 0; i < n; i++) ifs >> in[i];
    for(int i = 0; i < n; i++) ifs >> post[i];
    TreeNode* root = nullptr;

    root = buildTree(root, in, post);
    PreOrder(root);

    ifs.close();
    ofs.close();
}