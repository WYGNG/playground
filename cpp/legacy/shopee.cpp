#include <iostream>
#include <vector>
#include <string>

using namespace std;


char upper(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 32;
	}
	return c;
}

char lower(char& c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	return c;
}

int main() {
	string inputString;
	getline(cin, inputString);
	string outputString;
	bool upFlag = false;
	bool firstFlag = true;
	for (auto& c : inputString) {
		if (firstFlag) {
			outputString += lower(c);
			firstFlag = false;
		}
		else {
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
				if (upFlag) {
					outputString += upper(c);
					upFlag = false;
				}
				else {
					outputString += c;
				}
			}
			else {
				if (c >= '0' && c <= '9') {
					outputString += c;
				}
				upFlag = true;
			}
		}
	}
	cout << outputString << endl;
	system("pause");
	return 0;
}




//
//
//bool isMatch(string s, string p) {
//	int m = s.size();
//	int n = p.size();
//
//	auto matches = [&](int i, int j) {
//		if (i == 0) {
//			return false;
//		}
//		if (p[j - 1] == '?') {
//			return true;
//		}
//		return s[i - 1] == p[j - 1];
//	};
//
//	vector<vector<int>> f(m + 1, vector<int>(n + 1));
//	f[0][0] = true;
//	for (int i = 0; i <= m; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (p[j - 1] == '*') {
//				f[i][j] |= f[i][j - 2];
//				if (matches(i, j - 1)) {
//					f[i][j] |= f[i - 1][j];
//				}
//			}
//			else {
//				if (matches(i, j)) {
//					f[i][j] |= f[i - 1][j - 1];
//				}
//			}
//		}
//	}
//	return f[m][n];
//}
//
//
//int main() {
//	string s, p;
//	cin >> p >> s;
//	cout << isMatch(s, p) << endl;
//	system("pause");
//	return 0;
//}