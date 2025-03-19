#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


void postOrder(TreeNode* root){
    // 后序遍历
    if(root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

TreeNode* construct(int val,TreeNode *root){
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->left = construct(val, root->left);
    else if(val > root->val) root->right = construct(val, root->right);
    return root;
}

int main(){
    vector<int> nums;
    int temp;
    while(cin >> temp){
        if(temp == 0) break;
        else nums.push_back(temp);
    }
    TreeNode* root = nullptr;
    for(int i = 0; i < nums.size(); i++){
        root = construct(nums[i], root);
    }
    postOrder(root);
}