#include<bits/stdc++.h>

using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(vector<char>& Pre,vector<char>& Post){
    if(Pre.size() == 0) return nullptr;
    if(Pre.size() == 1) return new TreeNode(Pre[0]);

    char root_val = Pre[0];
    TreeNode* node = new TreeNode(root_val);
    // Pre[1]是左边第一个
    int index = 0;
    for(; index < Post.size() - 1; index++){
        if(Post[index] == Pre[1]) break;
    }
    // 左边
    vector<char> Pre_left(Pre.begin() + 1, Pre.begin() + index + 2);
    vector<char> Pre_right(Pre.begin() + index + 2, Pre.end());
    vector<char> Post_left(Post.begin(), Post.begin() + index + 1);
    vector<char> Post_right(Post.begin() + index + 1, Post.end() - 1);
    node->left = buildTree(Pre_left, Post_left);
    node->right = buildTree(Pre_right, Post_right);
    
    return node;
}
ofstream ofs("4.out");
void InOrder(TreeNode* root){
    if(root == nullptr) return;
    InOrder(root->left);
    cout << root->val << " ";
    ofs << root->val << " ";
    InOrder(root->right);
}


int main(){
    ifstream ifs("4.in");


    int n;
    ifs >> n;
    vector<char> Pre(n, 'A');
    vector<char> Post(n, 'A');
    for(int i = 0; i < n; i++){
        ifs >> Pre[i];
    }
    for(int i = 0; i < n; i++){
        ifs >> Post[i];
    }

    TreeNode* root = buildTree(Pre, Post);
    InOrder(root);

    ifs.close();
    ofs.close();
}