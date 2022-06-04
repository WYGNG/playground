#include <iostream>

using namespace std;

void insert_relation(int a, int b) {

}

bool search_relation(int a, int b) {
	if (a == b) return true;



}


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			insert_relation(a, b);
		}
		else if (t == 2) {
			int a, b, c;
			cin >> a >> b >> c;
			if (search_relation(a % c, b % c)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}



	system("pause");

	return 0;
}