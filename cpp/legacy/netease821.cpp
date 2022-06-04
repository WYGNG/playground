#include <iostream>
#include <vector>
#include <map>

using namespace std;

int run(vector<int> input) {
	int ret = input.size();
	map<int, int> mp;
	for (auto num : input) mp[num]++;

	return ret;
}


int main() {



















	return 0;
}



































//int main() {
//
//	vector<vector<int>> ipt = { {1,1,1,1,0},{0,1,0,1,0},{1,1,2,1,1},{0,2,0,0,1} };
//	cout << run(ipt) << endl;
//	system("pause");
//	return 0;
//}
//
//
//
//
//
//int run(vector<vector<int>> input) {
//	int r = input.size(), c = input[0].size();
//	vector<vector<int>> dp(r, vector<int>(c, -1));
//	dp[0][0] = 0;
//	for (int i = 1; i < c; i++) {
//		if (dp[0][i - 1] >= 0) {
//			if (input[0][i] == 1) dp[0][i] = dp[0][i - 1] + 1;
//			else if (input[0][i] == 0) dp[0][i] = dp[0][i - 1] + 2;
//		}
//	}
//	for (int j = 1; j < r; j++) {
//		if (dp[j - 1][0] >= 0) {
//			if (input[j][0] == 1) dp[j][0] = dp[j - 1][0] + 1;
//			else if (input[j][0] == 0) dp[j][0] = dp[j - 1][0] + 2;
//		}
//	}
//	cout << r << endl; cout << c << endl;
//	for (int i = 1; i < c; i++) {
//		for (int j = 1; j < r; j++) {
//
//			int curCost = INT_MAX;
//			if (dp[i - 1][j] >= 0 && dp[i - 1][j] < curCost) curCost = dp[i - 1][j];
//			if (dp[i][j - 1] >= 0 && dp[i][j - 1] < curCost) curCost = dp[i][j - 1];
//			if (curCost != INT_MAX) dp[i][j] = curCost + 1;
//
//		}
//	}
//	return dp[r - 1][c - 1];
//}
