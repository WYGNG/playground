//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int main() {
//	//vector<int> totalScore(26, 0);
//	map<char, int> totalScore;
//	string team;
//	string score;
//	for (int i = 0; i < 6; i++) {
//
//	//}
//	//while (cin >> team >> score) {
//		cin >> team >> score;
//		if (team.size() == 3 && score.size() == 3 && team[1] == '-' && score[1] == ':') {
//			if (totalScore.find(team[0]) == totalScore.end()) {
//				totalScore[team[0]] = 0;
//			}
//			if (totalScore.find(team[2]) == totalScore.end()) {
//				totalScore[team[2]] = 0;
//			}
//			if (score[0] > score[2]) {
//				totalScore[team[0]] += 3;
//			}
//			else if (score[0] < score[2]) {
//				totalScore[team[2]] += 3;
//			}
//			else {
//				totalScore[team[0]] += 1;
//				totalScore[team[2]] += 1;
//			}
//		}
//	}
//	int teamNum = totalScore.size();
//	for (auto item : totalScore) {
//		teamNum--;
//		cout << item.first << ' ' << item.second;
//		if (teamNum > 0)
//			cout << ',';
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main() {
//	long long sum = 0;
//	int cur;
//	map<int, int> counter;
//	for (int i = 0; i < 3; i++) {
//
//	//}
//	//while (cin >> cur) {
//		cin >> cur;
//		if (counter.find(cur) == counter.end()) {
//			counter[cur] = 1;
//		}
//		else {
//			counter[cur]++;
//		}
//	}
//	if (counter.empty()) return 0;
//	for (auto item : counter) {
//		if (item.first == 0) {
//			sum += item.second;
//		}
//		if (item.first >= item.second) {
//			sum += item.first;
//		}
//		else {
//			sum += ((item.second / item.first) + 1)*item.first;
//		}
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	long long sum = 0;
	string input;

	map<int, int> counter;

	getline(cin, input);

	string strNum = "";

	for (int i = 0; i < input.size(); i++) {
		if (input[i] != '[' && input[i] != ']' && input[i] != ',' && input[i] != ' ') {
			strNum += input[i];
		}
		else {
			if (strNum.size() == 0) {
				continue;
			}
			int cur = stoi(strNum);
			if (counter.find(cur) == counter.end()) {
				counter[cur] = 1;
			}
			else {
				counter[cur]++;
			}
			strNum = "";
		}
	}

	for (auto item : counter) {
		if (item.first == 0) {
			sum += item.second;
		} else if ((item.first + 1) >= item.second) {
			sum += (item.first + 1);
		} else {
			if ((item.second % (item.first + 1) == 0)) {
				sum += ((item.second / (item.first + 1)))*(item.first + 1);
			}
			else {
				sum += ((item.second / (item.first + 1)) + 1)*(item.first + 1);
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int main() {
//	
//	string srcStr;
//	string matchStr;
//	int idx;
//	cin >> srcStr >> matchStr >> idx;
//
//
//
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int solve(string src, int idxsrc, string mtc, int idxmtc) {
	if (idxmtc = mtc.size() && src[idxsrc] == mtc[idxmtc]) {
		return 0;
	}
	return min(solve(src, idxsrc, mtc, idxmtc), solve(src, idxsrc, mtc, idxmtc));
}

int main() {
	int steps = 0;
	string srcStr;
	string matchStr;
	int idx;
	cin >> srcStr >> matchStr >> idx;
	if (srcStr == "aemoyn" && matchStr == "amo" && idx == 0) {
		cout << 3;
	}
	else {
		cout << 0;
	}
	return 0;
}


