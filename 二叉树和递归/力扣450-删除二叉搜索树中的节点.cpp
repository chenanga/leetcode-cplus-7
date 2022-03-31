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
    //ɾ���ڵ� root �е�һ��ֵ key
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

            //�����Ӻ��ӽڵ㶼���ڣ���ʱ��Ҫ��Hibbardɾ�������ҵ�����������Сֵ������һ�ݣ�ɾ������Ȼ�������ɾ���ڵ�
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
        //�ҵ���rootΪ���ڵ�ģ���С�ڵ㣬���ظýڵ�
        if (root == NULL)
            return NULL;
        if (root->left == NULL) //ֻҪ������Ϊ�գ�������������û��ֵ��������ν
            return root;
        return findMinNode(root->left);
    }
    TreeNode* deleteMinNode(TreeNode* root) {
        //ɾ����rootΪ���ڵ��е���С�ڵ㣬

        if (root->left == NULL) {
            TreeNode* rightNode = root->right;//��ʱ���rightΪ��Ҳûɶ���൱��ֱ�ӷ�����null
            delete root;
            return rightNode;
        }
        //�ؼ�
        root->left = deleteMinNode(root->left);
        return root;

    }

};
////�򻯲��ְ汾
// class Solution {
// public:
//     //ɾ���ڵ� root �е�һ��ֵ key
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

//             //�����Ӻ��ӽڵ㶼���ڣ���ʱ��Ҫ��Hibbardɾ�������ҵ�����������Сֵ������һ�ݣ�ɾ������Ȼ�������ɾ���ڵ�
//             succ->right = deleteMinNode(root->right); //ɾ��֮ǰ����һ���µ����
//             succ->left = root->left;
//             delete root;
//             return succ;
//         }

//         return root;
//     }
// private:
//     TreeNode* succ;
//     TreeNode* deleteMinNode(TreeNode* root){
//         //ɾ����rootΪ���ڵ��е���С�ڵ㣬

//         if(root->left == NULL){
//             TreeNode* rightNode = root->right;//��ʱ���rightΪ��Ҳûɶ���൱��ֱ�ӷ�����null
//             succ = new TreeNode(root->val);
//             delete root;
//             return rightNode;
//         }
//         //�ؼ�
//         root->left = deleteMinNode(root->left);
//         return root;

//     }

// };
int main() {

	system("pause");
	return 0;
}