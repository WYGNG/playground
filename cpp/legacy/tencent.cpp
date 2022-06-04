#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isEqual(string a, string b) {
	int sizea = a.size();
	int sizeb = b.size();
	if (sizea != sizeb) {
		return false;
	}
	if (sizea % 2 == 1) {
		return a == b;
	}
	else {
		string a1;
		string a2;
		string b1;
		string b2;
		for (int i = 0; i < sizea / 2; i++) {
			a1 += a[i];
			b1 += b[i];
		}
		for (int i = sizea/2; i < sizea; i++) {
			a2 += a[i];
			b2 += b[i];
		}
		return isEqual(a1,b1) && isEqual(a2, b2) || isEqual(a1, b2) && isEqual(a2, b1);
	}
}

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string a, b;
		cin >> a >> b;
		if (isEqual(a, b)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}



//bytedance

#include <iostream>
using namespace std;

int func(vector<vector<int>> timeTable) {
	int currentCount = 0;
	int maxCount = 0;

	vector<int> timeStamp(180, 0);
	for (auto item : timeTable) {
		timeStamp[item[0]]++;
		timeStamp[item[1]]--;
	}
	for (auto item : timeStamp) {
		currentCount += item;
		maxCount = max(maxCount, currentCount);
	}

	return maxCount;
}



int main() {
	//int a;
	//cin >> a;
	cout << "Hello World!" << endl;
}