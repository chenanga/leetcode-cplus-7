#include<iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//  //参考257题，去掉中间的->的符号，然后把最后得到的字符串相加
// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         vector<string> res = __dfs(root);
//         int sum = 0;
//         for(int i = 0 ; i < res.size(); i ++){
//             sum += atoi(res[i].c_str());
//         }
// 	    return sum;
//     }

// private:
//     vector<string> __dfs(TreeNode* root){
//         vector<string> res;
//         if(root == NULL) return res;
//         if(root->left == NULL && root->right == NULL){
//             res.push_back(to_string(root->val));
//             return res;
//         }

//         vector<string> leftStr = __dfs(root->left);
//         for(int i = 0 ; i < leftStr.size(); i ++)
//             res.push_back(to_string(root->val)  + leftStr[i]);

//         vector<string> rightStr = __dfs(root->right);
//         for(int i = 0 ; i < rightStr.size(); i ++)
//             res.push_back(to_string(root->val)  + rightStr[i]);

//         return res;
//     }
// };

//优化方案，直接递归，不使用辅助数组
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        return __dfs(root, 0);
    }

private:
    int __dfs(TreeNode* root, int prevSum) {
        //计算根节点到当前节点的和，
        if (root == NULL) return 0;
        int sum = prevSum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return sum;
        return __dfs(root->left, sum) + __dfs(root->right, sum);


    }
};

int main() {

    system("pause");
    return 0;
}