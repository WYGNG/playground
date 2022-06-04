#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>


using namespace std;

void print_vector(vector<int> arr) {
	for (auto item : arr) {
		cout << item << endl;
	}
}

class SolutionDemo {
public:


private:

};

//类的声明 默认私有数据成员 共有成员函数
class Solution213 {
public:
	int search(const vector<int>& nums, int target);

private:

};

//类成员函数的实现
int Solution213::search(const vector<int>& nums, int target) {
	
}

int main() {
	vector<int> vec_213 = { 4, 5, 6, 7, 8, 9, 0, 1, 2, 3 };

	Solution213 solve;
	solve.search(vec_213, 8);


	return 0;
}