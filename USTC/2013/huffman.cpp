#include<bits/stdc++.h>

using namespace std;


// 优先队列有三个参数，声明形式如下
// priority_queue< type, container, function >
// type: 数据类型
// container: 实现优先队列的底层容器
// function: 元素之间的比较方式

struct TreeNode{
    // 记录频率
    float val;
    // 记录下标
    int index;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(float val) : val(val), left(nullptr), right(nullptr) {};
};

struct cmp{
public:
    bool operator()(TreeNode* a, TreeNode* b){
        return a->val > b->val;
    }
};

// 用来存放huffman编码
string path = "";
// 用来存放i和huffman的对应关系
unordered_map<int, string> umap;

void InOrder(TreeNode* root){
    if(root == nullptr) return;

    if(!root->left && !root->right){
        // 叶子节点
        // 收集结果
        umap[root->index] = path;
        return ;
    }
    // 回溯
    // 往左走记录为0
    path.push_back('0');
    InOrder(root->left);
    path.pop_back();
    // 往右走记录为1
    path.push_back('1');
    InOrder(root->right);
    path.pop_back();
}

int main(){
    ifstream ifs("7.in");
    ofstream ofs("7.out");
    
    // 小顶堆
    priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq_min;

    float num;
    int index = 0;
    while(ifs >> num){
        // 存入小顶堆
        TreeNode* t = new TreeNode(num);
        t->index = index++;
        pq_min.push(t);
    }

    // 取两个最小，合并再加入
    while(pq_min.size() >= 2){
        TreeNode* l = pq_min.top(); pq_min.pop();
        TreeNode* r = pq_min.top(); pq_min.pop();
        TreeNode* node  = new TreeNode(l->val + r->val);
        node->left = l;
        node->right = r;
        pq_min.push(node);
    }

    // 最后一个是根节点
    TreeNode* root = pq_min.top();pq_min.pop();

    InOrder(root);

    for(int i = 0; i < umap.size(); i++){
        ofs << umap[i] << endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}