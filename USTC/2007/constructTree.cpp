#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(), left(nullptr), right(nullptr) {};
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* constructed(TreeNode* root, vector<char>& inorder, vector<char>& postorder){
    if(inorder.size() == 0) return nullptr;
    int val = postorder[postorder.size() - 1];
    if(root == nullptr) root = new TreeNode(val);
    int index = 0;
    for(;index < inorder.size(); index++){
        // 找到根节点的值
        if(inorder[index] == val) break;
    }
    vector<char> left_in(inorder.begin(), inorder.begin() + index);
    vector<char> right_in(inorder.begin() + index + 1, inorder.end());
    vector<char> left_post(postorder.begin(), postorder.begin() + index);
    vector<char> right_post(postorder.begin() + index, postorder.end() - 1);

    root->left = constructed(root->left, left_in, left_post);
    root->right = constructed(root->right, right_in, right_post);
    return root;

}
void PreOrder(TreeNode* root, ofstream& ofs){
    if(root == nullptr) return ;
    ofs << root->val << " ";
    PreOrder(root->left, ofs);
    PreOrder(root->right, ofs);
}


int main(){
    ifstream ifs("4.in");
    ofstream ofs("4.out");
    int n;
    ifs >> n;
    vector<char> inorder;
    vector<char> postorder;
    char s;

    for(int i = 0; i < n; i++){
        ifs >> s;
        inorder.push_back(s);
    }
    for(int i = 0; i < n; i++){
        ifs >> s;
        postorder.push_back(s);
    }

    TreeNode *root = nullptr;
    root = constructed(root, inorder, postorder);
    PreOrder(root, ofs);

    ifs.close();
    ofs.close();

}