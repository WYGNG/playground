#include <iostream>
#include <stack>

using namespace std;

int main() {
	long long n;
	int k;
	cin >> k >> n;
	//思想就是使用9进制表示n-1，然后每位编码0~k-1, k+1~9;
	n--;
	stack<int> stk;
	while (n) {
		stk.push(n % 9);
		n /= 9;
	}
	long long ret = 0;
	while (!stk.empty()) {
		ret *= 10;
		if (stk.top() >= k) {
			ret += stk.top() + 1;
		}
		else {
			ret += stk.top();
		}
		stk.pop();
	}
	cout << ret << endl;
	system("pause");
	return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	for (int t = 0; t < N; t++) {
//		int n, m;
//		cin >> n >> m;
//		vector<pair<int, int>> base;
//		for (int i = 0; i < n; i++) {
//			int b, a;
//			cin >> b >> a;
//			base.push_back({ b, a });
//		}
//
//		sort(base.begin(), base.end(), [](const pair<int, int>& b, const pair<int, int>& a) {return (float)(b.second - b.first) / (b.second*(b.second + 1)) > (float)(a.second - a.first) / (a.second*(a.second + 1)); });
//		for (int i = 0; i < m; i++) {
//			base[0].first++;
//			base[0].second++;
//			sort(base.begin(), base.end(), [](const pair<int, int>& b, const pair<int, int>& a) {return (float)(b.second - b.first) / (b.second*(b.second + 1)) > (float)(a.second - a.first) / (a.second*(a.second + 1)); });
//		}
//		float ret = 0;
//
//		for (int i = 0; i < n; i++) {
//			ret += (float)base[i].first / base[i].second;
//			//cout << base[i].first << " " << base[i].second << endl;
//		}
//		ret /= base.size();
//		printf("%.5f", ret);
//		//cout << ret << endl;
//	}
//	return 0;
//}