#include <iostream>
#include <corecrt_math_defines.h>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

using namespace std;

double compute_pi(int N) //����pi����
{
	double dx = 1.0 / N;
	double pi = 0;
	for (int i = 1; i < N; ++i)
	{
		pi += 2 * sqrt(1 - i * dx*i*dx); // ���ֺ���
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
	//std::cout << "The computing value of �� is " << std::setprecision(10) << pi << '\n';
	//std::cout << "The computing error is " << std::setprecision(10) << abs(pi - M_PI) << '\n';

	//std::cout << "Please input a tolerance: ";
	//double dtol = 0;
	//std::cin >> dtol; // �������ȣ����� 0.000001
	//int M = (int)sqrt(dtol) / dtol; // �� ��dtol / dtol ��Ϊ��ʼ�� N �Ĺ���ֵ����ΪM
	//pi = compute_pi(M);
	//while (abs(pi - M_PI) > dtol)  // ����������������������������M
	//{
	//	M += (int)1 / sqrt(dtol); // �����Ĳ���Ϊ 1 / ��dtol���˴��ɸ��ݳ������п������е���
	//	pi = compute_pi(M); // �ٴμ����ֵ
	//}
	//std::cout << "The computing error is " << std::setprecision(10) << abs(pi - M_PI) << '\n';
	//std::cout << "The number of intervals is " << M << '\n';
	system("pause");
}