#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> res;
//         if(root == NULL) return res;
//         if(root->left == NULL && root->right == NULL && root->val == targetSum){
//             res.push_back({root->val});
//             return res;
//         }

//         vector<vector<int>>leftVec = pathSum(root->left, targetSum - root->val);
//         for(int i = 0; i < leftVec.size(); i ++){
//             leftVec[i].insert(leftVec[i].begin(),root->val);
//             res.push_back(leftVec[i]);
//         }

//         vector<vector<int>>rightVec = pathSum(root->right, targetSum - root->val);
//         for(int i = 0; i < rightVec.size(); i ++){
//             rightVec[i].insert(rightVec[i].begin(),root->val);
//             res.push_back(rightVec[i]);
//         }
//         return res;

//     }
// };

// //vector头插慢，使用queue,并没有快太多
// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        vector<deque<int>> temp = __pathSum(root, targetSum);
//        vector<vector<int>> res;
//        for(int i = 0; i < temp.size(); i++){
//            vector<int> t(temp[i].begin(), temp[i].end());
//            res.push_back(t);
//        }
//        return res;
//     }

// private:
//     vector<deque<int>> __pathSum(TreeNode* root, int targetSum) {
//         vector<deque<int>> res;
//         if(root == NULL) return res;
//         if(root->left == NULL && root->right == NULL && root->val == targetSum){
//             res.push_back({root->val});
//             return res;
//         }

//         vector<deque<int>>leftVec = __pathSum(root->left, targetSum - root->val);
//         for(int i = 0; i < leftVec.size(); i ++){
//             leftVec[i].push_front(root->val);
//             res.push_back(leftVec[i]);
//         }

//         vector<deque<int>>rightVec = __pathSum(root->right, targetSum - root->val);
//         for(int i = 0; i < rightVec.size(); i ++){
//             rightVec[i].push_front(root->val);
//             res.push_back(rightVec[i]);
//         }
//         return res;

//     }
// };

//大神回溯版本,基于大神版本更改
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        dfs(root, targetSum, 0);
        return res;
    }
    vector<int> path; //会自动回溯
    vector<vector<int>> res;
    void dfs(TreeNode* root, int targetSum, int sum)
    {
        if (root == NULL) return;
        path.emplace_back(root->val);
        sum += root->val;
        if (root->left == NULL && root->right == NULL && sum == targetSum) {
            res.emplace_back(path);
            path.pop_back();
            return;  //这边如果要return 就要多写这行。
        }
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        path.pop_back();

    }
};

int main() {

    system("pause");
    return 0;
}