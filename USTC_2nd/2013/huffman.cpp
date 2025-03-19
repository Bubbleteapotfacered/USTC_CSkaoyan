#include<bits/stdc++.h>

using namespace std;

// 记录输入与哈夫曼编码的对应关系
unordered_map<int, string> umap;


struct TreeNode{
    double val;
    int index;
    TreeNode* left;
    TreeNode* right;
    TreeNode(double val) : val(val), left(nullptr), right(nullptr) {};
};

struct cmp{
    bool operator()(const TreeNode* a, const TreeNode* b){
        return a->val > b->val;
    }
};
void InOrder(string& s,TreeNode* root){
    if(root == nullptr) return;
    // 往左加0
    s += "0";
    InOrder(s, root->left);
    s.pop_back();

    // 叶子节点 记录编码
    if(!root->left && !root->right){
        umap[root->index] = s;
    }
    // 往右加1
    s += "1";
    InOrder(s, root->right);
    s.pop_back();
}
int main(){
    ifstream ifs("7.in");
    ofstream ofs("7.out");

    // 用来记录下标, 即第几个输入的数
    int index = 0;
    
    // 小顶堆
    priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq_min;

    double val;
    while(ifs >> val){
        TreeNode* node = new TreeNode(val);
        // 记录下标
        node->index = index++;
        pq_min.push(node);
    }

    while(pq_min.size() > 1){
        // 选两个最小的
        TreeNode* node_1 = pq_min.top(); pq_min.pop();
        TreeNode* node_2 = pq_min.top(); pq_min.pop();
        // 合成一个新的加入小顶堆
        TreeNode* newnode = new TreeNode(node_1->val + node_2->val);
        newnode->left = node_1;
        newnode->right = node_2;
        pq_min.push(newnode);
    }
    // 剩下一个是根节点
    TreeNode* root = pq_min.top(); pq_min.pop();
    string s = "";
    InOrder(s, root);

    // 根据下标输出对应的编码
    // index的值就是umap中的个数
    for(int i = 0; i < index; i++){
        cout << umap[i] << endl;
        ofs << umap[i] << endl;
    }
     

    ifs.close();
    ofs.close();
}