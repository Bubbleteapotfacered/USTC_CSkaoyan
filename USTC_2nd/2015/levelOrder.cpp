#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    char left_val = '0', right_val = '0';
    TreeNode *left, *right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {};
    
};
ofstream ofs("output_3.txt");
void levelOrder(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    while(!que.empty()){
        depth++;
        int len = que.size();
        if(depth % 2 == 1) cout << depth << "level: " ;
        while(len--){
            TreeNode* cur = que.front(); que.pop();
            if(depth % 2 == 1) {
                cout << cur->val << " ";
                ofs << cur->val << " ";
            }
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        if(depth % 2 == 1) cout <<  endl;
    }
}

int main(){
    ifstream ifs("input_3.txt");


    string s;
    // 用来记录节点下标和TreeNode的对应关系
    unordered_map<char,TreeNode*>  umap;
    umap['0'] = nullptr;
    while(getline(ifs, s)){
        TreeNode* node = new TreeNode(s[0]);
        if(s.size() == 3){
            char left_val = s[2];
            node->left_val = left_val;
            // 如果本来不存在
            if(umap.find(s[2]) == umap.end()){
                TreeNode* lchild = new TreeNode(left_val);
                umap[s[2]] = lchild;
            }
        }else if(s.size() == 5){
            char left_val = s[2];
            char right_val = s[4];
            node->left_val = left_val;
            node->right_val = right_val;
            if(umap.find(s[2]) == umap.end()){
                TreeNode* lchild = new TreeNode(left_val);
                umap[s[2]] = lchild;
            }
            if(umap.find(s[4]) == umap.end()){
                TreeNode* rchild = new TreeNode(right_val);
                umap[s[4]] = rchild;
            }
        }
        umap[s[0]] = node;
    }
    for(pair<char, TreeNode*> ele : umap){
        // 注意second不能为nullptr  不然会报错
        if(ele.first == '0') continue;
        TreeNode* node = ele.second;
        node->left = umap[node->left_val];
        node->right = umap[node->right_val];
    }

    levelOrder(umap['A']);
    ifs.close();
    ofs.close();
}