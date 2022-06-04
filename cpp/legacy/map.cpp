#include <iostream>
#include <map>
#include <vector>

using namespace std;

int maxLength(vector<int>& arr) {
	// write code here
	//��Ҫһ��map���浱ǰԪ��������λ��
	map<int, int> position;
	int left = -1, right = 0;
	int ret = 0;
	while (right < arr.size()) {
		if (position.find(arr[right]) == position.end()) {
			position[arr[right]] = right;
			right++;
			if (right - left > ret) ret = right - left;
		}
		else {
			int pos = position[arr[right]];
			while (++left <= pos) {
				position.erase(arr[left]);
			}
		}
	}
	return ret;
}
int main() {
	//
	//map<int, int> mp;
	//mp[1] = 2;
	//mp[2] = 3;
	//mp.erase(1);
	//for (const auto& item : mp) {
	//	cout << item.first << " " << item.second << endl;
	//}


	vector<int> temp = { 2, 2 };
	cout << maxLength(temp) << endl;

	// system("pause");
	return 0;
}
