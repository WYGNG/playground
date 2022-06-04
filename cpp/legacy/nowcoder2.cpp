



class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 返回集合大小的最小值
	 * @param n long长整型
	 * @return int整型
	 */
	int getSize(long long n) {
		// write code here
		long long base = 1;
		int ret = 0;
		while (1) {
			base *= 2;
			ret++;
			if (base >= n) return ret;
		}
		return 0;
	}
};











#include <iostream>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if ((3 * a + b - c) % 3 != 0) {
		a++;
	}
	long long d = (3 * a + b - c) / 3;
	if (d < 0) cout << 0 << endl;
	else cout << d << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>> table(n, vector<char>(m));
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(26, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
			for (int c = 0; c < 26; c++) {
				dp[i + 1][j + 1][c] = dp[i][j + 1][c] + dp[i + 1][j][c] - dp[i][j][c];
			}
			dp[i + 1][j + 1][table[i][j] - 'a']++;
		}
	}


	bool finded = false;
	int small = n > m ? m : n;
	if (small*small < k) {
		cout << -1 << endl;
		return 0;
	}
	//寻找最小正方形
	int l = 1;
	for (l = 1; l <= small; l++) {
		if (l*l >= k) break;
	}

	for (; l <= small; l++) {
		for (int x = 0; x <= n - l; x++) {//左上角行号
			for (int y = 0; y <= m - l; y++) {
				int ret = 0;
				for (int i = 0; i < 26; i++) {
					if ((dp[x][y][i] - dp[x][y + l][i] - dp[x + l][y][i] + dp[x + l][y + l][i]) > 0) ret++;
				}
				if (ret >= k) {
					cout << l << endl;
					return 0;
				}
			}
		}
	}
	if (!finded) cout << -1 << endl;
	return 0;
}