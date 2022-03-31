#include<iostream>
#include<unordered_map>

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
//     int count = 0;
//     //����rootΪ���ڵ�Ķ������У�Ѱ�Һ�Ϊsum��·��������������·���ĸ���
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root == NULL) return 0;

//         int res = findPath(root, targetSum);
//         res += pathSum(root->left, targetSum);
//         res += pathSum(root->right, targetSum);

//         return res;



//     }
// private:
//     //����nodeΪ���ڵ�Ķ������У�Ѱ�Ұ���node·��,����·������
//     int findPath(TreeNode* node, int targetSum){
//         if(node == NULL) return 0;
//         int res = 0;

//         if(node->val == targetSum) res += 1;//��ʱ����return����Ϊ�������ܻ�������������ģ������и���

//         res += findPath(node->left, targetSum - node->val);

//         res += findPath(node->right, targetSum - node->val);

//         return res;

//     }
// };

//�Ż���ǰ׺��˼·,
class Solution {
public:

    //����rootΪ���ڵ�Ķ������У�Ѱ�Һ�Ϊsum��·��������������·���ĸ���
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        unordered_map<int, int>hashMap; //<ǰ׺��,����>
        hashMap[0] = 1;//�Լ����Լ��Ľڵ�·���������ڵ�.
        //���ڿ�·������Ҳ��Ҫ����Ԥ�ȴ���һ�£���ʱ��Ϊ��·���������κνڵ㣬�������ǰ׺��Ϊ 0


        int curSum = 0; //��¼�¸��ڵ� root ����ǰ�ڵ� node ��·���ϳ���ǰ�ڵ��������нڵ��ǰ׺��
        return __pathSum(root, targetSum, curSum, hashMap);

    }
private:
    //ע�⣬����unordered_mapʹ�����ô��� &
    //curSum ��¼�¸��ڵ� root ����ǰ�ڵ� node ��·���ϳ���ǰ�ڵ��������нڵ��ǰ׺��
    int __pathSum(TreeNode* node, int targetSum, int curSum, unordered_map<int, int>& hashMap) {
        //
        if (node == NULL) return 0;
        int res = 0;
        curSum += node->val;

        res += hashMap[curSum - targetSum];//���������keyΪcurSum - targetSum��Ĭ��Ϊ�գ�res+0 =res����Ӱ��

        hashMap[curSum] ++;
        res += __pathSum(node->left, targetSum, curSum, hashMap);
        res += __pathSum(node->right, targetSum, curSum, hashMap);
        hashMap[curSum] --;
        return res;
    }

};

int main() {

	system("pause");
	return 0;
}