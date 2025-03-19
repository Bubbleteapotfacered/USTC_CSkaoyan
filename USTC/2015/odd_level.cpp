#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    char l = '0', r = '0';
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(), left(nullptr), right(nullptr) {};
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {};
};

void levelOrder(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    // 本层的节点数量
    int len;
    // count表示层数
    int count = 0;
    while(!que.empty()){
        count++;
        len = que.size();

        if(count % 2 == 1) cout <<  count << "_level: ";
        
        while(len--){
            TreeNode* cur = que.front(); que.pop();
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
            if(count % 2 == 1) cout << cur->val << " ";
        }

        if(count % 2 == 1) cout << endl;
    }
}

int main(){
    ifstream ifs("input_3.txt");
    string s;

    unordered_map<char, TreeNode*> umap;
    while(getline(ifs, s)){
        TreeNode* node = new TreeNode(s[0]);

        if(s.size() == 3){
            if(umap.find(s[2]) == umap.end()) umap[s[2]] = new TreeNode(s[2]);
            node->l = s[2];
        }else if(s.size() == 5){
            if(umap.find(s[2]) == umap.end()) umap[s[2]] = new TreeNode(s[2]);
            if(umap.find(s[4]) == umap.end()) umap[s[4]] = new TreeNode(s[4]);
            node->l = s[2];
            node->r = s[4];
        }
        umap[s[0]] = node;
    }

    for(pair<char,TreeNode*> ele : umap){
        TreeNode* node =  ele.second;
        if(node->l != '0') node->left = umap[node->l];
        if(node->r != '0') node->right = umap[node->r];
    }

    levelOrder(umap['A']);

    ifs.close();


}