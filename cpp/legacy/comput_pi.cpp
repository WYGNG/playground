#include <iostream>
#include <corecrt_math_defines.h>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

using namespace std;

double compute_pi(int N) //计算pi函数
{
	double dx = 1.0 / N;
	double pi = 0;
	for (int i = 1; i < N; ++i)
	{
		pi += 2 * sqrt(1 - i * dx*i*dx); // 积分函数
	}
	pi += 1;
	pi *= 2 * dx;
	return pi;
}

typedef struct Node {
	Node * left;
	Node * right;
	Node * parent;
	int val;
} Node;

int findDepth(Node* point) {
	if (point == nullptr) return 0;
	set<Node*> visited;
	int level = 0;
	int levelSize = 1;
	queue<Node*> que;
	visited.insert(point);
	que.push(point);
	while (levelSize) {
		for (int i = 0; i < level; i++) {
			Node* curNode = que.front();
			que.pop();
			if (curNode->parent != nullptr && visited.find(curNode->parent) == visited.end()) {
				visited.insert(curNode->parent);
				que.push(curNode->parent);
			}
			if (curNode->left != nullptr && visited.find(curNode->left) == visited.end()) {
				visited.insert(curNode->left);
				que.push(curNode->left);
			}
			if (curNode->right != nullptr && visited.find(curNode->right) == visited.end()) {
				visited.insert(curNode->right);
				que.push(curNode->right);
			}
		}
		level++;
		levelSize = que.size();
	}
	return level - 1;
}

int main()
{
	//std::cout << "Please input a number: ";
	//int N = 0;
	//std::cin >> N;
	//double pi = compute_pi(N);
	//std::cout.setf(std::ios::scientific);
	//std::cout << "The computing value of π is " << std::setprecision(10) << pi << '\n';
	//std::cout << "The computing error is " << std::setprecision(10) << abs(pi - M_PI) << '\n';

	//std::cout << "Please input a tolerance: ";
	//double dtol = 0;
	//std::cin >> dtol; // 输入误差精度，例如 0.000001
	//int M = (int)sqrt(dtol) / dtol; // 以 √dtol / dtol 作为初始的 N 的估计值，记为M
	//pi = compute_pi(M);
	//while (abs(pi - M_PI) > dtol)  // 若计算误差大于输入的容忍误差，则递增M
	//{
	//	M += (int)1 / sqrt(dtol); // 递增的步进为 1 / √dtol，此处可根据程序运行快慢进行调整
	//	pi = compute_pi(M); // 再次计算π值
	//}
	//std::cout << "The computing error is " << std::setprecision(10) << abs(pi - M_PI) << '\n';
	//std::cout << "The number of intervals is " << M << '\n';
	system("pause");
}