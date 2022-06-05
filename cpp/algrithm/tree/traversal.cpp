#include "tree.h"


class Solution {
public:
//先序非递归
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        if (root == nullptr) return ret;
        stk.push(root);
        while (!stk.empty()) {
            auto p = stk.top();
            ret.push_back(p->val);
            stk.pop();
            if (p->right) stk.push(p->right);
            if (p->left) stk.push(p->left);
        }
        return ret;
    }
//先序递归
    void perdfs(TreeNode* r, vector<int>& a) {
        a.push_back(r->val);
        if (r->left) perdfs(r->left, a);
        if (r->right) perdfs(r->right, a);
    }

    vector<int> preorder(TreeNode* root) {
        vector<int> ret;
        perdfs(root, ret);
        return ret;
    }

//中序非递归
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        if (root == nullptr) return ret;
        TreeNode* p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            ret.push_back(p->val);
            p = p->right;
        }

        return ret;
    }

//中序递归
    void indfs(TreeNode* r, vector<int>& a) {
        if (r->left) indfs(r->left, a);
        a.push_back(r->val);
        if (r->right) indfs(r->right, a);
    }

    vector<int> inorder(TreeNode* root) {
        vector<int> ret;
        indfs(root, ret);
        return ret;
    }

//后序非递归
    vector<int> postorderTraversal(TreeNode* root) {
        //需要左右交换的逆后续遍历
        vector<int> ret;
        stack<TreeNode*> stk;
        if (root == nullptr) return ret;
        stk.push(root);
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            ret.push_back(p->val);
            if (p->left) stk.push(p->left);
            if (p->right) stk.push(p->right);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

//后序递归
    void postdfs(TreeNode* r, vector<int>& a) {
        if (r->left) postdfs(r->left, a);
        if (r->right) postdfs(r->right, a);
        a.push_back(r->val);
    }

    vector<int> postorder(TreeNode* root) {
        vector<int> ret;
        postdfs(root, ret);
        return ret;
    }

//层次遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		queue<TreeNode*> que;
		que.push(root);
		int levelsize = 1;
		while (levelsize) {
			vector<int> tmp;
			for (int i = 0; i < levelsize; i++) {
				TreeNode* cur = que.front();
				tmp.push_back(cur->val);
				if (cur->left) {
					que.push(cur->left);
				}
				if (cur->right) {
					que.push(cur->right);
				}
				que.pop();
			}
			levelsize = que.size();
			ret.push_back(tmp);
		}
		return ret;
	}
};

/* 
 * tree example:
 * root = [3,9,20,null,null,15,7]
 * 
 *              3
 *             / \
 *            9   20
 *               /  \
 *              15   7
 */

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        cout << integerVectorToString(Solution().preorderTraversal(root)) << endl;
        cout << integerVectorToString(Solution().preorder(root)) << endl;
        cout << integerVectorToString(Solution().inorderTraversal(root)) << endl;
        cout << integerVectorToString(Solution().inorder(root)) << endl;
        cout << integerVectorToString(Solution().postorderTraversal(root)) << endl;
        cout << integerVectorToString(Solution().postorder(root)) << endl;
        cout << integerVector2ToString(Solution().levelOrder(root)) << endl;
        
    }
    return 0;
}