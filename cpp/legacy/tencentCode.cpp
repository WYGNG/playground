#include <iostream>
#include <string>

using namespace std;

int main() {
	int len = 0;
	string strNum;
	cin >> len >> strNum;
	


	bool done = false;

	while (!done) {
		int i = 0;
		for (i = 0; i + 1 < strNum.size(); i++) {
			if ((strNum[i] - '0') + (strNum[i + 1] - '0') == 10) {
				strNum.erase(i, 2);
				break;
			}
		}
		cout << i << " " << strNum << strNum.size();
		if (strNum.empty()) {
			break;
		}
		if (i > strNum.size() - 2) {
			done = true;
		}

	}

	cout << strNum.size() << ' ' << strNum << endl;

	system("pause");



	return 0;
}



/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

//class Solution {
//public:
//	/**
//	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	 * ����Ҫ����һ��ָ�룬ָ��root����ʾɾ��ȥ���ɸ����ʣ�µ���
//	 * @param root TreeNode�� ָ��������ĸ�
//	 * @return TreeNode��
//	 */
//	TreeNode* solve(TreeNode* root) {
//		// write code here
//		cutTree(root, fullTreeLevel(root));
//		return root;
//	}
//
//	void cutTree(TreeNode* root, int level) {
//		if (level <= 1) {
//			//            delete root->left;
//			//            root->left = nullptr;
//			//            delete root->right;
//			//            root->right = nullptr;
//			//            freeTree(root->left);
//			//            freeTree(root->right);
//			freeTree(root);
//		}
//		else {
//			cutTree(root->left, level - 1);
//			cutTree(root->right, level - 1);
//		}
//	}
//
//	void freeTree(TreeNode* root) {
//		if (root == nullptr) return;
//		if (root->left == nullptr && root->right == nullptr) return;
//		if (root->left != nullptr) {
//			if (root->left->left == nullptr && root->left->right == nullptr) {
//				delete root->left;
//				root->left = nullptr;
//			}
//			else {
//				freeTree(root->left);
//				delete root->left;
//				root->left = nullptr;
//			}
//		}
//		if (root->right != nullptr) {
//			if (root->right->left == nullptr && root->right->right == nullptr) {
//				delete root->right;
//				root->right = nullptr;
//			}
//			else {
//				freeTree(root->right);
//				delete root->right;
//				root->right = nullptr;
//			}
//		}
//	}
//
//	int fullTreeLevel(TreeNode* root) {
//		if (root == nullptr) return 0;
//		if (root->left == nullptr || root->right == nullptr) {
//			return 1;
//		}
//		return min(fullTreeLevel(root->left), fullTreeLevel(root->right)) + 1;
//	}
//
//};