#include <iostream>
#include <string>
#include <vector>

using namespace std;


//int main() {
//	string curPath;
//	string targetPath;
//	string deltaPath;
//	cin >> targetPath >> curPath;
//	vector<string> curVec, targetVec;
//	string temp;
//	for (auto & c : curPath) {
//		if (c == '/') {
//			curVec.push_back(temp);
//			temp.clear();
//		}
//		else {
//			temp += c;
//		}
//	} 
//	if (!temp.empty()) {
//		curVec.push_back(temp);
//		temp.clear();
//	}
//	for (auto & c : targetPath) {
//		if (c == '/') {
//			targetVec.push_back(temp);
//			temp.clear();
//		}
//		else {
//			temp += c;
//		}
//	}
//	if (!temp.empty()) {
//		targetVec.push_back(temp);
//		temp.clear();
//	}
//	int i = 0, j = 0, m = curVec.size(), n = targetVec.size();
//	while (i < m && j < n) {
//		if (curVec[i] == targetVec[j]) {
//			i++;
//			j++;
//		}
//		else {
//			break;
//		}
//	}
//	for (; i < m; i++) {
//		deltaPath += "../";
//	}
//
//	for (; j < n; j++) {
//		deltaPath += targetVec[j];
//		deltaPath += '/';
//	}
//	deltaPath.pop_back();
//	cout << deltaPath << endl;
//	system("pause");
//	return 0;
//}

int main() {
	string input;
	cin >> input;
	vector<string> partVec;
	string temp;
	for (auto & c : input) {
		if (c == '/' || c == '?') {
			if (!temp.empty()) {
				partVec.push_back(temp);
				temp.clear();
			}
		}
		else {
			temp += c;
		}
	} 
	if (!temp.empty()) {
		partVec.push_back(temp);
		temp.clear();
	}
	bool valid = true;
	if (partVec.size() >= 4) {
		if (partVec[0] != "https:") valid = false;


	
		if (partVec[2] != "j" && partVec[2] != "w" && partVec[2] != "s") valid = false;

		if (partVec[3].size() < 9 || partVec[3].size() > 11) valid = false;

		if (valid) {
			cout << stoll(partVec[3], 0, 10) << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}



	system("pause");
	return 0;
}