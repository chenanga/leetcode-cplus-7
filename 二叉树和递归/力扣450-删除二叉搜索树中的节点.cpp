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

class Solution {
public:
    //删除节点 root 中的一个值 key
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val < key) {
            TreeNode* rightNode = deleteNode(root->right, key);
            root->right = rightNode;
            return root;
        }
        else if (root->val > key) {
            TreeNode* leftNode = deleteNode(root->left, key);
            root->left = leftNode;
            return root;
        }
        else { //root->val == key
            if (root->left == NULL) {
                TreeNode* rightNode = root->right;
                delete root;
                return rightNode;
            }
            if (root->right == NULL) {
                TreeNode* leftNode = root->left;
                delete root;
                return leftNode;
            }

            //两个子孩子节点都存在，此时需要用Hibbard删除法，找到右子树的最小值，复制一份，删除它，然后替代待删除节点
            TreeNode* succ = new TreeNode(findMinNode(root->right)->val);

            succ->right = deleteMinNode(root->right);
            succ->left = root->left;
            delete root;
            return succ;
        }



        return root;
    }
private:
    TreeNode* findMinNode(TreeNode* root) {
        //找到以root为根节点的，最小节点，返回该节点
        if (root == NULL)
            return NULL;
        if (root->left == NULL) //只要左子树为空，不管右子树有没有值，都无所谓
            return root;
        return findMinNode(root->left);
    }
    TreeNode* deleteMinNode(TreeNode* root) {
        //删除以root为根节点中的最小节点，

        if (root->left == NULL) {
            TreeNode* rightNode = root->right;//此时如果right为空也没啥，相当于直接返回了null
            delete root;
            return rightNode;
        }
        //关键
        root->left = deleteMinNode(root->left);
        return root;

    }

};
////简化部分版本
// class Solution {
// public:
//     //删除节点 root 中的一个值 key
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) 
//             return NULL;
//         if(root->val < key){
//             TreeNode* rightNode = deleteNode(root->right, key);
//             root->right = rightNode;
//             return root;
//         }
//         else if(root->val > key){
//             TreeNode* leftNode = deleteNode(root->left, key);
//             root->left = leftNode;
//             return root;
//         }
//         else{ //root->val == key
//             if(root->left == NULL){
//                 TreeNode* rightNode = root->right;
//                 delete root;
//                 return rightNode;
//             }
//             if(root->right == NULL){
//                 TreeNode* leftNode = root->left;
//                 delete root;
//                 return leftNode;
//             }

//             //两个子孩子节点都存在，此时需要用Hibbard删除法，找到右子树的最小值，复制一份，删除它，然后替代待删除节点
//             succ->right = deleteMinNode(root->right); //删除之前创建一个新的替代
//             succ->left = root->left;
//             delete root;
//             return succ;
//         }

//         return root;
//     }
// private:
//     TreeNode* succ;
//     TreeNode* deleteMinNode(TreeNode* root){
//         //删除以root为根节点中的最小节点，

//         if(root->left == NULL){
//             TreeNode* rightNode = root->right;//此时如果right为空也没啥，相当于直接返回了null
//             succ = new TreeNode(root->val);
//             delete root;
//             return rightNode;
//         }
//         //关键
//         root->left = deleteMinNode(root->left);
//         return root;

//     }

// };
int main() {

	system("pause");
	return 0;
}