#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param n string字符串
	 * @return int整型
	 */
	int NS_LIS(string n) {
		// write code here
		int ret = n[0] - '0';
		ret += (n.size() - 1) * 9;
		for (int i = 1; i < n.size(); i++) {
			if (n[i] != '9') {
				ret--;
				break;
			}
		}
		return ret;
	}
};

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param h int整型vector
	 * @return int整型vector
	 */
	vector<int> Magical_NN(vector<int>& h) {
		// write code here
		int n = h.size();
		vector<int> ret(n, 0);
		vector<int> sum(n, 0);
		vector<int> t = h;
		unordered_map<int, int> val;
		sort(t.begin(), t.end(), [](int a, int b) { return a > b; });
		int cursum = 0;
		for (int i = 0; i < n; i++) {
			cursum += t[i];
			sum[i] = cursum;
		}
		for (int i = 0; i < n; i++) {
			int s1 = sum[i] - (i + 1)*t[i];
			int s2 = (n - i - 1)*t[i] - (cursum - sum[i]);
			val[t[i]] = s1 + s2;
		}

		for (int i = 0; i < n; i++) {
			ret[i] = val[h[i]];
		}

		return ret;
	}
};

int main() {






	string test = "110328324";


	cout << NS_LIS(test) << endl;


	system("pause");

	return 0;
}


