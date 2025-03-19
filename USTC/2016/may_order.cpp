#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val = '0';
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
};
TreeNode* buildTree(vector<char>& pre, vector<char>& post, int pre_left, int pre_right, int post_left, int post_right){
    // 需要保证pre[pre_left] = post[post_right]
    if(pre_left == pre_right) return new TreeNode(pre[pre_left]);
    if(pre_left > pre_right || pre_left >= pre.size() || pre_right < 0) return nullptr;
    if(post_left > post_right || post_left >= pre.size() || post_right < 0) return nullptr;
    TreeNode* node = new TreeNode(pre[pre_left]);
    int i;
    for(i = 0; i < post_right; i++){
        if(pre[pre_left + 1] == post[post_left + i]) break;
    }
    node->left = buildTree(pre, post, pre_left + 1, pre_left + 1 + i, post_left, post_left + i);
    node->right = buildTree(pre, post, pre_left + i + 2, pre_right, post_left + i + 1, post_right - 1);
    return node;
}
vector<char> res;
void InOrder(TreeNode* root){
    if(root == nullptr) return ;
    InOrder(root->left);

    cout << root->val << " ";
    res.push_back(root->val);

    InOrder(root->right);
}
int main(){
    ifstream ifs("4.in");
    ofstream ofs("4.out");
    int n;
    ifs >> n;
    vector<char> PreOrder;
    vector<char> PostOrder;
    
    char c;
    for(int i = 1; i <= n; i++){
        ifs >> c;
        PreOrder.push_back(c);
    }
    for(int i = 1; i <= n; i++){
        ifs >> c;
        PostOrder.push_back(c);
    }

    TreeNode* root = buildTree(PreOrder, PostOrder, 0, n - 1, 0, n - 1);
    InOrder(root);
    for(int i = 0 ; i < res.size(); i++){
        if(i != 0) ofs << " ";
        ofs << res[i];
        
    }

    ifs.close();
    ofs.close();

}