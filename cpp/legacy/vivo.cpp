// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;


int main() {
	int C = 0;
	cin >> C;
	vector<int> W, V;
	string wString, vString, tp;
	getline(cin, tp);
	getline(cin, wString);
	getline(cin, vString);
	string temp;
	for (const auto& c : wString) {
		if (c >= '0' && c <= '9') {
			temp += c;
		}
		else {
			W.push_back(stoi(temp));
			temp = "";
		}
	}
	if (!temp.empty()) {
		W.push_back(stoi(temp));
		temp = "";
	}

	for (const auto& c : vString) {
		if (c >= '0' && c <= '9') {
			temp += c;
		}
		else {
			V.push_back(stoi(temp));
			temp = "";
		}
	}
	if (!temp.empty()) {
		V.push_back(stoi(temp));
		temp = "";
	}

	int size = W.size();
	int ret = 0;

	vector<vector<int>> dp(C + 1, vector<int>(size, 0));
	dp[W[0]][0] = V[0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= C; j++) {
			if (j >= W[i]) {
				dp[j][i] = max(dp[j][i - 1], dp[j - W[i]][i - 1] + V[i]);
			}
			else {
				dp[j][i] = dp[j][i - 1];
			}
		}
	}





	cout << dp[C][size - 1] << endl;

	system("pause");
	return 0;
}