#include<bits/stdc++.h>

using namespace std;

ofstream ofs("4.out");

struct TreeNode {
    int val;
    int lchild = 0;
    int rchild = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val) : val(val), left(nullptr), right(nullptr) {};
};
TreeNode* build(int parent, int lchild, int rchild){
    TreeNode* node = new TreeNode(parent);
    node->lchild = lchild;
    node->rchild = rchild;
    return node;
}
void PostOrder(TreeNode* root){
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    ofs << root->val << " ";
    cout << root->val << " ";
}
int main(){
    ifstream ifs("4.txt");
    int n;
    ifs >> n;
    int parent, lchild, rchild;
    vector<TreeNode*> nodes;
    nodes.push_back(nullptr);
    for(int i = 1; i <= n; i++){
        ifs >> parent >> lchild >> rchild;
        nodes.push_back(build(parent, lchild, rchild));
    }
    for(int i = 1; i <= n; i++){
        nodes[i]->left = nodes[nodes[i]->lchild];
        nodes[i]->right = nodes[nodes[i]->rchild];
    }
    PostOrder(nodes[1]);
    ofs.close();
}