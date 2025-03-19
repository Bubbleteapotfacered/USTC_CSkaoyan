#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    int left_val;
    int right_val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};
ofstream ofs("4.out");
// 后序遍历
void PostOrder(TreeNode* root){
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
    ofs << root->val << " ";
}

int main(){
    ifstream ifs("4.txt");

    int n;
    ifs >> n;
    // 存放各个顶点的指针
    vector<TreeNode*> Nodes;
    // 0表示nullptr
    Nodes.push_back(nullptr);

    int val, left_val, right_val;

    // 用来寻找根节点的下标
    int root = 0;
    vector<bool> ischild(n + 1, false);

    for(int i = 0; i < n; i++){
        ifs >> val >> left_val >> right_val;
        TreeNode* Node = new TreeNode(val);
        // 记录节点左右孩子的下标
        Node->left_val = left_val;
        Node->right_val = right_val;
        Nodes.push_back(Node);

        // left_val和right_val下标对应的节点是别人的孩子，标记为true
        ischild[left_val] = true;
        ischild[right_val] = true;
    }
    // 将每个节点连接起来
    for(int i = 1; i <= n; i++){
        Nodes[i]->left = Nodes[Nodes[i]->left_val];
        Nodes[i]->right = Nodes[Nodes[i]->right_val];
    }

    // 寻找根节点的下标
    for(int i = 1; i <= n; i++){
        // 根节点不是任何一个节点的孩子
        if(!ischild[i]){
            root = i;
            break;
        }
    }
    // 后续遍历
    PostOrder(Nodes[root]);
    ifs.close();
    ofs.close();
}